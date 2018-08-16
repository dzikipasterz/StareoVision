#include "widgetcalibration.h"
#include "ui_widgetcalibration.h"

widgetCalibration::widgetCalibration(AppSettings sett) :
    ui(new Ui::widgetCalibration)
{
    //AppWidget
    settings = sett;

    //widgetCalibration
    ui->setupUi(this);
    ui->lefCamera->setScaledContents(true);
    ui->rightCamera->setScaledContents(true);

}

widgetCalibration::~widgetCalibration()
{
    delete ui;
}
