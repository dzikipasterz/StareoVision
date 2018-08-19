#include "widgetsettings.h"
#include "ui_widgetsettings.h"

widgetSettings::widgetSettings(AppSettings sett) :
    ui(new Ui::widgetSettings)
{
    //AppWidget
    settings = sett;

    //widgetSettings
    ui->setupUi(this);
    ui->leftCamera->setScaledContents(true);
    ui->rightCamera->setScaledContents(true);
    ui->leftCameraId->setValue(settings.readLeftCameraId());
    ui->rightCameraId->setValue(settings.readRightCameraId());
    ui->labelSavePictDir->setText(settings.readCalibPictSavePath());
    ui->labelSaveMovDir->setText(settings.readMovFilesDir());
    ui->labelCalibFilesDir->setText(settings.readCalibFilesDir());
    ui->labelCalibFile->setText(settings.readCalibFilePath());

    startup();
}

widgetSettings::~widgetSettings()
{
    delete ui;
}

void widgetSettings::startup()
{ 
    AppWidget::startup();
    AppWidget::initTimer();
    AppWidget::initCamera(settings.readLeftCameraId(), settings.readRightCameraId());

    connect(this,SIGNAL(sendStereoCameraSetup(const int, const int)),AppWidget::camera,SLOT(receiveSetup(const int, const int)));
    connect(AppWidget::camera,SIGNAL(sendCameraStatus(bool, bool)),this,SLOT(receiveCameraStatus(bool, bool)));
    connect(AppWidget::camera,SIGNAL(sendFrames(cv::Mat, cv::Mat)),this,SLOT(receiveFrames(cv::Mat, cv::Mat)));
    connect(AppWidget::camera, SIGNAL(sendJobDone()), AppWidget::intervalRegulator, SLOT(receiveJobDone()));

    AppWidget::startCamera();
    AppWidget::startTimer();
}

void widgetSettings::displayCameraStatus(bool status, QLabel * labelStatus)
{
    if(!status)
    {
        labelStatus->setText("Kamera włączona");
    }
    else
    {
        labelStatus->setText("Brak połączenia z kamerą.");
    }
}

void widgetSettings::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    displayFrame(leftFrame, ui->leftCamera);
    displayFrame(rightFrame, ui->rightCamera);
}

void widgetSettings::receiveCameraStatus(bool leftCameraStatus, bool rightCameraStatus)
{
    displayCameraStatus(leftCameraStatus, ui->labelLeftCameraStatus);
    displayCameraStatus(rightCameraStatus, ui->labelRightCameraStatus);
}

void widgetSettings::on_leftCameraId_valueChanged(int leftCameraId)
{
    settings.setLeftCameraId(leftCameraId);
    emit sendSettingsChanged(settings);
    emit sendStereoCameraSetup(settings.readLeftCameraId(), settings.readRightCameraId());
}

void widgetSettings::on_rightCameraId_valueChanged(int rightCameraId)
{
    settings.setRightCameraId(rightCameraId);
    emit sendSettingsChanged(settings);
    emit sendStereoCameraSetup(settings.readLeftCameraId(),settings.readRightCameraId());
}

void widgetSettings::on_pushButtonSelectPicDir_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"Wybierz folder dla zdjęć kalibracyjnych",settings.readCalibPictSavePath(),QFileDialog::ShowDirsOnly);

    if(!dir.isNull())
    {
        dir.append("/");
        settings.setCalibPictsSavePath(dir);
        emit sendSettingsChanged(settings);
        ui->labelSavePictDir->setText(dir);
    }
}

void widgetSettings::on_pushButtonSelectCalibFile_clicked()
{
    QString calibFile = QFileDialog::getOpenFileName(this,"Wybierz plik kalibracyjny",settings.readCalibFilePath(),tr("Plik kalibracyjny (*.calib)"));

    if(!calibFile.isNull())
    {
        settings.setCalibFilePath(calibFile);
        emit sendSettingsChanged(settings);
        ui->labelCalibFile->setText(calibFile);
    }
}

void widgetSettings::on_pushButtonSelectMovDir_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"Wybierz folder dla nagrywanych filmów",settings.readMovFilesDir(),QFileDialog::ShowDirsOnly);

    if(!dir.isNull())
    {
        dir.append("/");
        settings.setMovFilesDir(dir);
        emit sendSettingsChanged(settings);
        ui->labelSaveMovDir->setText(dir);
    }
}

void widgetSettings::on_pushButtonSelectCalibDir_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,"Wybierz folder dla plików kalibracyjnych",settings.readCalibFilesDir(),QFileDialog::ShowDirsOnly);

    if(!dir.isNull())
    {
        dir.append("/");
        settings.setCalibFilesDir(dir);
        emit sendSettingsChanged(settings);
        ui->labelCalibFilesDir->setText(dir);
    }
}
