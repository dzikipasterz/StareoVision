#include "widgetsettings.h"
#include "ui_widgetsettings.h"

widgetSettings::widgetSettings(AppSettings *sett) :
    ui(new Ui::widgetSettings)
{
    //store reference to application settings
    settings = sett;

    //setup UI
    ui->setupUi(this);
    ui->leftCamera->setScaledContents(true);
    ui->rightCamera->setScaledContents(true);
    ui->leftCameraId->setValue(settings->readLeftCameraId());
    ui->rightCameraId->setValue(settings->readRightCameraId());
    ui->labelSavePictDir->setText(settings->readPictSavePath());
    ui->labelSaveMovDir->setText(settings->readMovFilesDir());
    ui->labelCalibFilesDir->setText(settings->readCalibFilesDir());
    ui->labelCalibFile->setText(settings->readCalibFilePath());

    //fill comboBox with algorithms names
    QStringList algorithms;
    algorithms.append("Block Matching (CPU)");
    algorithms.append("Block Matching (GPU)");
    algorithms.append("Semi-Global Block Matching (CPU)");
    algorithms.append("Belief Propagation (GPU)");
    algorithms.append("Constant Space Belief Propagation (GPU)");
    ui->comboBoxAlgorithm->addItems(algorithms);
    ui->comboBoxAlgorithm->setCurrentIndex(int(settings->readAlgorithm()));

    //init basic elements of AppWidget
    AppWidget::initTimer();
    AppWidget::initCamera(settings->readLeftCameraId(), settings->readRightCameraId());

    //connect this <-------> camera, camera -----> intervalRegulator
    connect(this,SIGNAL(sendStereoCameraSetup(const int, const int)),AppWidget::camera,SLOT(receiveSetup(const int, const int)));
    connect(AppWidget::camera,SIGNAL(sendCameraStatus(bool, bool)),this,SLOT(receiveCameraStatus(bool, bool)));
    connect(AppWidget::camera,SIGNAL(sendFrames(cv::Mat, cv::Mat)),this,SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendJobDone()), AppWidget::intervalRegulator, SLOT(receiveJobDone()));

    //start camera and timer
    AppWidget::startCamera();
    AppWidget::startTimer();
}

widgetSettings::~widgetSettings()
{
    delete ui;
}

//display information with camera status - if connection is properly established or not. True - there is an error, false - no error
void widgetSettings::displayCameraStatus(bool status, QLabel * labelStatus)
{
    if(!status)
    {
        labelStatus->setText("Kamera włączona");
    }
    else
    {
        labelStatus->setText("Brak połączenia z kamerą.");
    }
}

//receive frames and display them to ensure a user about corectness of a connection (if left camera is really left one, right is right)
void widgetSettings::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    displayFrame(leftFrame, ui->leftCamera);
    displayFrame(rightFrame, ui->rightCamera);
    leftFrame.release();
    rightFrame.release();
}

//receive status of both cameras consisting a stereocamera.
void widgetSettings::receiveCameraStatus(bool leftCameraStatus, bool rightCameraStatus)
{
    displayCameraStatus(leftCameraStatus, ui->labelLeftCameraStatus);
    displayCameraStatus(rightCameraStatus, ui->labelRightCameraStatus);
}

//change left camera
void widgetSettings::on_leftCameraId_valueChanged(int id)
{
    settings->setLeftCameraId(id);
    emit sendStereoCameraSetup(settings->readLeftCameraId(), settings->readRightCameraId());
}

//change right camera
void widgetSettings::on_rightCameraId_valueChanged(int id)
{
    settings->setRightCameraId(id);
    emit sendStereoCameraSetup(settings->readLeftCameraId(),settings->readRightCameraId());
}

//change default directory for pictures saving
void widgetSettings::on_pushButtonSelectPicDir_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"Wybierz folder dla zdjęć",settings->readPictSavePath(),QFileDialog::ShowDirsOnly);

    if(!dir.isNull())
    {
        dir.append("/");
        settings->setPictsSavePath(dir);
        ui->labelSavePictDir->setText(dir);
    }
}

//change currently used calibration file
void widgetSettings::on_pushButtonSelectCalibFile_clicked()
{
    QString calibFile = QFileDialog::getOpenFileName(this,"Wybierz plik kalibracyjny",settings->readCalibFilePath(),tr("Plik kalibracyjny (*.xml)"));

    if(!calibFile.isNull())
    {
        settings->setCalibFilePath(calibFile);
        ui->labelCalibFile->setText(calibFile);
    }
}

//change default directory for saving video files
void widgetSettings::on_pushButtonSelectMovDir_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"Wybierz folder dla nagrywanych filmów",settings->readMovFilesDir(),QFileDialog::ShowDirsOnly);

    if(!dir.isNull())
    {
        dir.append("/");
        settings->setMovFilesDir(dir);
        ui->labelSaveMovDir->setText(dir);
    }
}

//change degault directory for saving calibration files
void widgetSettings::on_pushButtonSelectCalibDir_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"Wybierz folder dla plików kalibracyjnych",settings->readCalibFilesDir(),QFileDialog::ShowDirsOnly);

    if(!dir.isNull())
    {
        dir.append("/");
        settings->setCalibFilesDir(dir);
        ui->labelCalibFilesDir->setText(dir);
    }
}

//change algorithm of stereo pixel matching
void widgetSettings::on_comboBoxAlgorithm_activated(int index)
{
    settings->setAlgorithm(Algorithm(index));
}
