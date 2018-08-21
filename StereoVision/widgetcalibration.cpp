#include "widgetcalibration.h"
#include "ui_widgetcalibration.h"

widgetCalibration::widgetCalibration(AppSettings sett) :
    ui(new Ui::widgetCalibration),
    threadCornersFinder(nullptr),
    threadCalibrator(nullptr),
    calibrator(nullptr),
    cameraInitialized(false),
    captureFrames(false)
{
    //AppWidget
    settings = sett;

    //widgetCalibration
    ui->setupUi(this);
    ui->leftCamera->setScaledContents(true);
    ui->rightCamera->setScaledContents(true);
    ui->pushButtonTurnCameraOn->setText("Włącz kamerę");
    ui->pushButtonTurnCameraOn->toggled(false);
    ui->spinBoxCollectedSets->setValue(0);
    ui->labelLastPictStatus->setText("");

}

widgetCalibration::~widgetCalibration()
{
    if(cameraInitialized)
    {
        threadCalibrator->quit();
        threadCornersFinder->quit();
        while(!threadCalibrator->isFinished());
        while(!threadCornersFinder->isFinished());

        delete threadCalibrator;
        delete threadCornersFinder;
    }
    delete ui;
}


void widgetCalibration::openCamera()
{
    AppWidget::startup();
    AppWidget::initTimer();
    AppWidget::initCamera(settings.readLeftCameraId(), settings.readRightCameraId());

    threadCornersFinder = new QThread;
    threadCalibrator = new QThread;
    cornersFinder = new CornersFinder();

    calibrator = new Calibrator();
    calibrator->setPatternSize(cv::Size(6,9));
    calibrator->setSquareSideSize(0.026f);

    connect(AppWidget::camera, SIGNAL(sendFrames(cv::Mat, cv::Mat)), cornersFinder, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendFrames(cv::Mat, cv::Mat)), calibrator, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(cornersFinder, SIGNAL(sendProcessedFrames(cv::Mat, cv::Mat)), this, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(cornersFinder, SIGNAL(sendJobDone()), AppWidget::intervalRegulator, SLOT(receiveJobDone()));

    connect(threadCalibrator, SIGNAL(finished()), calibrator, SLOT(deleteLater()));
    connect(threadCornersFinder, SIGNAL(finished()), cornersFinder, SLOT(deleteLater()));
    connect(this, SIGNAL(sendTakePicture()), calibrator, SLOT(receiveTakePicture()), Qt::DirectConnection);
    connect(this, SIGNAL(sendStartCalibration()), calibrator, SLOT(receiveStartCalibration()));
    connect(calibrator, SIGNAL(sendCalibratorStatus(int, bool)), this, SLOT(receiveCalibratorStatus(int, bool)));

    calibrator->moveToThread(threadCalibrator);
    cornersFinder->moveToThread(threadCornersFinder);
    threadCornersFinder->start();
    threadCalibrator->start();

    AppWidget::startCamera();
    AppWidget::startTimer();
}

void widgetCalibration::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    AppWidget::displayFrame(leftFrame, ui->leftCamera);
    AppWidget::displayFrame(rightFrame, ui->rightCamera);
    leftFrame.release();
    rightFrame.release();
}

void widgetCalibration::receiveCalibratorStatus(int setsNumber, bool lastSetStatus)
{
    QString status;
    if (lastSetStatus) status = "Zdjęcie nie zostało dodane do zestawu kalibracyjnego";
    else status = "Zdjęcie zostało pomyślnie dodane";
    ui->spinBoxCollectedSets->setValue(setsNumber);
    ui->labelLastPictStatus->setText(status);
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

void widgetCalibration::on_pushButtonCalibrate_clicked()
{
    emit sendStartCalibration();
}
