#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    if(Ui::widgetPanel != nullptr)
        ui->centralWidget->layout()->removeWidget(Ui::widgetPanel);
    Ui::widgetPanel->deleteLater();
    Ui::widgetPanel = new widgetSettings();
}


void MainWindow::showMeasurementWidget()
{
    initPanelWidget();
    Ui::widgetPanel = new widgetMeasurement();
    ui->centralWidget->layout()->addWidget(Ui::widgetPanel);
}

void MainWindow::showSettingsWidget()
{
    initPanelWidget();
    Ui::widgetPanel = new widgetSettings();
    ui->centralWidget->layout()->addWidget(Ui::widgetPanel);
}

void MainWindow::showCalibrationWidget()
{
    initPanelWidget();
    Ui::widgetPanel = new widgetCalibration();
    ui->centralWidget->layout()->addWidget(Ui::widgetPanel);
}

void resizeEvent(QResizeEvent * event)
{

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

void MainWindow::on_pushButtonPomiar_clicked()
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
