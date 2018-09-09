#include "widgetcalibration.h"
#include "ui_widgetcalibration.h"

widgetCalibration::widgetCalibration(AppSettings *sett) :
    ui(new Ui::widgetCalibration),
    threadCornersFinder(nullptr),
    threadCalibrator(nullptr),
    calibrator(nullptr),
    cameraInitialized(false)
{
    //AppWidget
    settings = sett;

    //widgetCalibration
    ui->setupUi(this);
    ui->leftCamera->setScaledContents(true);
    ui->rightCamera->setScaledContents(true);
    ui->spinBoxCollectedSets->setValue(0);
    ui->labelLastPictStatus->setText("");
    ui->spinBoxRows->setValue(settings->readChessboardRows());
    ui->spinBoxCols->setValue(settings->readChessboardCols());
    ui->doubleSpinBoxSquareSize->setValue(settings->readChessboardSquareSize());

    openCamera();
}

widgetCalibration::~widgetCalibration()
{
    if(cameraInitialized)
    {
        threadCalibrator->quit();
        threadCornersFinder->quit();
        while(!threadCalibrator->isFinished());
        while(!threadCornersFinder->isFinished());

        delete threadCalibrator;
        delete threadCornersFinder;
    }
    delete ui;
}


void widgetCalibration::openCamera()
{
    AppWidget::initTimer();
    AppWidget::initCamera(settings->readLeftCameraId(), settings->readRightCameraId());

    threadCornersFinder = new QThread;
    threadCalibrator = new QThread;
    cornersFinder = new CornersFinder();

    cornersFinder->setPatternSize(settings->readPatternSize());

    calibrator = new Calibrator();
    calibrator->setPatternSize(settings->readPatternSize());
    calibrator->setSquareSideSize(float(settings->readChessboardSquareSize()));
    calibrator->setSaveCalibrationDir(settings->readCalibFilesDir());

    connect(AppWidget::camera, SIGNAL(sendFrames(cv::Mat, cv::Mat)), cornersFinder, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendFrames(cv::Mat, cv::Mat)), calibrator, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(cornersFinder, SIGNAL(sendProcessedFrames(cv::Mat, cv::Mat)), this, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(cornersFinder, SIGNAL(sendJobDone()), AppWidget::intervalRegulator, SLOT(receiveJobDone()));

    connect(threadCalibrator, SIGNAL(finished()), calibrator, SLOT(deleteLater()));
    connect(threadCornersFinder, SIGNAL(finished()), cornersFinder, SLOT(deleteLater()));
    connect(this, SIGNAL(sendTakePicture()), calibrator, SLOT(receiveTakePicture()), Qt::DirectConnection);
    connect(this, SIGNAL(sendLoadPicture()), calibrator, SLOT(receiveTakePicture()));
    connect(this, SIGNAL(sendStartCalibration()), calibrator, SLOT(receiveStartCalibration()));
    connect(this, SIGNAL(sendLoadedFrames(cv::Mat, cv::Mat)), calibrator, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(calibrator, SIGNAL(sendCollectionStatus(int, bool)), this, SLOT(receiveCalibratorStatus(int, bool)));
    connect(calibrator, SIGNAL(sendCreatedFilePath(QString)), this, SLOT(receiveCalibrationFilePath(QString)));
    connect(calibrator, SIGNAL(sendCalibrationStatus(QString)), this, SLOT(receiveCalibrationStatus(QString)));

    calibrator->moveToThread(threadCalibrator);
    cornersFinder->moveToThread(threadCornersFinder);
    threadCornersFinder->start();
    threadCalibrator->start();

    AppWidget::startCamera();
    AppWidget::startTimer();
}

void widgetCalibration::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    AppWidget::displayFrame(leftFrame, ui->leftCamera);
    AppWidget::displayFrame(rightFrame, ui->rightCamera);
    leftFrame.release();
    rightFrame.release();
}

void widgetCalibration::receiveCalibratorStatus(int setsNumber, bool lastSetStatus)
{
    QString status;
    if (lastSetStatus) status = "Zdjęcie nie zostało dodane do zestawu kalibracyjnego";
    else status = "Zdjęcie zostało pomyślnie dodane";
    ui->spinBoxCollectedSets->setValue(setsNumber);
    ui->labelLastPictStatus->setText(status);
}

void widgetCalibration::receiveCalibrationStatus(QString status)
{
    ui->labelCalibrationStatus->setText(status);
}

void widgetCalibration::receiveCalibrationFilePath(QString path)
{
    settings->setCalibFilePath(path);
}


void widgetCalibration::on_pushButtonTakePicture_clicked()
{
    emit sendTakePicture();
}

void widgetCalibration::on_pushButtonCalibrate_clicked()
{
    emit sendStartCalibration();
}

void widgetCalibration::on_spinBoxRows_valueChanged(int arg1)
{
    settings->setChessboardRows(arg1);
}



void widgetCalibration::on_spinBoxCols_valueChanged(int arg1)
{
    settings->setChessboardCols(arg1);
}



void widgetCalibration::on_doubleSpinBoxSquareSize_valueChanged(double arg1)
{
    settings->setChessboardSquareSize(arg1);
}

void widgetCalibration::on_pushButtonChooseDirToLoad_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"Wybierz folder ze zdjęciami kalibracyjnymi","/home/",QFileDialog::ShowDirsOnly);

    if(!dir.isNull())
    {
        dir.append("/");
        settings->setCalibFilesDir(dir);
        ui->labelPicsDir->setText(dir);
    }
}

void widgetCalibration::on_pushButtonLoad_clicked()
{
    QDir directory(ui->labelPicsDir->text());
    directory.setNameFilters(QStringList("*.jpg"));
    directory.setSorting(QDir::Name);
    QStringList files = directory.entryList();
    cv::Mat leftFrame, rightFrame;

    for(int i = 0; i < files.size(); i+=2)
    {
        leftFrame = cv::imread(ui->labelPicsDir->text().append(files.at(i)).toUtf8().constData());
        rightFrame = cv::imread(ui->labelPicsDir->text().append(files.at(i+1)).toUtf8().constData());
        emit sendLoadPicture();
        emit sendLoadedFrames(leftFrame, rightFrame);
    }
}

