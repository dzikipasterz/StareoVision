#include "widgetmeasoffline.h"
#include "ui_widgetmeasoffline.h"

widgetMeasOffline::widgetMeasOffline(AppSettings *sett) :
    ui(new Ui::widgetMeasOffline),
    depthDisplay(new DepthDisplay()),
    mapper(nullptr),
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
    rectifier = new Rectifier();
    stereoMatcher = new BlockMatching(); //#todo: zaleznie od wybranego algorytmu

    // connect

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
