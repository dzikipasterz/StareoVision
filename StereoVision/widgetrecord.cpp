#include "widgetrecord.h"
#include "ui_widgetrecord.h"

widgetRecord::widgetRecord(AppSettings *sett) :
    ui(new Ui::widgetRecord)
{
    ui->setupUi(this);
    settings = sett;

    //----------------------------------------------------------------------------------------------------------------

    //init GUI
    ui->labelLeftCamera->setScaledContents(true);
    ui->labelRightCamera->setScaledContents(true);
    ui->labelLeftPicPath->setText("");
    ui->labelRightPicPath->setText("");
    ui->labelLeftMovPath->setText("");
    ui->labelRightMovPath->setText("");
    ui->pushButtonMakeMovie->toggled(false);
    ui->pushButtonMakeMovie->setText("Nagrywaj");

    //----------------------------------------------------------------------------------------------------------------

    //init camera, writers and threads
    AppWidget::initTimer();
    AppWidget::initCamera(settings->readLeftCameraId(), settings->readRightCameraId(), singleFrames);
    threadRecord = new QThread();
    leftPictureTaker = new PictureTaker();
    rightPictureTaker = new PictureTaker();
    leftVideoWriter = new VideoWriter();
    rightVideoWriter = new VideoWriter();

    //----------------------------------------------------------------------------------------------------------------

    //camera <------> this
    connect(AppWidget::camera, SIGNAL(sendLeftFrame(cv::Mat)),this, SLOT(receiveLeftFrame(cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendRightFrame(cv::Mat)),this, SLOT(receiveRightFrame(cv::Mat)));

    //----------------------------------------------------------------------------------------------------------------

    //camera <------> PictureTaker
    connect(AppWidget::camera, SIGNAL(sendLeftFrame(cv::Mat)), leftPictureTaker, SLOT(receiveFrame(cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendRightFrame(cv::Mat)), rightPictureTaker, SLOT(receiveFrame(cv::Mat)));

    //----------------------------------------------------------------------------------------------------------------

    //camera <------> VideoWriter
    connect(AppWidget::camera, SIGNAL(sendLeftFrame(cv::Mat)), leftVideoWriter, SLOT(receiveFrame(cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendRightFrame(cv::Mat)), rightVideoWriter, SLOT(receiveFrame(cv::Mat)));

    //----------------------------------------------------------------------------------------------------------------

    //camera <------> IntervalRegulator
    connect(AppWidget::camera, SIGNAL(sendJobDone()), AppWidget::intervalRegulator, SLOT(receiveJobDone()));

    //----------------------------------------------------------------------------------------------------------------

    //threadRecord <------> PictureTaker, VideoWriter
    connect(threadRecord, SIGNAL(finished()), leftPictureTaker, SLOT(deleteLater()));
    connect(threadRecord, SIGNAL(finished()), rightPictureTaker, SLOT(deleteLater()));
    connect(threadRecord, SIGNAL(finished()), leftVideoWriter, SLOT(deleteLater()));
    connect(threadRecord, SIGNAL(finished()), rightVideoWriter, SLOT(deleteLater()));

    //----------------------------------------------------------------------------------------------------------------

    //this <------> PictureTaker
    connect(this, SIGNAL(sendTakePicture()), leftPictureTaker, SLOT(receiveTakePicture()));
    connect(this, SIGNAL(sendTakePicture()), rightPictureTaker, SLOT(receiveTakePicture()));
    connect(this, SIGNAL(sendSetLeftPicSavePath(QString)), leftPictureTaker, SLOT(receiveSetPath(QString)));
    connect(this, SIGNAL(sendSetRightPicSavePath(QString)), rightPictureTaker, SLOT(receiveSetPath(QString)));
    connect(leftPictureTaker, SIGNAL(sendImagePath(QString)), this, SLOT(receiveLeftImagePath(QString)));
    connect(rightPictureTaker, SIGNAL(sendImagePath(QString)), this, SLOT(receiveRightImagePath(QString)));

    //----------------------------------------------------------------------------------------------------------------

    //this <------> VideoWriter
    connect(this, SIGNAL(sendSetLeftMovSavePath(QString)), leftVideoWriter, SLOT(receiveSetSavePath(QString)));
    connect(this, SIGNAL(sendSetRightMovSavePath(QString)), rightVideoWriter, SLOT(receiveSetSavePath(QString)));
    connect(this, SIGNAL(sendStartRecording()), leftVideoWriter, SLOT(receiveStartWriting()));
    connect(this, SIGNAL(sendStartRecording()), rightVideoWriter, SLOT(receiveStartWriting()));
    connect(this, SIGNAL(sendStopRecording()), leftVideoWriter, SLOT(receiveStopWriting()));
    connect(this, SIGNAL(sendStopRecording()), rightVideoWriter, SLOT(receiveStopWriting()));
    connect(leftVideoWriter, SIGNAL(sendFilePath(QString)), this, SLOT(receiveLeftMoviePath(QString)));
    connect(rightVideoWriter, SIGNAL(sendFilePath(QString)), this, SLOT(receiveRightMoviePath(QString)));

    //----------------------------------------------------------------------------------------------------------------

    //move workers to threads
    rightVideoWriter->moveToThread(threadRecord);
    leftVideoWriter->moveToThread(threadRecord);
    leftPictureTaker->moveToThread(threadRecord);
    rightPictureTaker->moveToThread(threadRecord);
    threadRecord->start();

    //----------------------------------------------------------------------------------------------------------------

    AppWidget::startCamera();
    AppWidget::startTimer();

}

widgetRecord::~widgetRecord()
{
    //safely quit thread
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

void widgetRecord::receiveLeftImagePath(QString leftPath)
{
    ui->labelLeftPicPath->setText(leftPath);
}

void widgetRecord::receiveRightImagePath(QString rightPath)
{
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
    //create file name with current timestamp
    QDateTime time = QDateTime::currentDateTime();
    QString timeString = time.toString("yyyyMMdd_hhmmss_");
    QString leftPath = settings->readPictSavePath();
    leftPath = leftPath.append(timeString).append("L.jpg");
    QString rightPath = settings->readPictSavePath();
    rightPath = rightPath.append(timeString).append("R.jpg");

    //set paths and take pictures
    emit sendSetLeftPicSavePath(leftPath);
    emit sendSetRightPicSavePath(rightPath);
    emit sendTakePicture();
}

void widgetRecord::on_pushButtonMakeMovie_toggled(bool checked)
{
    if(checked)
    {
        //change boolean text when pressed to "zatrzymaj" ("stop") when recording enabled
        ui->pushButtonMakeMovie->setText("Zatrzymaj");

        //create file name (path) with current timestamp
        QDateTime time = QDateTime::currentDateTime();
        QString timeString = time.toString("yyyyMMdd_hhmmss_");
        QString leftPath = settings->readMovFilesDir();
        leftPath = leftPath.append(timeString).append("L.avi");
        QString rightPath = settings->readMovFilesDir();
        rightPath = rightPath.append(timeString).append("R.avi");

        //set paths and start recording
        emit sendSetLeftMovSavePath(leftPath);
        emit sendSetRightMovSavePath(rightPath);
        emit sendStartRecording();
    }
    else
    {
        //change boolean text to "nagrywaj" ("record") when recording disabled
        ui->pushButtonMakeMovie->setText("Nagrywaj");

        //stop recording
        emit sendStopRecording();
    }
}
