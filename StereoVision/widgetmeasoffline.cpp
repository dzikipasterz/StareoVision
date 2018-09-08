#include "widgetmeasoffline.h"
#include "ui_widgetmeasoffline.h"

widgetMeasOffline::widgetMeasOffline(AppSettings *sett) :
    ui(new Ui::widgetMeasOffline),
    depthDisplay(new DepthDisplay()),
    rectifier(nullptr),
    stereoMatcher(nullptr),
    threadSourceReader(nullptr),
    threadRectifier(nullptr),
    threadStereoMatcher(nullptr)
{
    ui->setupUi(this);
    settings = sett;

    connect(depthDisplay, SIGNAL(sendDistance(double)), this, SLOT(receiveDistance(double)));
    ui->gridLayout->addWidget(depthDisplay,0,0);
    depthDisplay->setFrameShape(QFrame::Box);
    depthDisplay->setScaledContents(true);
    depthDisplay->setDispToDistMat(settings->readDispToDepthMap());
    ui->labelLeftDisplay->setScaledContents(true);
    ui->labelRightDisplay->setScaledContents(true);
}


widgetMeasOffline::~widgetMeasOffline()
{
    stopThreads();
    delete ui;
    delete depthDisplay;
}

void widgetMeasOffline::setupMeasurement()
{
    stopThreads();

    threadSourceReader = new QThread();
    threadRectifier = new QThread();
    threadStereoMatcher = new QThread();

    sourceReader = new VideoReader(); //#todo: zaleznie od formatu
    sourceReader->setSourcePaths(ui->labelSourceLeft->text(), ui->labelSourceRight->text());
    rectifier = new Rectifier();
    rectifier->setCalibrationFile(settings->readCalibFilePath());
    stereoMatcher = new StereoSGBMcpu(); //#todo: zaleznie od wybranego algorytmu

    connect(threadSourceReader, SIGNAL(finished()), sourceReader, SLOT(deleteLater()));
    connect(threadRectifier, SIGNAL(finished()), rectifier, SLOT(deleteLater()));
    connect(threadStereoMatcher, SIGNAL(finished()), stereoMatcher, SLOT(deleteLater()));

    connect(this, SIGNAL(SendStartMeas()), sourceReader, SLOT(receiveStart()));
    connect(sourceReader, SIGNAL(sendFrames(cv::Mat, cv::Mat)), rectifier, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(rectifier, SIGNAL(sendFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat)), stereoMatcher, SLOT(receiveFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat)));
    connect(stereoMatcher, SIGNAL(sendDisparity(cv::Mat, cv::Mat, cv::Mat)), this, SLOT(receiveDisparity(cv::Mat, cv::Mat, cv::Mat)));
    connect(stereoMatcher, SIGNAL(sendJobDone()), sourceReader, SLOT(receiveJobDone()));

    sourceReader->moveToThread(threadSourceReader);
    rectifier->moveToThread(threadRectifier);
    stereoMatcher->moveToThread(threadStereoMatcher);

    threadStereoMatcher->start();
    threadRectifier->start();
    threadSourceReader->start();

    emit SendStartMeas();
}

void widgetMeasOffline::stopThreads()
{
    if(threadSourceReader != nullptr)
    {
        threadSourceReader->quit();
        while(!threadSourceReader->isFinished());
        threadSourceReader = nullptr;
    }

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

void widgetMeasOffline::receiveDisparity(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat disparity)
{
    displayDisparity(disparity, depthDisplay);
    displayFrame(leftFrameRaw, ui->labelLeftDisplay);
    displayFrame(rightFrameRaw, ui->labelRightDisplay);
}

void widgetMeasOffline::receiveDistance(double distance)
{
    ui->doubleSpinBoxDistance->setValue(distance);
}

void widgetMeasOffline::on_pushButtonLeftSource_clicked()
{
    leftSourcePath = QFileDialog::getOpenFileName(nullptr, "Wybierz źródło lewego obrazu", settings->readPictSavePath());
    ui->labelSourceLeft->setText(leftSourcePath);
}

void widgetMeasOffline::on_pushButtonRightSource_clicked()
{
    rightSourcePath = QFileDialog::getOpenFileName(nullptr, "Wybierz źródło prawego obrazu", settings->readPictSavePath());
    ui->labelSourceRight->setText(rightSourcePath);
}

void widgetMeasOffline::on_pushButtonStart_clicked()
{
    setupMeasurement();
}
