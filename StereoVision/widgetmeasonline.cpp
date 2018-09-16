#include "widgetmeasonline.h"
#include "ui_widgetmeasonline.h"

widgetMeasOnline::widgetMeasOnline(AppSettings *sett) :
    ui(new Ui::widgetMeasOnline),
    threadRectifier(nullptr),
    threadStereoMatcher(nullptr),
    writeToFile(false)
{

    settings = sett;

    //setup GUI
    ui->setupUi(this);
    ui->labelLeftDisplay->setScaledContents(true);
    ui->labelRightDisplay->setScaledContents(true);

    //------------------------------------------------------------------------------------------------------------------------

    //setup disparity display, connect slots and signals
    disparityDisplay = new DepthDisplay();
    disparityDisplay->setScaledContents(true);
    disparityDisplay->setDispToDistMat(settings->readDispToDepthMap());

    connect(disparityDisplay, SIGNAL(sendDistance(double)), this, SLOT(receiveDistance(double)));
    connect(disparityDisplay, SIGNAL(sendCoords(int, int)), this, SLOT(receiveCoords(int, int)));
    connect(disparityDisplay, SIGNAL(sendFPS(double)), this, SLOT(receiveFPS(double)));
    connect(this, SIGNAL(sendCoords(int, int)), disparityDisplay, SLOT(receiveCoords(int, int)));

    ui->gridLayoutMain->addWidget(disparityDisplay,0,0);

    //------------------------------------------------------------------------------------------------------------------------

    //init basic elements of AppWidget - timer and camera.
    AppWidget::initTimer();
    AppWidget::initCamera(settings->readLeftCameraId(), settings->readRightCameraId());

    //------------------------------------------------------------------------------------------------------------------------

    //setup rectifier
    threadRectifier = new QThread();
    rectifier = new Rectifier();
    rectifier->setCalibrationFile(settings->readCalibFilePath());

    //------------------------------------------------------------------------------------------------------------------------

    //setup stereomatcher
    threadStereoMatcher = new QThread();

    switch(settings->readAlgorithm())
    {
        case Algorithm::BM_cpu:
            stereoMatcher = new StereoBMcpu();
        break;

        case Algorithm::BM_cuda:
            stereoMatcher = new StereoBMcuda();
        break;

        case Algorithm::SGBM_cpu:
            stereoMatcher= new StereoSGBMcpu;
        break;

        case Algorithm::BP_cuda:
            stereoMatcher = new StereoBPcuda();
        break;

        case Algorithm::CSBP_cuda:
            stereoMatcher = new StereoCSBPcuda;
        break;
    }

    //------------------------------------------------------------------------------------------------------------------------

    //connect signals and slots

    //image process chain camera -> rectifier -> stereomatcher -> this
    connect(AppWidget::camera,SIGNAL(sendFrames(cv::Mat, cv::Mat)),rectifier,SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(rectifier, SIGNAL(sendFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat)), stereoMatcher, SLOT(receiveFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat)));
    connect(stereoMatcher, SIGNAL(sendDisparityAndRaw(cv::Mat, cv::Mat, cv::Mat)), this, SLOT(receiveDisparity(cv::Mat, cv::Mat, cv::Mat)));

    //end signals of threads ---> workers
    connect(threadRectifier, SIGNAL(finished()), rectifier, SLOT(deleteLater()));
    connect(threadStereoMatcher, SIGNAL(finished()), stereoMatcher, SLOT(deleteLater()));

    //feedback from stereomatcher to intervalRegulator about finished job (processed one pair of frames)
    connect(stereoMatcher, SIGNAL(sendJobDone()), AppWidget::intervalRegulator, SLOT(receiveJobDone()));

    //move workers to threads and start
    rectifier->moveToThread(threadRectifier);
    stereoMatcher->moveToThread(threadStereoMatcher);
    threadRectifier->start();
    threadStereoMatcher->start();

    //start camera and timer
    AppWidget::startCamera();
    AppWidget::startTimer();
}

widgetMeasOnline::~widgetMeasOnline()
{
    //safely remove disparityDisplay from UI and then delete UI and display
    ui->gridLayoutMain->removeWidget(disparityDisplay);
    delete ui;
    delete disparityDisplay;

    //stop threads if initialized
    if(threadRectifier != nullptr)
    {
        threadRectifier->quit();
        while(!threadRectifier->isFinished());
        threadRectifier = nullptr;
    }

    if(threadStereoMatcher != nullptr)
    {
        threadStereoMatcher->quit();
        while(!threadStereoMatcher->isFinished());
        threadStereoMatcher = nullptr;
    }
}

void widgetMeasOnline::openFile()
{
    closeFile();
    writeToFile = true;

    QDateTime currentTime = QDateTime::currentDateTime();
    QString filename = settings->readResultsDir().append(currentTime.toString("yyyyMMdd_hhmmss").append("_distance.csv"));
    results.setFileName(filename);
    results.open(QFile::WriteOnly | QIODevice::Append);
    if(results.isOpen())
    {
        output.setDevice(&results);
        ui->labelResultsPath->setText(filename);
    }
}

void widgetMeasOnline::closeFile()
{
    if(results.isOpen())
    {
        results.close();
        output.flush();
        writeToFile = false;
    }
}

void widgetMeasOnline::receiveDisparity(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat disparity)
{
    displayFrame(leftFrameRaw, ui->labelLeftDisplay);
    displayFrame(rightFrameRaw, ui->labelRightDisplay);
    displayDisparity(disparity, disparityDisplay);
}

void widgetMeasOnline::receiveDistance(double distance)
{
    ui->doubleSpinBoxDistance->setValue(distance);
    if(writeToFile)
    {
        output << QString::number(distance).append(";").append(QString::number(FPS).append(";")) << endl;
    }
}

void widgetMeasOnline::receiveCoords(int x, int y)
{
    ui->spinBoxX->setValue(x);
    ui->spinBoxY->setValue(y);
}

void widgetMeasOnline::receiveFPS(double fps)
{
    ui->doubleSpinBoxFPS->setValue(fps);
    FPS = fps;
}

void widgetMeasOnline::on_spinBoxX_valueChanged(int arg1)
{
   emit sendCoords(arg1, ui->spinBoxY->value());
}

void widgetMeasOnline::on_spinBoxY_valueChanged(int arg1)
{
   emit sendCoords(ui->spinBoxX->value(), arg1);
}

void widgetMeasOnline::on_pushButtonWrite_toggled(bool write)
{
    if(write)
    {
        openFile();
    }
    else closeFile();
}
