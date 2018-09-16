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
        sourcesDir = dir;
        ui->labelSourcesDir->setText(dir);
    }

}

//select a directory to save disparity images / videos
void WidgetDisparity::on_pushButtonResults_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"Wybierz folder dla wyników", lastDir,QFileDialog::ShowDirsOnly);
    lastDir = dir;
    resultsDir = dir;
    ui->labelResultsDir->setText(dir);
}

//start calculating disparity
void WidgetDisparity::on_pushButtonStart_clicked()
{
    status = "";
    dir = ui->labelSourcesDir->text();

    QDir directory(ui->labelSourcesDir->text());
    QStringList filter;
    filter.append("*.jpg");
    filter.append("*.avi");
    directory.setNameFilters(filter);
    directory.setSorting(QDir::Name);
    QStringList files = directory.entryList();

    for(int i = 0; i < files.size(); i++)
    {
        filesVector.push_back(files.at(i));
    }

    filesVector.clear();
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
    iter++;
    leftSource = dir.append(*iter);
    iter++;
    rightSource = dir.append(*iter);

    QDateTime currentTime = QDateTime::currentDateTime();
    status.append(currentTime.toString("[hh:mm:ss] ")).append("Analizowany plik ").append(leftSource).append("\n");
    status.append(currentTime.toString("[hh:mm:ss] ")).append("Analizowany plik ").append(rightSource).append("\n");
    ui->textBrowserStatus->setText(status);
    ui->textBrowserStatus->moveCursor(QTextCursor::End);

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

    //setup rectifier
    threadRectifier = new QThread();
    rectifier = new Rectifier();
    rectifier->setCalibrationFile(settings->readCalibFilePath());

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

    //connect signals and slots

    //threads ----> workers
    connect(threadSourceReader, SIGNAL(started()), sourceReader, SLOT(receiveStart()));
    connect(threadSourceReader, SIGNAL(finished()), sourceReader, SLOT(deleteLater()));
    connect(threadRectifier, SIGNAL(finished()), rectifier, SLOT(deleteLater()));
    connect(threadStereoMatcher, SIGNAL(finished()), stereoMatcher, SLOT(deleteLater()));
    connect(threadFileWriter, SIGNAL(finished()), fileWriter, SLOT(deleteLater()));

    //image processing chain: sourceReader ---> rectifier ---> stereoMatcher ---> fileWriter
    connect(sourceReader, SIGNAL(sendFrames(cv::Mat, cv::Mat)), rectifier, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(rectifier, SIGNAL(sendFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat)), stereoMatcher, SLOT(receiveFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat)));
    connect(stereoMatcher, SIGNAL(sendDisparity(cv::Mat)), fileWriter, SLOT(receiveFrame(cv::Mat)));
    connect(fileWriter, SIGNAL(sendJobDone()), sourceReader, SLOT(receiveJobDone()));
}
