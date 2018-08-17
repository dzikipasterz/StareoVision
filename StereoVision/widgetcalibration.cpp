#include "widgetcalibration.h"
#include "ui_widgetcalibration.h"

widgetCalibration::widgetCalibration(AppSettings sett) :
    ui(new Ui::widgetCalibration)
{
    //AppWidget
    settings = sett;

    //widgetCalibration
    ui->setupUi(this);
    ui->leftCamera->setScaledContents(true);
    ui->rightCamera->setScaledContents(true);

    widgetCalibration::startup();
}

widgetCalibration::~widgetCalibration()
{
    delete ui;
}


void widgetCalibration::startup()
{
    AppWidget::startup();
    AppWidget::initTimer();
    AppWidget::initCamera(settings.readLeftCameraId(), settings.readRightCameraId());

    threadCornersFinder = new QThread;
    cornersFinder = new CornersFinder();

    connect(AppWidget::camera, SIGNAL(sendFrames(cv::Mat, cv::Mat)), cornersFinder, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(cornersFinder, SIGNAL(sendProcessedFrames(cv::Mat, cv::Mat)), this, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(cornersFinder, SIGNAL(sendJobDone()), AppWidget::intervalRegulator, SLOT(receiveJobDone()));

    cornersFinder->moveToThread(threadCornersFinder);
    threadCornersFinder->start();

    AppWidget::startCamera();
    AppWidget::startTimer();
}

void widgetCalibration::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    AppWidget::displayFrame(leftFrame, ui->leftCamera);
    AppWidget::displayFrame(rightFrame, ui->rightCamera);
}
