#include "widgetmeasoffline.h"
#include "ui_widgetmeasoffline.h"

widgetMeasOffline::widgetMeasOffline(AppSettings *sett) :
    ui(new Ui::widgetMeasOffline),
    depthDisplay(new DepthDisplay()),
    rectifier(nullptr),
    stereoMatcher(nullptr),
    threadSourceReader(nullptr),
    threadRectifier(nullptr),
    threadStereoMatcher(nullptr),
    threadPostprocessing(nullptr),
    threadDispToDist(nullptr)
{
    ui->setupUi(this);
    settings = sett;

    connect(depthDisplay, SIGNAL(sendPixelArrCoord(int, int)), this, SLOT(receivePixelArrCoord(int, int)));
    ui->gridLayout->addWidget(depthDisplay,0,0);
    depthDisplay->setFrameShape(QFrame::Box);
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
    threadPostprocessing = new QThread();
    threadDispToDist = new QThread();

    sourceReader = new ImageReader(); //#todo: zaleznie od formatu
    sourceReader->setSourcePaths(ui->labelSourceLeft->text(), ui->labelSourceRight->text());
    rectifier = new Rectifier();
    rectifier->setCalibrationFile(settings->readCalibFilePath());
    stereoMatcher = new BlockMatching(); //#todo: zaleznie od wybranego algorytmu
    stereoMatcher->setCalibFile(settings->readCalibFilePath());
    filter = new PostFilter(); //#todo: zaleznie od wybranego algorytmu
    converter = new DisparityConverter();

    connect(threadSourceReader, SIGNAL(finished()), sourceReader, SLOT(deleteLater()));
    connect(threadRectifier, SIGNAL(finished()), rectifier, SLOT(deleteLater()));
    connect(threadStereoMatcher, SIGNAL(finished()), stereoMatcher, SLOT(deleteLater()));
    connect(threadPostprocessing, SIGNAL(finished()), filter, SLOT(deleteLater()));
    connect(threadDispToDist, SIGNAL(finished()), converter, SLOT(deleteLater()));

    connect(this, SIGNAL(startMeas()), sourceReader, SLOT(receiveStart()));
    connect(sourceReader, SIGNAL(sendFrames(cv::Mat, cv::Mat)), rectifier, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(rectifier, SIGNAL(sendFrames(cv::Mat, cv::Mat)), stereoMatcher, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(stereoMatcher, SIGNAL(sendDisparityMap(cv::Mat)), filter, SLOT(receiveFrame(cv::Mat)));
    connect(filter, SIGNAL(sendFrame(cv::Mat)), converter, SLOT(receiveFrames(cv::Mat)));
    connect(converter, SIGNAL(sendFrame(cv::Mat)), this, SLOT(receiveFrame(cv::Mat)));

    sourceReader->moveToThread(threadSourceReader);
    rectifier->moveToThread(threadRectifier);
    stereoMatcher->moveToThread(threadStereoMatcher);

    threadDispToDist->start();
    threadPostprocessing->start();
    threadStereoMatcher->start();
    threadRectifier->start();
    threadSourceReader->start();
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

    if(threadPostprocessing != nullptr)
    {
        threadPostprocessing->quit();
        while(!threadPostprocessing->isFinished());
        threadPostprocessing = nullptr;
    }

    if(threadDispToDist != nullptr)
    {
        threadDispToDist->quit();
        while(!threadDispToDist->isFinished());
        threadDispToDist = nullptr;
    }
}

void widgetMeasOffline::receivePixelArrCoord(int x, int y)
{

}

void widgetMeasOffline::receiveFrame(cv::Mat frame)
{
    displayFrame(frame, depthDisplay);
}

void widgetMeasOffline::on_pushButtonLeftSource_clicked()
{
    leftSourcePath = QFileDialog::getOpenFileName(nullptr, "Wybierz źródło lewego obrazu", settings->readPictSavePath());
}

void widgetMeasOffline::on_pushButtonRightSource_clicked()
{
    rightSourcePath = QFileDialog::getOpenFileName(nullptr, "Wybierz źródło prawego obrazu", settings->readPictSavePath());
}

void widgetMeasOffline::on_pushButton_clicked()
{

}
