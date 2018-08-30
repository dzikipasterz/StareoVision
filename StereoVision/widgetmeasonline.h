#ifndef WIDGETMEASONLINE_H
#define WIDGETMEASONLINE_H

#include <QWidget>
#include <appsettings.h>
#include <appwidget.h>

namespace Ui {
class widgetMeasOnline;
}

class widgetMeasOnline : public AppWidget
{
    Q_OBJECT

public:
    explicit widgetMeasOnline(AppSettings *sett);
    ~widgetMeasOnline();

private:
    Ui::widgetMeasOnline *ui;
};

#endif // WIDGETMEASONLINE_H
