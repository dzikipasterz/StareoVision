#include "widgetrecord.h"
#include "ui_widgetrecord.h"

widgetRecord::widgetRecord(AppSettings *sett) :
    ui(new Ui::widgetRecord)
{
    ui->setupUi(this);
    settings = sett;

    ui->labelLeftCamera->setScaledContents(true);
    ui->labelRightCamera->setScaledContents(true);
    ui->labelLeftPicPath->setText("");
    ui->labelRightPicPath->setText("");
    ui->labelLeftMovPath->setText("");
    ui->labelRightMovPath->setText("");
    ui->pushButtonMakeMovie->toggled(false);
    ui->pushButtonMakeMovie->setText("Nagrywaj");

    AppWidget::initTimer();
    AppWidget::initCamera(settings->readLeftCameraId(), settings->readRightCameraId());
    threadRecord = new QThread();
    pictureTaker = new PictureTaker(settings->readPictSavePath());
    leftVideoWriter = new VideoWriter();
    rightVideoWriter = new VideoWriter();

    connect(AppWidget::camera, SIGNAL(sendFrames(cv::Mat, cv::Mat)),this, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendFrames(cv::Mat, cv::Mat)), pictureTaker, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendFrames(cv::Mat, cv::Mat)), videoWriter, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendJobDone()), AppWidget::intervalRegulator, SLOT(receiveJobDone()));
    connect(threadRecord, SIGNAL(finished()), pictureTaker, SLOT(deleteLater()));
    connect(threadRecord, SIGNAL(finished()), videoWriter, SLOT(deleteLater()));
    connect(this, SIGNAL(sendTakePicture()), pictureTaker, SLOT(receiveTakePicture()));
    connect(pictureTaker, SIGNAL(sendImagesPaths(QString, QString)), this, SLOT(receiveImagesPaths(QString, QString)));
    connect(this, SIGNAL(sendStartRecording()), videoWriter, SLOT(receiveStartRecording()));
    connect(this, SIGNAL(sendStopRecording()), videoWriter, SLOT(receiveStopRecording()));
    connect(videoWriter, SIGNAL(sendMovFilesPaths(QString, QString)), this, SLOT(receiveMoviesPaths(QString, QString)));


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

void widgetRecord::receiveImagesPaths(QString leftPath, QString rightPath)
{
    ui->labelLeftPicPath->setText(leftPath);
    ui->labelRightPicPath->setText(rightPath);
}

void widgetRecord::receiveMoviesPaths(QString leftPath, QString rightPath)
{
    ui->labelLeftMovPath->setText(leftPath);
    ui->labelRightMovPath->setText(rightPath);
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
