#include "widgetcalibration.h"
#include "ui_widgetcalibration.h"

widgetCalibration::widgetCalibration(AppSettings sett) :
    ui(new Ui::widgetCalibration),
    pictureTaker(nullptr)
{
    //AppWidget
    settings = sett;

    //widgetCalibration
    ui->setupUi(this);
    ui->leftCamera->setScaledContents(true);
    ui->rightCamera->setScaledContents(true);
    ui->pushButtonTurnCameraOn->setText("Włącz kamerę");
    ui->pushButtonTurnCameraOn->toggled(false);

}

widgetCalibration::~widgetCalibration()
{
    if(pictureTaker != nullptr) delete pictureTaker;
    delete ui;
}


void widgetCalibration::openCamera()
{
    AppWidget::startup();
    AppWidget::initTimer();
    AppWidget::initCamera(settings.readLeftCameraId(), settings.readRightCameraId());

    threadCornersFinder = new QThread;
    cornersFinder = new CornersFinder();
    pictureTaker = new PictureTaker();

    connect(AppWidget::camera, SIGNAL(sendFrames(cv::Mat, cv::Mat)), cornersFinder, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendFrames(cv::Mat, cv::Mat)), pictureTaker, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(cornersFinder, SIGNAL(sendProcessedFrames(cv::Mat, cv::Mat)), this, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(cornersFinder, SIGNAL(sendJobDone()), AppWidget::intervalRegulator, SLOT(receiveJobDone()));
    connect(this, SIGNAL(sendTakePicture()), pictureTaker, SLOT(receiveTakePicture()));

    cornersFinder->moveToThread(threadCornersFinder);
    threadCornersFinder->start();

    AppWidget::startCamera();
    AppWidget::startTimer();
}

void widgetCalibration::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    AppWidget::displayFrame(leftFrame, ui->leftCamera);
    AppWidget::displayFrame(rightFrame, ui->rightCamera);
}

void widgetCalibration::on_pushButtonTurnCameraOn_toggled(bool checked)
{
    if(checked)
    {
        ui->pushButtonTurnCameraOn->setText("Zatrzymaj kamerę");

        if(!cameraInitialized)
        {
            openCamera();
            cameraInitialized=true;
        }
        else resumeTimer();
    }

    else
    {
        ui->pushButtonTurnCameraOn->setText("Włącz kamerę");
        pauseTimer();
    }
}

void widgetCalibration::on_pushButtonTakePicture_clicked()
{
    emit sendTakePicture();
}
