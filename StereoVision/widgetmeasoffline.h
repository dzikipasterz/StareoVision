#ifndef WIDGETMEASOFFLINE_H
#define WIDGETMEASOFFLINE_H

#include <QWidget>
#include <QImage>
#include <appwidget.h>
#include <appsettings.h>
#include <depthdisplay.h>

namespace Ui {
class widgetMeasOffline;
}

class widgetMeasOffline : public AppWidget
{
    Q_OBJECT

public:
    explicit widgetMeasOffline(AppSettings sett);
    ~widgetMeasOffline();

private:
    Ui::widgetMeasOffline *ui;
    DepthDisplay *depthDisplay;
};

#endif // WIDGETMEASOFFLINE_H
