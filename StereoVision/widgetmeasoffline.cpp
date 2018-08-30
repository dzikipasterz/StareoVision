#include "widgetmeasoffline.h"
#include "ui_widgetmeasoffline.h"

widgetMeasOffline::widgetMeasOffline(AppSettings *sett) :
    ui(new Ui::widgetMeasOffline),
    depthDisplay(new DepthDisplay())
{
    ui->setupUi(this);
    settings = sett;

    connect(depthDisplay, SIGNAL(sendPixelArrCoord(int, int)), this, SLOT(receivePixelArrCoord(int, int)));

    ui->gridLayout->addWidget(depthDisplay,0,0);
    depthDisplay->setFrameShape(QFrame::Box);

}

widgetMeasOffline::~widgetMeasOffline()
{
    delete ui;
    delete depthDisplay;
}


void widgetMeasOffline::receivePixelArrCoord(int x, int y)
{
    ui->spinBox->setValue(x);
    ui->spinBox_2->setValue(y);
}
