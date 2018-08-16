#include "widgetcalibration.h"
#include "ui_widgetcalibration.h"

widgetCalibration::widgetCalibration(AppSettings sett) :
    ui(new Ui::widgetCalibration)
{
    //AppWidget
    settings = sett;

    //widgetSettings
    ui->setupUi(this);
}

widgetCalibration::~widgetCalibration()
{
    delete ui;
}
