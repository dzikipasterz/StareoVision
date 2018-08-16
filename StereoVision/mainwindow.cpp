#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    baseSize = this->size();
    settings = readSettingsFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

AppSettings MainWindow::readSettingsFile()
{
    AppSettings sett;
    sett.setLeftCameraId(0);
    sett.setRightCameraId(1);
    return sett;
}

void MainWindow::closeApplication()
{
    QApplication::closeAllWindows();
}

void MainWindow::receiveAppSettings(AppSettings sett)
{
    settings = sett;
}

void MainWindow::showAppInfo()
{
    info Info;
    Info.setModal(true);
    centerChild(this, &Info);
    Info.exec();
}

void MainWindow::showCloseConfirmation()
{
    closeConfirm closeConfirmation;
    closeConfirmation.setModal(true);
    centerChild(this,&closeConfirmation);
    connect(&closeConfirmation,SIGNAL(closeApplication()),this,SLOT(closeApplication()));
    closeConfirmation.exec();
}

void MainWindow::initPanelWidget()
{
    if(widgetPanel != nullptr)
        ui->centralWidget->layout()->removeWidget(widgetPanel);
    widgetPanel->deleteLater();
}


void MainWindow::showMeasurementWidget()
{
    initPanelWidget();
    widgetPanel = new widgetMeasurement(settings);
    ui->centralWidget->layout()->addWidget(widgetPanel);
}

void MainWindow::showSettingsWidget()
{
    initPanelWidget();
    widgetPanel = new widgetSettings(settings);
    connect(widgetPanel, SIGNAL(sendSettingsChanged(AppSettings)), this, SLOT(receiveAppSettings(AppSettings)));
    ui->centralWidget->layout()->addWidget(widgetPanel);
}

void MainWindow::showCalibrationWidget()
{
    initPanelWidget();
    widgetPanel = new widgetCalibration(settings);
    ui->centralWidget->layout()->addWidget(widgetPanel);
}

void MainWindow::on_pushButtonInfo_clicked()
{
   showAppInfo();
}

void MainWindow::on_actionO_programie_triggered()
{
    showAppInfo();
}

void MainWindow::on_pushButtonWyjscie_clicked()
{
    showCloseConfirmation();
}

void MainWindow::on_actionZako_cz_triggered()
{
    showCloseConfirmation();
}

void MainWindow::on_pushButtonPomiarOnline_clicked()
{
    showMeasurementWidget();
}

void MainWindow::on_pushButtonUstawienia_clicked()
{
    showSettingsWidget();
}

void MainWindow::on_pushButtonKalibracja_clicked()
{
    showCalibrationWidget();
}
