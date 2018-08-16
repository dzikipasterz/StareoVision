#include "appwidget.h"


AppWidget::AppWidget(QWidget *parent):
    QWidget(parent),
    threadStereoCamera(nullptr),
    threadTimer(nullptr)
{
}


AppWidget::~AppWidget()
{
    if (threadTimer != nullptr)
    {
        threadStereoCamera->quit();
        while(!AppWidget::threadStereoCamera->isFinished());
    }

    if (threadTimer != nullptr)
    {
        threadTimer->quit();
        while(!AppWidget::threadTimer->isFinished());
    }

    delete threadStereoCamera;
    delete threadTimer;
}


void AppWidget::startup()
{
    qRegisterMetaType<cv::Mat>("cv::Mat");
}

void AppWidget::initTimer(const int timerInterval)
{
    threadTimer = new QThread();
    intervalRegulator = new timerRegulator();
    timer = new QTimer();

    timer->setInterval(timerInterval);
    intervalRegulator->setInterval(timerInterval);

    connect(intervalRegulator, SIGNAL(sendInterval(int)), timer, SLOT(start(int)));
    connect(timer, SIGNAL(timeout()), intervalRegulator, SLOT(receiveTimeout()));
    connect(threadTimer, SIGNAL(finished()), timer, SLOT(deleteLater()));
    connect(threadTimer, SIGNAL(finished()), intervalRegulator, SLOT(deleteLater()));
    connect(threadTimer, SIGNAL(started()), timer, SLOT(start()));
}

void AppWidget::startTimer()
{
    timer->moveToThread(threadTimer);
    intervalRegulator->moveToThread(threadTimer);
    threadTimer->start();
}

void AppWidget::initCamera(const int leftCameraId, const int rightCameraId)
{
    threadStereoCamera = new QThread();
    camera = new stereoCamera();
    camera->receiveSetup(leftCameraId, rightCameraId);
    connect(timer, SIGNAL(timeout()), camera, SLOT(receiveGrabFrame()));
    connect(threadStereoCamera, SIGNAL(finished()), camera, SLOT(deleteLater()));
}

void AppWidget::startCamera()
{
    camera->moveToThread(threadStereoCamera);
    threadStereoCamera->start();
}

void AppWidget::displayFrame(cv::Mat frame, QLabel * display)
{
    cv::Mat frameProcessed;
    cv::cvtColor(frame, frameProcessed, cv::COLOR_BGR2GRAY);
    QImage output((const unsigned char *)frameProcessed.data, frameProcessed.cols, frameProcessed.rows, QImage::Format_Indexed8);
    display->setPixmap(QPixmap::fromImage(output));
}
