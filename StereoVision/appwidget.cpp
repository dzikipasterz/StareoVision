#include "appwidget.h"


AppWidget::AppWidget(QWidget *parent):
    QWidget(parent),
    threadStereoCamera(nullptr),
    threadTimer(nullptr)
{
    qRegisterMetaType<cv::Mat>("cv::Mat");
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
    threadStereoCamera = nullptr;
    delete threadTimer;
    threadTimer = nullptr;
}


void AppWidget::initTimer(const int timerInterval)
{
    threadTimer = new QThread();
    intervalRegulator = new timerRegulator();

    intervalRegulator->setInterval(timerInterval);

    connect(this, SIGNAL(sendPauseTimer()), intervalRegulator, SLOT(receivePause()));
    connect(this, SIGNAL(sendResumeTimer()), intervalRegulator, SLOT(receiveResume()));
    connect(threadTimer, SIGNAL(finished()), intervalRegulator, SLOT(deleteLater()));
    connect(threadTimer, SIGNAL(started()), intervalRegulator, SLOT(receiveStart()));
}

void AppWidget::startTimer()
{
    intervalRegulator->moveToThread(threadTimer);
    threadTimer->start();
}

void AppWidget::pauseTimer()
{
    emit sendPauseTimer();
}

void AppWidget::resumeTimer()
{
    emit sendResumeTimer();
}

void AppWidget::initCamera(const int leftCameraId, const int rightCameraId)
{
    threadStereoCamera = new QThread();
    camera = new stereoCamera();
    camera->receiveSetup(leftCameraId, rightCameraId);
    connect(intervalRegulator, SIGNAL(sendTimeout()), camera, SLOT(receiveGrabFrame()));
    connect(threadStereoCamera, SIGNAL(finished()), camera, SLOT(deleteLater()));
}

void AppWidget::startCamera()
{
    camera->moveToThread(threadStereoCamera);
    threadStereoCamera->start();
}

void AppWidget::displayFrame(cv::Mat frame, QLabel * display)
{
    int channels = frame.channels();
    if(channels == 3)
    {
        QImage output(frame.data, frame.cols, frame.rows, static_cast<int>(frame.step), QImage::Format_RGB888);
        display->setPixmap(QPixmap::fromImage(output.rgbSwapped()));
    }
    if(channels == 1)
    {
        QImage output(frame.data, frame.cols, frame.rows, static_cast<int>(frame.step), QImage::Format_Grayscale8);
        display->setPixmap(QPixmap::fromImage(output));
    }
}

void AppWidget::displayDisparity(cv::Mat frame, DepthDisplay * display)
{
    cv::Mat frameEq;
    cv::equalizeHist(frame, frameEq);
    QImage outputRaw(frame.data, frame.cols, frame.rows, static_cast<int>(frame.step), QImage::Format_Grayscale8);
    QImage outputEq(frameEq.data, frameEq.cols, frameEq.rows, static_cast<int>(frameEq.step), QImage::Format_Grayscale8);
    display->setImage(outputRaw, outputEq);
}
