#include "widgetmeasoffline.h"
#include "ui_widgetmeasoffline.h"

widgetMeasOffline::widgetMeasOffline(AppSettings *sett) :
    ui(new Ui::widgetMeasOffline),
    depthDisplay(new DepthDisplay()),
    lastPath("/home"),
    writeToFile(false),
    rectifier(nullptr),
    stereoMatcher(nullptr),
    threadSourceReader(nullptr),
    threadRectifier(nullptr),
    threadStereoMatcher(nullptr)
{
    ui->setupUi(this);
    settings = sett;

    connect(depthDisplay, SIGNAL(sendDistance(double)), this, SLOT(receiveDistance(double)));
    connect(depthDisplay, SIGNAL(sendCoords(int, int)), this, SLOT(receiveCoords(int,int)));
    connect(depthDisplay, SIGNAL(sendFPS(double)), this, SLOT(receiveFPS(double)));
    connect(this, SIGNAL(sendCoords(int, int)), depthDisplay, SLOT(receiveCoords(int, int)));
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
    closeFile();
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

    switch(settings->readAlgorithm())
    {
        case Algorithm::BM_cpu:
            stereoMatcher = new StereoBMcpu;
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

    connect(threadSourceReader, SIGNAL(finished()), sourceReader, SLOT(deleteLater()));
    connect(threadRectifier, SIGNAL(finished()), rectifier, SLOT(deleteLater()));
    connect(threadStereoMatcher, SIGNAL(finished()), stereoMatcher, SLOT(deleteLater()));

    connect(this, SIGNAL(sendStartMeas()), sourceReader, SLOT(receiveStart()));
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

    emit sendStartMeas();
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

void widgetMeasOffline::openFile()
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

void widgetMeasOffline::closeFile()
{
    if(results.isOpen())
    {
        output.flush();
        results.close();
        writeToFile = false;
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
    if(writeToFile)
    {
        output << QString::number(distance).append(";").append(QString::number(FPS).append(";")) << endl;
    }
}

void widgetMeasOffline::receiveFPS(double fps)
{
    FPS = fps;
    ui->doubleSpinBoxFPS->setValue(fps);
}
void widgetMeasOffline::receiveCoords(int x, int y)
{
    ui->spinBoxX->setValue(x);
    ui->spinBoxY->setValue(y);
}

void widgetMeasOffline::on_pushButtonLeftSource_clicked()
{
    leftSourcePath = QFileDialog::getOpenFileName(nullptr, "Wybierz źródło lewego obrazu", lastPath);
    ui->labelSourceLeft->setText(leftSourcePath);
    lastPath = leftSourcePath;
}

void widgetMeasOffline::on_pushButtonRightSource_clicked()
{
    rightSourcePath = QFileDialog::getOpenFileName(nullptr, "Wybierz źródło prawego obrazu", lastPath);
    ui->labelSourceRight->setText(rightSourcePath);
    lastPath = rightSourcePath;
}

void widgetMeasOffline::on_pushButtonStart_clicked()
{
    setupMeasurement();
}

void widgetMeasOffline::on_spinBoxX_valueChanged(int x)
{
    emit sendCoords(x, ui->spinBoxY->value());
}

void widgetMeasOffline::on_spinBoxY_valueChanged(int y)
{
    emit sendCoords(ui->spinBoxX->value(), y);
}

void widgetMeasOffline::on_pushButtonWrite_toggled(bool write)
{
    if(write)
    {
        openFile();
    }
    else closeFile();

}
