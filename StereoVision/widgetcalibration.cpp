#include "widgetcalibration.h"
#include "ui_widgetcalibration.h"

widgetCalibration::widgetCalibration(QWidget *parent) :
    AppWidget (parent),
    ui(new Ui::widgetCalibration)
{
    ui->setupUi(this);
}

widgetCalibration::~widgetCalibration()
{
    delete ui;
    //AppWidget::~AppWidget();
}
