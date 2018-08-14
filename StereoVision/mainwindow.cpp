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

void MainWindow::showMeasurementWidget()
{
    //layout()->removeWidget(Ui::widgetPanel);
    //ui->centralWidget->layout()->addWidget(Ui::widgetPanel);
    Ui::widgetPanel->deleteLater();
    Ui::widgetPanel = new widgetMeasurement();
    //QMainWindow::layout()->addWidget(Ui::widgetPanel);
    ui->centralWidget->layout()->addWidget(Ui::widgetPanel);
    //Ui::widgetPanel->setGeometry(150,50,861,681);
}

void MainWindow::showSettingsWidget()
{
    //layout()->removeWidget(Ui::widgetPanel);
    //ui->centralWidget->layout()->addWidget(Ui::widgetPanel);
    Ui::widgetPanel->deleteLater();
    Ui::widgetPanel = new widgetSettings();
    //QMainWindow::layout()->addWidget(Ui::widgetPanel);
    ui->centralWidget->layout()->addWidget(Ui::widgetPanel);
    //Ui::widgetPanel->setGeometry(150,50,861,681);
}

void MainWindow::showCalibrationWidget()
{
    //layout()->removeWidget(Ui::widgetPanel);
    //ui->centralWidget->layout()->addWidget(Ui::widgetPanel);
    Ui::widgetPanel->deleteLater();
    Ui::widgetPanel = new widgetCalibration();
    //QMainWindow::layout()->addWidget(Ui::widgetPanel);
    ui->centralWidget->layout()->addWidget(Ui::widgetPanel);
    //Ui::widgetPanel->setGeometry(150,50,861,681);
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
