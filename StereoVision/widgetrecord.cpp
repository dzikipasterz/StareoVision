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
    threadRecord = new QThread();
    pictureTaker = new PictureTaker(nullptr, settings.readPictSavePath());

    connect(AppWidget::camera, SIGNAL(sendFrames(cv::Mat, cv::Mat)),this, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendFrames(cv::Mat, cv::Mat)), pictureTaker, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendJobDone()), AppWidget::intervalRegulator, SLOT(receiveJobDone()));
    connect(threadRecord, SIGNAL(finished()), pictureTaker, SLOT(deleteLater()));
    connect(this, SIGNAL(sendTakePicture()), pictureTaker, SLOT(receiveTakePicture()));
    connect(pictureTaker, SIGNAL(sendLeftImagePath(QString)), this, SLOT(receiveLeftImagePath(QString)));
    connect(pictureTaker, SIGNAL(sendRightImagePath(QString)), this, SLOT(receiveRightImagePath(QString)));

    pictureTaker->moveToThread(threadRecord);
    threadRecord->start();
    AppWidget::startCamera();
    AppWidget::startTimer();

}

widgetRecord::~widgetRecord()
{
    threadRecord->quit();
    while(!threadRecord->isFinished());
    delete threadRecord;

    delete ui;
}


void widgetRecord::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    displayFrame(leftFrame, ui->labelLeftCamera);
    displayFrame(rightFrame, ui->labelRightCamera);
}

void widgetRecord::receiveLeftImagePath(QString path)
{
    ui->labelLeftPicPath->setText(path);
}

void widgetRecord::receiveRightImagePath(QString path)
{
    ui->labelRightPicPath->setText(path);
}

void widgetRecord::on_pushButtonTakePicture_clicked()
{
    emit sendTakePicture();
}

void widgetRecord::on_pushButtonMakeMovie_toggled(bool checked)
{
    if(checked)
    {
        ui->pushButtonMakeMovie->setText("Zatrzymaj");
        emit sendStartRecording();
    }
    else
    {
        ui->pushButtonMakeMovie->setText("Nagrywaj");
        emit sendStopRecording();
    }
}
