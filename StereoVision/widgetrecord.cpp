#include "widgetrecord.h"
#include "ui_widgetrecord.h"

widgetRecord::widgetRecord(AppSettings sett) :
    ui(new Ui::widgetRecord)
{
    ui->setupUi(this);
    settings = sett;

    ui->labelLeftCamera->setScaledContents(true);
    ui->labelRightCamera->setScaledContents(true);
    ui->labelLeftPicPath->setText("");
    ui->labelRightPicPath->setText("");
    ui->labelMovPath->setText("");
    ui->pushButtonMakeMovie->toggled(false);
    ui->pushButtonMakeMovie->setText("Nagrywaj");

    AppWidget::initTimer();
    AppWidget::initCamera(settings.readLeftCameraId(), settings.readRightCameraId());

    connect(AppWidget::camera,SIGNAL(sendFrames(cv::Mat, cv::Mat)),this,SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendJobDone()), AppWidget::intervalRegulator, SLOT(receiveJobDone()));

    AppWidget::startCamera();
    AppWidget::startTimer();

}

widgetRecord::~widgetRecord()
{
    delete ui;
}


void widgetRecord::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    displayFrame(leftFrame, ui->labelLeftCamera);
    displayFrame(rightFrame, ui->labelRightCamera);
}
