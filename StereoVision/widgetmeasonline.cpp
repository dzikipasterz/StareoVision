#include "widgetmeasonline.h"
#include "ui_widgetmeasonline.h"

widgetMeasOnline::widgetMeasOnline(AppSettings *sett) :
    ui(new Ui::widgetMeasOnline),
    threadRectifier(nullptr),
    threadStereoMatcher(nullptr)
{
    ui->setupUi(this);
    settings = sett;

    ui->labelLeftDisplay->setScaledContents(true);
    ui->labelRightDisplay->setScaledContents(true);
    disparityDisplay = new DepthDisplay();
    disparityDisplay->setScaledContents(true);
    disparityDisplay->setDispToDistMat(settings->readDispToDepthMap());

    connect(disparityDisplay, SIGNAL(sendDistance(double)), this, SLOT(receiveDistance(double)));
    connect(disparityDisplay, SIGNAL(sendCoords(int, int)), this, SLOT(receiveCoords(int, int)));
    connect(this, SIGNAL(sendCoords(int, int)), disparityDisplay, SLOT(receiveCoords(int, int)));

    ui->gridLayoutMain->addWidget(disparityDisplay,0,0);

    AppWidget::initTimer();
    AppWidget::initCamera(settings->readLeftCameraId(), settings->readRightCameraId());

    threadRectifier = new QThread();
    threadStereoMatcher = new QThread();

    rectifier = new Rectifier();
    rectifier->setCalibrationFile(settings->readCalibFilePath());
    stereoMatcher = new StereoSGBMcpu(); //#todo: zaleznie od wybranego algorytmu

    connect(AppWidget::camera,SIGNAL(sendFrames(cv::Mat, cv::Mat)),rectifier,SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(rectifier, SIGNAL(sendFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat)), stereoMatcher, SLOT(receiveFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat)));
    connect(stereoMatcher, SIGNAL(sendDisparity(cv::Mat, cv::Mat, cv::Mat)), this, SLOT(receiveDisparity(cv::Mat, cv::Mat, cv::Mat)));
    connect(stereoMatcher, SIGNAL(sendJobDone()), AppWidget::intervalRegulator, SLOT(receiveJobDone()));

    connect(threadRectifier, SIGNAL(finished()), rectifier, SLOT(deleteLater()));
    connect(threadStereoMatcher, SIGNAL(finished()), stereoMatcher, SLOT(deleteLater()));

    rectifier->moveToThread(threadRectifier);
    stereoMatcher->moveToThread(threadStereoMatcher);
    threadRectifier->start();
    threadStereoMatcher->start();
    AppWidget::startCamera();
    AppWidget::startTimer();
}

widgetMeasOnline::~widgetMeasOnline()
{
    ui->gridLayoutMain->removeWidget(disparityDisplay);
    delete ui;
    delete disparityDisplay;

    if(threadRectifier != nullptr)
    {
        threadRectifier->quit();
        while(!threadRectifier->isFinished());
        threadRectifier = nullptr;
    }

    if(threadStereoMatcher != nullptr)
    {
        threadStereoMatcher->quit();
        while(!threadStereoMatcher->isFinished());
        threadStereoMatcher = nullptr;
    }
}

void widgetMeasOnline::openFile()
{
    closeFile();
    writeToFile = true;

    QDateTime currentTime = QDateTime::currentDateTime();
    QString filename = settings->readResultsDir().append(currentTime.toString("yyyyMMdd_hhmmss").append("_distance.csv"));
    results.setFileName(filename);
    results.open(QFile::WriteOnly | QIODevice::Append);
    if(results.isOpen())
    {
        output.setDevice(&results);
        ui->labelResultsPath->setText(filename);
    }
}

void widgetMeasOnline::closeFile()
{
    if(results.isOpen())
    {
        results.close();
        output.flush();
        writeToFile = false;
    }
}

void widgetMeasOnline::receiveDisparity(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat disparity)
{
    displayFrame(leftFrameRaw, ui->labelLeftDisplay);
    displayFrame(rightFrameRaw, ui->labelRightDisplay);
    displayDisparity(disparity, disparityDisplay);
}

void widgetMeasOnline::receiveDistance(double distance)
{
    ui->doubleSpinBoxDistance->setValue(distance);
    if(writeToFile)
    {
        output << QString::number(distance).append(";") << endl;
    }
}

void widgetMeasOnline::receiveCoords(int x, int y)
{
    ui->spinBoxX->setValue(x);
    ui->spinBoxY->setValue(y);
}

void widgetMeasOnline::on_spinBoxX_valueChanged(int arg1)
{
   emit sendCoords(arg1, ui->spinBoxY->value());
}

void widgetMeasOnline::on_spinBoxY_valueChanged(int arg1)
{
   emit sendCoords(ui->spinBoxX->value(), arg1);
}

void widgetMeasOnline::on_pushButtonWrite_toggled(bool write)
{
    if(write)
    {
        openFile();
    }
    else closeFile();
}
