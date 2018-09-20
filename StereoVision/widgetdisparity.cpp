#include "widgetdisparity.h"
#include "ui_widgetdisparity.h"

WidgetDisparity::WidgetDisparity(AppSettings *sett) :
    ui(new Ui::WidgetDisparity),
    sourcesDir("/home/"),
    resultsDir("/home/"),
    lastDir("/home/"),
    threadSourceReader(nullptr),
    threadRectifier(nullptr),
    threadStereoMatcher(nullptr),
    threadFileWriter(nullptr)
{
    ui->setupUi(this);
    ui->labelSourcesDir->setText("/home");
    ui->labelResultsDir->setText("/home");
    ui->textBrowserStatus->setAlignment(Qt::AlignTop);
    settings = sett;
}

WidgetDisparity::~WidgetDisparity()
{
    delete ui;
}

//select a directory with pairs of stereoscopic images / videos
void WidgetDisparity::on_pushButtonSource_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"Wybierz folder ze źródłami", lastDir,QFileDialog::ShowDirsOnly);

    if(!dir.isNull())
    {
        dir.append("/");
        lastDir = dir;
        ui->labelSourcesDir->setText(dir);
    }
}

//select a directory to save disparity images / videos
void WidgetDisparity::on_pushButtonResults_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"Wybierz folder dla wyników", lastDir,QFileDialog::ShowDirsOnly);
    dir.append("/");
    lastDir = dir;
    ui->labelResultsDir->setText(dir);
}

//start calculating disparity
void WidgetDisparity::on_pushButtonStart_clicked()
{
    status = "";
    sourcesDir = ui->labelSourcesDir->text();

    QDir directory(ui->labelSourcesDir->text());
    QStringList filter;
    filter.append("*.jpg");
    filter.append("*.avi");
    directory.setNameFilters(filter);
    directory.setSorting(QDir::Name);
    QStringList files = directory.entryList();

    filesVector.clear();

    for(int i = 0; i < files.size(); i++)
    {
        filesVector.push_back(files.at(i));
    }

    iter = filesVector.begin();
    grabNextFiles();
}

void WidgetDisparity::stopThreads()
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

    if(threadFileWriter != nullptr)
    {
        threadFileWriter->quit();
        while(!threadFileWriter->isFinished());
        threadFileWriter = nullptr;
    }
}


