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
    threadStereoMatcher(nullptr),
    isVideo(false),
    mode(fromRaw)
{
    ui->setupUi(this);
    //store app settings ref
    settings = sett;

    //setup GUI
    ui->labelLeftDisplay->setScaledContents(true);
    ui->labelRightDisplay->setScaledContents(true);
    ui->pushButtonStart->setText("Start");
    ui->pushButtonStart->toggled(false);
    ui->comboBoxMode->addItem("Para obrazów stereoskopowych");
    ui->comboBoxMode->addItem("Mapa dysparycji");

    //setup depthDisplay widget
    connect(depthDisplay, SIGNAL(sendDistance(double)), this, SLOT(receiveDistance(double)));
    connect(depthDisplay, SIGNAL(sendCoords(int, int)), this, SLOT(receiveCoords(int,int)));
    connect(depthDisplay, SIGNAL(sendFPS(double)), this, SLOT(receiveFPS(double)));
    connect(this, SIGNAL(sendCoords(int, int)), depthDisplay, SLOT(receiveCoords(int, int)));
    ui->gridLayout->addWidget(depthDisplay,0,0);
    depthDisplay->setFrameShape(QFrame::Box);
    depthDisplay->setScaledContents(true);
    depthDisplay->setDispToDistMat(settings->readDispToDepthMap());

}


widgetMeasOffline::~widgetMeasOffline()
{
    //safely stop running threads, delete GUI and close opened file references
    stopThreads();
    delete ui;
    delete depthDisplay;
    closeFile();
}

void widgetMeasOffline::setupMeasurement()
{
    //stop all curently running threads
    stopThreads();

    //create threads for workers
    threadSourceReader = new QThread();
    threadRectifier = new QThread();
    threadStereoMatcher = new QThread();

    //----------------------------------------------------------------------------------------------------------------

    setupSourceReader();
    //set sourceReader's files to read
    //sourceReader->setSourcePaths(ui->labelSourceLeft->text(), ui->labelSourceRight->text());

    //----------------------------------------------------------------------------------------------------------------

    //setup rectifier
    rectifier = new Rectifier();
    rectifier->setCalibrationFile(settings->readCalibFilePath());

    //----------------------------------------------------------------------------------------------------------------

    //setup stereoMatcher according to selected algorithm
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

    //----------------------------------------------------------------------------------------------------------------

    //threads <---------> workers
    connect(threadSourceReader, SIGNAL(finished()), sourceReader, SLOT(deleteLater()));
    connect(threadRectifier, SIGNAL(finished()), rectifier, SLOT(deleteLater()));
    connect(threadStereoMatcher, SIGNAL(finished()), stereoMatcher, SLOT(deleteLater()));

    //----------------------------------------------------------------------------------------------------------------

    //this <-------> sourceReader
    connect(this, SIGNAL(sendStartMeas()), sourceReader, SLOT(receiveStart()));
    connect(this, SIGNAL(sendStopMeas()), sourceReader, SLOT(receiveStop()));

    //image processing chain: sourceReader ---> rectifier ---> stereoMatcher ---> this
    connect(sourceReader, SIGNAL(sendFrames(cv::Mat, cv::Mat)), rectifier, SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(rectifier, SIGNAL(sendFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat)), stereoMatcher, SLOT(receiveFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat)));
    connect(stereoMatcher, SIGNAL(sendDisparityAndRaw(cv::Mat, cv::Mat, cv::Mat)), this, SLOT(receiveDisparityAndRaw(cv::Mat, cv::Mat, cv::Mat)));

    //feedback to sourceReader about finished job
    connect(stereoMatcher, SIGNAL(sendJobDone()), sourceReader, SLOT(receiveJobDone()));

    //----------------------------------------------------------------------------------------------------------------

    //move workers to threads and start
    sourceReader->moveToThread(threadSourceReader);
    rectifier->moveToThread(threadRectifier);
    stereoMatcher->moveToThread(threadStereoMatcher);

    threadStereoMatcher->start();
    threadRectifier->start();
    threadSourceReader->start();

    emit sendStartMeas();
}

void widgetMeasOffline::readDisparity()
{
    //stop all curently running threads
    stopThreads();

    //setup source reader
    threadSourceReader = new QThread();
    setupSourceReader();

    //connect signals and slots
    connect(threadSourceReader, SIGNAL(finished()), sourceReader, SLOT(deleteLater()));
    connect(sourceReader, SIGNAL(sendFrame(cv::Mat)), this, SLOT(receiveDisparity(cv::Mat)));
    connect(this, SIGNAL(sendStartMeas()), sourceReader, SLOT(receiveStart()));
    connect(this, SIGNAL(sendStopMeas()), sourceReader, SLOT(receiveStop()));
    connect(this, SIGNAL(sendJobDone()), sourceReader, SLOT(receiveJobDone()));

    emit sendStartMeas();
}

