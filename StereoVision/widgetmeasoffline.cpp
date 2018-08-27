#include "widgetmeasoffline.h"
#include "ui_widgetmeasoffline.h"

widgetMeasOffline::widgetMeasOffline(AppSettings sett) :
    ui(new Ui::widgetMeasOffline),
    depthDisplay(new DepthDisplay())
{
    ui->setupUi(this);
    settings = sett;
    ui->gridLayout->addWidget(depthDisplay,0,0);
    //ui->mainLayout->addWidget(depthDisplay);
    depthDisplay->setFrameShape(QFrame::Box);

}

widgetMeasOffline::~widgetMeasOffline()
{
    delete ui;
    delete depthDisplay;
}
