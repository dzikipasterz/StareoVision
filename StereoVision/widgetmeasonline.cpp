#include "widgetmeasonline.h"
#include "ui_widgetmeasonline.h"

widgetMeasOnline::widgetMeasOnline(AppSettings *sett) :
    ui(new Ui::widgetMeasOnline)
{
    ui->setupUi(this);
    settings = sett;
}

widgetMeasOnline::~widgetMeasOnline()
{
    delete ui;
}
