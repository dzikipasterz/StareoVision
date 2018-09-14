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

    connect(AppWidget::camera, SIGNAL(sendLeftFrame(cv::Mat)),this, SLOT(receiveLeftFrame(cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendRightFrame(cv::Mat)),this, SLOT(receiveRightFrame(cv::Mat)));
    //connect(AppWidget::camera, SIGNAL(sendRightFrame(cv::Mat)), pictureTaker, SLOT(receiveRightFrame(cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendLeftFrame(cv::Mat)), leftVideoWriter, SLOT(receiveFrame(cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendRightFrame(cv::Mat)), rightVideoWriter, SLOT(receiveFrame(cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendJobDone()), AppWidget::intervalRegulator, SLOT(receiveJobDone()));
    connect(threadRecord, SIGNAL(finished()), pictureTaker, SLOT(deleteLater()));
    connect(threadRecord, SIGNAL(finished()), leftVideoWriter, SLOT(deleteLater()));
    connect(threadRecord, SIGNAL(finished()), rightVideoWriter, SLOT(deleteLater()));
    connect(this, SIGNAL(sendTakePicture()), pictureTaker, SLOT(receiveTakePicture()));
    connect(pictureTaker, SIGNAL(sendImagesPaths(QString, QString)), this, SLOT(receiveImagesPaths(QString, QString)));

    connect(this, SIGNAL(sendSetLeftSavePath(QString)), leftVideoWriter, SLOT(receiveSetSavePath(QString)));
    connect(this, SIGNAL(sendSetRightSavePath(QString)), rightVideoWriter, SLOT(receiveSetSavePath(QString)));
    connect(this, SIGNAL(sendStartRecording()), leftVideoWriter, SLOT(receiveStartWriting()));
    connect(this, SIGNAL(sendStartRecording()), rightVideoWriter, SLOT(receiveStartWriting()));
    connect(this, SIGNAL(sendStopRecording()), leftVideoWriter, SLOT(receiveStopWriting()));
    connect(this, SIGNAL(sendStopRecording()), rightVideoWriter, SLOT(receiveStopWriting()));
    connect(leftVideoWriter, SIGNAL(sendFilePath(QString)), this, SLOT(receiveLeftMoviePath(QString)));
    connect(rightVideoWriter, SIGNAL(sendFilePath(QString)), this, SLOT(receiveRightMoviePath(QString)));

    rightVideoWriter->moveToThread(threadRecord);
    leftVideoWriter->moveToThread(threadRecord);
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


void widgetRecord::receiveLeftFrame(cv::Mat leftFrame)
{
    displayFrame(leftFrame, ui->labelLeftCamera);
}

void widgetRecord::receiveRightFrame(cv::Mat rightFrame)
{
    displayFrame(rightFrame, ui->labelRightCamera);
}

void widgetRecord::receiveImagesPaths(QString leftPath, QString rightPath)
{
    ui->labelLeftPicPath->setText(leftPath);
    ui->labelRightPicPath->setText(rightPath);
}

void widgetRecord::receiveLeftMoviePath(QString leftPath)
{
    ui->labelLeftMovPath->setText(leftPath);
}

void widgetRecord::receiveRightMoviePath(QString rightPath)
{
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
        QDateTime time = QDateTime::currentDateTime();
        QString timeString = time.toString("yyyymmdd_hhmmss_");
        QString leftPath = settings->readMovFilesDir();
        leftPath = leftPath.append(timeString).append("L.avi");
        QString rightPath = settings->readMovFilesDir();
        rightPath = rightPath.append(timeString).append("R.avi");

        emit sendSetLeftSavePath(leftPath);
        emit sendSetRightSavePath(rightPath);
        emit sendStartRecording();
    }
    else
    {
        ui->pushButtonMakeMovie->setText("Nagrywaj");
        emit sendStopRecording();
    }
}