void WidgetDisparity::grabNextFiles()
{
    sourcesDir = ui->labelSourcesDir->text();
    resultsDir = ui->labelResultsDir->text();

    leftSource = sourcesDir;
    rightSource = sourcesDir;
    leftSource = leftSource.append(*iter);
    iter++;
    rightSource = rightSource.append(*iter);
    iter++;

    QDateTime currentTime = QDateTime::currentDateTime();
    status.append(currentTime.toString("[hh:mm:ss] ")).append("Analizowany plik ").append(leftSource).append("\n");
    status.append(currentTime.toString("[hh:mm:ss] ")).append("Analizowany plik ").append(rightSource).append("\n");

    stopThreads();

    //check source files extensions and run correct source reader and file writer
    QString leftExt = leftSource.split(".").at(1);
    QString rightExt = rightSource.split(".").at(1);

    threadSourceReader = new QThread();
    threadFileWriter = new QThread();

    if((leftExt == rightExt) && (leftExt == "avi"))
    {
        sourceReader = new VideoReader(stereo);
        fileWriter = new VideoWriter();
        isVideo = true;
    }
    else if((leftExt == rightExt) && (leftExt == "jpg"))
    {
        sourceReader = new ImageReader(stereo);
        fileWriter = new ImageWriter();
        isVideo = false;
    }

    sourceReader->setSourcePaths(leftSource, rightSource);

    QString disparityFile = resultsDir;
    disparityFile = disparityFile.append(currentTime.toString("yyyyMMdd_hhmmss_")).append("disparity.").append(leftExt);
    fileWriter->receiveSetSavePath(disparityFile);
    status.append((currentTime.toString("[hh:mm:ss] ")).append("Wynikowy plik ").append(disparityFile).append("\n"));
    ui->textBrowserStatus->setText(status);
    ui->textBrowserStatus->moveCursor(QTextCursor::End);

    //setup rectifier
    threadRectifier = new QThread();
    rectifier = new Rectifier();
    rectifier->setCalibrationFile(settings->readCalibFilePath());

    //setup stereomatcher
    threadStereoMatcher = new QThread();

    switch(settings->readAlgorithm())
    {
        case Algorithm::BM_cpu_pure:
            stereoMatcher = new StereoBMcpu(MatcherMode::pure);
        break;

        case Algorithm::BM_cpu_filter:
            stereoMatcher = new StereoBMcpu(MatcherMode::filter);
        break;

        case Algorithm::BM_cuda_pure:
            stereoMatcher = new StereoBMcuda(MatcherMode::pure);
        break;

        case Algorithm::BM_cuda_filter:
        stereoMatcher = new StereoBMcuda(MatcherMode::filter);
        break;

        case Algorithm::SGBM_cpu_pure:
            stereoMatcher= new StereoSGBMcpu(MatcherMode::pure);
        break;

        case Algorithm::SGBM_cpu_filter:
            stereoMatcher= new StereoSGBMcpu(MatcherMode::filter);
        break;

        case Algorithm::BP_cuda_pure:
            stereoMatcher = new StereoBPcuda(MatcherMode::pure);
        break;

        case Algorithm::BP_cuda_filter:
            stereoMatcher = new StereoBPcuda(MatcherMode::filter);
        break;

        case Algorithm::CSBP_cuda_pure:
            stereoMatcher = new StereoCSBPcuda(MatcherMode::pure);
        break;

        case Algorithm::CSBP_cuda_filter:
            stereoMatcher = new StereoCSBPcuda(MatcherMode::filter);
        break;
    }

    //connect signals and slots

    //threads ----> workers
    connect(threadSourceReader, SIGNAL(started()), sourceReader, SLOT(receiveStart()));
    connect(threadSourceReader, SIGNAL(finished()), sourceReader, SLOT(deleteLater()));
    connect(threadRectifier, SIGNAL(finished()), rectifier, SLOT(deleteLater()));
    connect(threadStereoMatcher, SIGNAL(finished()), stereoMatcher, SLOT(deleteLater()));
    connect(threadFileWriter, SIGNAL(finished()), fileWriter, SLOT(deleteLater()));

    //image processing chain: sourceReader ---> rectifier ---> stereoMatcher ---> fileWriter
    connect(sourceReader, SIGNAL(sendFrames(cv::Mat, cv::Mat)), rectifier, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(sourceReader, SIGNAL(sendFrameSize(cv::Size)), fileWriter, SLOT(receiveFrameSize(cv::Size)), Qt::DirectConnection);
    connect(rectifier, SIGNAL(sendFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat)), stereoMatcher, SLOT(receiveFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat)));
    connect(stereoMatcher, SIGNAL(sendDisparity(cv::Mat)), fileWriter, SLOT(receiveFrame(cv::Mat)));
    connect(fileWriter, SIGNAL(sendJobDone()), sourceReader, SLOT(receiveJobDone()));

    //start signal
    connect(this, SIGNAL(sendStartProcessing()), fileWriter, SLOT(receiveStartWriting()));

    //end signal
    connect(sourceReader, SIGNAL(sendEnd()), this, SLOT(receiveEnd()));
    connect(sourceReader, SIGNAL(sendEnd()), fileWriter, SLOT(receiveStopWriting()), Qt::DirectConnection);

    //move workers to threads and start
    sourceReader->moveToThread(threadSourceReader);
    rectifier->moveToThread(threadRectifier);
    stereoMatcher->moveToThread(threadStereoMatcher);
    fileWriter->moveToThread(threadFileWriter);

    threadFileWriter->start();
    threadStereoMatcher->start();
    threadRectifier->start();
    threadSourceReader->start();


    emit sendStartProcessing();
}

void WidgetDisparity::receiveEnd()
{
    if(iter != filesVector.end()) grabNextFiles();
    else
    {
        QDateTime currentTime = QDateTime::currentDateTime();
        status.append(currentTime.toString("[hh:mm:ss] ")).append("Zakończono przetwarzanie. \n");
        ui->textBrowserStatus->setText(status);
        stopThreads();
    }
}
