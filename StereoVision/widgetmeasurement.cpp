#include "widgetmeasurement.h"
#include "ui_widgetmeasurement.h"

widgetMeasurement::widgetMeasurement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetMeasurement)
{
    ui->setupUi(this);
}

widgetMeasurement::~widgetMeasurement()
{
    delete ui;
}
