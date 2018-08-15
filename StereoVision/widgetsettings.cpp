#include "widgetsettings.h"
#include "ui_widgetsettings.h"

widgetSettings::widgetSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetSettings),
    leftCamera(0),
    rightCamera(1)
{
    ui->setupUi(this);
    ui->leftCamera->setScaledContents(true);
    ui->rightCamera->setScaledContents(true);
    ui->leftCameraId->setValue(leftCamera);
    ui->rightCameraId->setValue(rightCamera);

    startup();
}

widgetSettings::~widgetSettings()
{
    threadStereoCamera->quit();
    threadTimer->quit();
    while(!threadStereoCamera->isFinished());
    while(!threadTimer->isFinished());

    delete threadStereoCamera;
    delete threadTimer;

    delete ui;
}

void widgetSettings::startup()
{
    qRegisterMetaType<cv::Mat>("cv::Mat");

    int timerInterval = 42;
    threadStereoCamera = new QThread();
    threadTimer = new QThread();

    stereoCamera * camera = new stereoCamera();
    timerRegulator * intervalRegulator = new timerRegulator();
    QTimer * timer = new QTimer();
    timer->setInterval(timerInterval);
    intervalRegulator->setInterval(timerInterval);

    connect(this, SIGNAL(sendStereoCameraSetup(const int, const int)), camera, SLOT(receiveSetup(const int, const int)));
    connect(timer, SIGNAL(timeout()), camera, SLOT(receiveGrabFrame()));
    connect(timer, SIGNAL(timeout()), intervalRegulator, SLOT(receiveTimeout()));

    connect(intervalRegulator, SIGNAL(sendInterval(int)), timer, SLOT(start(int)));
    connect(intervalRegulator, SIGNAL(sendInterval(int)), this, SLOT(receiveTimerInterval(int)));

    connect(camera, SIGNAL(sendCameraStatus(bool, bool)), this, SLOT(receiveCameraStatus(bool, bool)));
    connect(camera, SIGNAL(sendFrames(cv::Mat, cv::Mat)), this, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(camera, SIGNAL(sendJobDone()), intervalRegulator, SLOT(receiveJobDone()));

    connect(threadStereoCamera, SIGNAL(finished()), camera, SLOT(deleteLater()));
    connect(threadTimer, SIGNAL(finished()), timer, SLOT(deleteLater()));
    connect(threadTimer, SIGNAL(finished()), intervalRegulator, SLOT(deleteLater()));
    connect(threadTimer, SIGNAL(started()), timer, SLOT(start()));

    camera->moveToThread(threadStereoCamera);

    timer->moveToThread(threadTimer);
    intervalRegulator->moveToThread(threadTimer);

    threadStereoCamera->start();
    threadTimer->start();

    emit sendStereoCameraSetup(ui->leftCameraId->value(), ui->rightCameraId->value());
    threadTimer->start();
}

void widgetSettings::displayFrame(cv::Mat frame, QLabel * display)
{
    cv::Mat frameProcessed;
    cv::cvtColor(frame, frameProcessed, cv::COLOR_BGR2GRAY);
    QImage output((const unsigned char *)frameProcessed.data, frameProcessed.cols, frameProcessed.rows, QImage::Format_Indexed8);
    display->setPixmap(QPixmap::fromImage(output));
}

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

void widgetSettings::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    displayFrame(leftFrame, ui->leftCamera);
    displayFrame(rightFrame, ui->rightCamera);
}

void widgetSettings::receiveCameraStatus(bool leftCameraStatus, bool rightCameraStatus)
{
    displayCameraStatus(leftCameraStatus, ui->labelLeftCameraStatus);
    displayCameraStatus(rightCameraStatus, ui->labelRightCameraStatus);
}

void widgetSettings::receiveTimerInterval(int interval)
{
    ui->spinBoxinterval->setValue(interval);
}

void widgetSettings::on_leftCameraId_valueChanged(int leftCameraId)
{
    leftCamera = leftCameraId;
    emit sendStereoCameraSetup(leftCamera, rightCamera);
}


void widgetSettings::on_rightCameraId_valueChanged(int rightCameraId)
{
    rightCamera = rightCameraId;
    emit sendStereoCameraSetup(leftCamera, rightCamera);
}
