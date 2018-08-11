#include "widgetsettings.h"
#include "ui_widgetsettings.h"

widgetSettings::widgetSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetSettings)
{
    ui->setupUi(this);
}

widgetSettings::~widgetSettings()
{
    delete ui;
}
