#include "widgetsettings.h"
#include "ui_widgetsettings.h"

widgetSettings::widgetSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetSettings)
{
    ui->setupUi(this);
    ui->leftCamera->setScaledContents(true);
    ui->rightCamera->setScaledContents(true);
    ui->leftCameraId->setValue(1);
    ui->rightCameraId->setValue(2);

    startup();

}

widgetSettings::~widgetSettings()
{

    threadLeftCameraFrameGrabber->quit();
    threadRightCameraFrameGrabber->quit();
    threadGrabberTimer->quit();
    while(!threadLeftCameraFrameGrabber->isFinished());
    while(!threadRightCameraFrameGrabber->isFinished());
    while(!threadGrabberTimer->isFinished());

    delete threadLeftCameraFrameGrabber;
    delete threadRightCameraFrameGrabber;
    delete threadGrabberTimer;

    delete ui;
}

void widgetSettings::startup()
{
    qRegisterMetaType<cv::Mat>("cv::Mat");

    threadLeftCameraFrameGrabber = new QThread();
    threadRightCameraFrameGrabber = new QThread();
    threadGrabberTimer = new QThread();

    frameGrabber * leftGrabber = new frameGrabber();
    frameGrabber * rightGrabber = new frameGrabber();

    QTimer * timer = new QTimer();
    timer->setInterval(42);

    connect(this, SIGNAL(sendLeftCameraSetup(const int)), leftGrabber, SLOT(receiveSetup(const int)));
    connect(this, SIGNAL(sendRightCameraSetup(const int)), rightGrabber, SLOT(receiveSetup(const int)));
    connect(timer, SIGNAL(timeout()), leftGrabber, SLOT(receiveGrabFrame()));
    connect(timer, SIGNAL(timeout()), rightGrabber, SLOT(receiveGrabFrame()));
    connect(leftGrabber, SIGNAL(sendStatus(bool)), this, SLOT(receiveLeftCameraStatus(bool)));
    connect(leftGrabber, SIGNAL(sendFrame(cv::Mat)), this, SLOT(receiveFrameLeft(cv::Mat)));
    connect(rightGrabber, SIGNAL(sendStatus(bool)), this, SLOT(receiveRightCameraStatus(bool)));
    connect(rightGrabber, SIGNAL(sendFrame(cv::Mat)), this, SLOT(receiveFrameRight(cv::Mat)));
    connect(threadLeftCameraFrameGrabber, SIGNAL(finished()), leftGrabber, SLOT(deleteLater()));
    connect(threadRightCameraFrameGrabber, SIGNAL(finished()), rightGrabber, SLOT(deleteLater()));
    connect(threadGrabberTimer, SIGNAL(finished()), timer, SLOT(deleteLater()));
    connect(threadGrabberTimer, SIGNAL(started()), timer, SLOT(start()));

    leftGrabber->moveToThread(threadLeftCameraFrameGrabber);
    rightGrabber->moveToThread(threadRightCameraFrameGrabber);
    timer->moveToThread(threadGrabberTimer);

    threadLeftCameraFrameGrabber->start();
    threadRightCameraFrameGrabber->start();

    emit sendLeftCameraSetup(ui->leftCameraId->value());
    emit sendRightCameraSetup(ui->rightCameraId->value());

    threadGrabberTimer->start();
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

void widgetSettings::receiveFrameLeft(cv::Mat frame)
{
    displayFrame(frame, ui->leftCamera);
}

void widgetSettings::receiveFrameRight(cv::Mat frame)
{
    displayFrame(frame, ui->rightCamera);
}

void widgetSettings::receiveLeftCameraStatus(bool status)
{
    displayCameraStatus(status, ui->labelLeftCameraStatus);
}

void widgetSettings::receiveRightCameraStatus(bool status)
{
    displayCameraStatus(status, ui->labelRightCameraStatus);
}

void widgetSettings::on_leftCameraId_valueChanged(int arg1)
{
    emit sendLeftCameraSetup(arg1);
}


void widgetSettings::on_rightCameraId_valueChanged(int arg1)
{
    emit sendRightCameraSetup(arg1);
}
