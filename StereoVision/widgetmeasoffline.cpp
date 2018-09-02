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

    connect(depthDisplay, SIGNAL(sendPixelArrCoord(int, int)), this, SLOT(receivePixelArrCoord(int, int)));
    connect(depthDisplay, SIGNAL(sendPixelValue(int)), this, SLOT(receivePixValue(int)));
    ui->gridLayout->addWidget(depthDisplay,0,0);
    depthDisplay->setFrameShape(QFrame::Box);
    depthDisplay->setScaledContents(true);
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
    threadSourceReader = new QThread();
    threadRectifier = new QThread();
    threadStereoMatcher = new QThread();

    sourceReader = new ImageReader(); //#todo: zaleznie od formatu
    sourceReader->setSourcePaths(ui->labelSourceLeft->text(), ui->labelSourceRight->text());
    rectifier = new Rectifier();
    rectifier->setCalibrationFile(settings->readCalibFilePath());
    stereoMatcher = new StereoBM(); //#todo: zaleznie od wybranego algorytmu

    connect(threadSourceReader, SIGNAL(finished()), sourceReader, SLOT(deleteLater()));
    connect(threadRectifier, SIGNAL(finished()), rectifier, SLOT(deleteLater()));
    connect(threadStereoMatcher, SIGNAL(finished()), stereoMatcher, SLOT(deleteLater()));


    connect(this, SIGNAL(SendStartMeas()), sourceReader, SLOT(receiveStart()));
    connect(sourceReader, SIGNAL(sendFrames(cv::Mat, cv::Mat)), rectifier, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(rectifier, SIGNAL(sendFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat)), stereoMatcher, SLOT(receiveFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat)));
    connect(stereoMatcher, SIGNAL(sendDisparity(cv::Mat, cv::Mat, cv::Mat)), this, SLOT(receiveDisparity(cv::Mat, cv::Mat, cv::Mat)));

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

void widgetMeasOffline::receivePixelArrCoord(int, int)
{

}

void widgetMeasOffline::receiveDisparity(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat disparity)
{
    displayDisparity(disparity, depthDisplay);
    displayFrame(leftFrameRaw, ui->labelLeftDisplay);
    displayFrame(rightFrameRaw, ui->labelRightDisplay);
}

void widgetMeasOffline::receivePixValue(int val)
{
    ui->doubleSpinBoxPixelVal->setValue(val);
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
