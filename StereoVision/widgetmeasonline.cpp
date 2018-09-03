#include "widgetmeasonline.h"
#include "ui_widgetmeasonline.h"

widgetMeasOnline::widgetMeasOnline(AppSettings *sett) :
    ui(new Ui::widgetMeasOnline),
    threadRectifier(nullptr),
    threadStereoMatcher(nullptr)
{
    ui->setupUi(this);
    settings = sett;

    disparityDisplay = new DepthDisplay();
    disparityDisplay->setScaledContents(true);
    disparityDisplay->setDispToDistMat(settings->readDispToDepthMap());

    connect(disparityDisplay, SIGNAL(sendDistance(double)), this, SLOT(receiveDistance(double)));

    ui->gridLayout->addWidget(disparityDisplay,0,0);

    AppWidget::initTimer();
    AppWidget::initCamera(settings->readLeftCameraId(), settings->readRightCameraId());

    threadRectifier = new QThread();
    threadStereoMatcher = new QThread();

    rectifier = new Rectifier();
    rectifier->setCalibrationFile(settings->readCalibFilePath());
    stereoMatcher = new StereoBM(); //#todo: zaleznie od wybranego algorytmu

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
    delete ui;
    ui->gridLayout->removeWidget(disparityDisplay);
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

void widgetMeasOnline::receiveDisparity(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat disparity)
{
    leftFrameRaw.release();
    rightFrameRaw.release();
    displayDisparity(disparity, disparityDisplay);
}

void widgetMeasOnline::receiveDistance(double distance)
{
    ui->doubleSpinBoxDistance->setValue(distance);
}
