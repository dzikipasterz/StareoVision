#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    widgetPanel(nullptr)
{
    ui->setupUi(this);
    baseSize = this->size();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::closeApplication()
{
    QApplication::closeAllWindows();
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
    {
        ui->centralWidget->layout()->removeWidget(widgetPanel);
        widgetPanel->deleteLater();
    }
}


void MainWindow::showMeasurementOfflineWidget()
{
    initPanelWidget();
    widgetPanel = new widgetMeasOffline(&settings);
    ui->centralWidget->layout()->addWidget(widgetPanel);
}

void MainWindow::showMeasurementOnlineWidget()
{
    initPanelWidget();
    widgetPanel = new widgetMeasOnline(&settings);
    ui->centralWidget->layout()->addWidget(widgetPanel);
}

void MainWindow::showSettingsWidget()
{
    initPanelWidget();
    widgetPanel = new widgetSettings(&settings);
    ui->centralWidget->layout()->addWidget(widgetPanel);
}

void MainWindow::showCalibrationWidget()
{
    initPanelWidget();
    widgetPanel = new widgetCalibration(&settings);
    ui->centralWidget->layout()->addWidget(widgetPanel);
}

void MainWindow::showRecordWidget()
{
    initPanelWidget();
    widgetPanel = new widgetRecord(&settings);
    ui->centralWidget->layout()->addWidget(widgetPanel);
}

void MainWindow::showDisparityWidget()
{
    initPanelWidget();
    widgetPanel = new WidgetDisparity(&settings);
    ui->centralWidget->layout()->addWidget(widgetPanel);
}

void MainWindow::on_pushButtonInfo_clicked()
{
   showAppInfo();
}

void MainWindow::on_actionAbout_triggered()
{
    showAppInfo();
}

void MainWindow::on_pushButtonExit_clicked()
{
    showCloseConfirmation();
}

void MainWindow::on_actionExit_triggered()
{
    showCloseConfirmation();
}

void MainWindow::on_pushButtonMeasOnline_clicked()
{
    showMeasurementOnlineWidget();
}

void MainWindow::on_pushButtonSettings_clicked()
{
    showSettingsWidget();
}

void MainWindow::on_pushButtonCalibration_clicked()
{
    showCalibrationWidget();
}

void MainWindow::on_pushButtonRecord_clicked()
{
    showRecordWidget();
}

void MainWindow::on_pushButtonMeasOffline_clicked()
{
    showMeasurementOfflineWidget();
}

void MainWindow::on_pushButtonDisparity_clicked()
{
    showDisparityWidget();
}
