#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(on_pushButtonInfo_clicked(),on_actionO_programie_triggered());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAppInfo()
{
    info Info;
    Info.setModal(true);
    centerChild(this, &Info);
    Info.exec();
}

void MainWindow::on_pushButtonInfo_clicked()
{
   showAppInfo();
}

void MainWindow::on_actionO_programie_triggered()
{
   showAppInfo();
}