void widgetMeasOffline::setupSourceReader()
{
    //check source files extensions and run correct source reader
    if(mode == fromRaw)
    {
        QString leftExt = leftSourcePath.split(".").at(1);
        QString rightExt = rightSourcePath.split(".").at(1);

        if((leftExt == rightExt) && (leftExt == "avi"))
        {
            sourceReader = new VideoReader(SourceReaderMode(mode));
            isVideo = true;
        }
        else if((leftExt == rightExt) && (leftExt == "jpg"))
        {
            sourceReader = new ImageReader(SourceReaderMode(mode));
            isVideo = false;
        }

        sourceReader->setSourcePaths(leftSourcePath, rightSourcePath);
    }

    if(mode == fromFile)
    {
        QString dispExt = disparityPath.split(".").at(1);
        if(dispExt == "avi")
        {
            sourceReader = new VideoReader(SourceReaderMode(mode));
            isVideo = true;
        }
        else if(dispExt == "jpg")
        {
            sourceReader = new ImageReader(SourceReaderMode(mode));
            isVideo = false;
        }
        sourceReader->setSourcePaths(disparityPath);
    }
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
    closeFile(); //close curently opened references
    writeToFile = true;

    //create new file with name including current timestamp
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


void widgetMeasOffline::receiveDisparityAndRaw(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat disparity)
{
    //display disparity map
    displayDisparity(disparity, depthDisplay);

    //if disparity has been calculated from raw images, show them. If it comes from a file with disparity already
    //calculated - do not do anything

    switch(mode)
    {
        case fromRaw:
            displayFrame(leftFrameRaw, ui->labelLeftDisplay);
            displayFrame(rightFrameRaw, ui->labelRightDisplay);
            break;

        case fromFile:
            break;
    }
}

void widgetMeasOffline::receiveDisparity(cv::Mat disparity)
{
    displayDisparity(disparity, depthDisplay);
    emit sendJobDone();
}

//receive distance from currently chosen point on depthDisplay
void widgetMeasOffline::receiveDistance(double distance)
{
    ui->doubleSpinBoxDistance->setValue(distance);
    if(writeToFile)
    {
        output << QString::number(distance).append(";").append(QString::number(FPS).append(";")) << endl;
    }
}

//receive FPS from depthDisplay
void widgetMeasOffline::receiveFPS(double fps)
{
    FPS = fps;
    ui->doubleSpinBoxFPS->setValue(fps);
}

//receive coords (in pixels of not-scaled disparity map) of currently chosen point.
void widgetMeasOffline::receiveCoords(int x, int y)
{
    ui->spinBoxX->setValue(x);
    ui->spinBoxY->setValue(y);
}

//change source of left image/video
void widgetMeasOffline::on_pushButtonLeftSource_clicked()
{
    leftSourcePath = QFileDialog::getOpenFileName(nullptr, "Wybierz źródło lewego obrazu", lastPath);
    ui->labelSourceLeft->setText(leftSourcePath);
    lastPath = leftSourcePath;
}

//change source of right image/video
void widgetMeasOffline::on_pushButtonRightSource_clicked()
{
    rightSourcePath = QFileDialog::getOpenFileName(nullptr, "Wybierz źródło prawego obrazu", lastPath);
    ui->labelSourceRight->setText(rightSourcePath);
    lastPath = rightSourcePath;
}

void widgetMeasOffline::on_pushButtonDisparity_clicked()
{
    disparityPath = QFileDialog::getOpenFileName(nullptr, "Wybierz mapę dysparycji", lastPath);
    ui->labelDispSource->setText(disparityPath);
    lastPath = disparityPath;
}


//change x coordinate of point chosen in depthDisplay
void widgetMeasOffline::on_spinBoxX_valueChanged(int x)
{
    emit sendCoords(x, ui->spinBoxY->value());
}

//change y coordinate of point chosen in depthDisplay
void widgetMeasOffline::on_spinBoxY_valueChanged(int y)
{
    emit sendCoords(ui->spinBoxX->value(), y);
}

//start/stop writing distance and fps to a file
void widgetMeasOffline::on_pushButtonWrite_toggled(bool write)
{
    if(write)
    {
        openFile();
    }
    else closeFile();

}

//start/stop a measurement
void widgetMeasOffline::on_pushButtonStart_toggled(bool checked)
{

    if(checked)
    {
        switch(mode)
        {
        //if input files are contain non-processed image
        case fromRaw:
            setupMeasurement();
            break;

        //if input file contains disparity map
        case fromFile:
            readDisparity();
            break;
        }

        //change boolean text to "Stop" if a video has been launched. Otherwise (image) untoggle the button.
        if(isVideo) ui->pushButtonStart->setText("Stop");
        else ui->pushButtonStart->toggled(false);
    }

    else
    {
        emit sendStopMeas();
        ui->pushButtonStart->setText("Start");
    }
}

void widgetMeasOffline::on_comboBoxMode_activated(int index)
{
    mode = disparityMode(index);
}

