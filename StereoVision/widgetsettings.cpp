#include "widgetsettings.h"
#include "ui_widgetsettings.h"

widgetSettings::widgetSettings(AppSettings sett) :
    ui(new Ui::widgetSettings)
{
    //AppWidget
    settings = sett;

    //widgetSettings
    ui->setupUi(this);
    ui->leftCamera->setScaledContents(true);
    ui->rightCamera->setScaledContents(true);
    ui->leftCameraId->setValue(settings.readLeftCameraId());
    ui->rightCameraId->setValue(settings.readRightCameraId());

    startup();
}

widgetSettings::~widgetSettings()
{
    delete ui;
}

void widgetSettings::startup()
{ 
    AppWidget::startup();
    AppWidget::initTimer();
    AppWidget::initCamera(settings.readLeftCameraId(), settings.readRightCameraId());

    connect(this, SIGNAL(sendStereoCameraSetup(const int, const int)), AppWidget::camera, SLOT(receiveSetup(const int, const int)));
    connect(AppWidget::camera, SIGNAL(sendCameraStatus(bool, bool)), this, SLOT(receiveCameraStatus(bool, bool)));
    connect(AppWidget::camera, SIGNAL(sendFrames(cv::Mat, cv::Mat)), this, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendJobDone()), AppWidget::intervalRegulator, SLOT(receiveJobDone()));

    AppWidget::startCamera();
    AppWidget::startTimer();
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

    if(leftCameraStatus || rightCameraStatus)
    {
        emit sendStereoCameraSetup(ui->leftCameraId->value(), ui->rightCameraId->value());
    }
}

void widgetSettings::on_leftCameraId_valueChanged(int leftCameraId)
{
    settings.setLeftCameraId(leftCameraId);
    emit sendSettingsChanged(settings);
    emit sendStereoCameraSetup(settings.readLeftCameraId(), settings.readRightCameraId());
}

void widgetSettings::on_rightCameraId_valueChanged(int rightCameraId)
{
    settings.setRightCameraId(rightCameraId);
    emit sendSettingsChanged(settings);
    emit sendStereoCameraSetup(settings.readLeftCameraId(), settings.readRightCameraId());
}
