#ifndef WIDGETMEASUREMENT_H
#define WIDGETMEASUREMENT_H

#include <QWidget>
#include <appwidget.h>

namespace Ui {
class widgetMeasurement;
}

class widgetMeasurement : public AppWidget
{
    Q_OBJECT

public:
    explicit widgetMeasurement(AppSettings sett);
    ~widgetMeasurement();

private:
    Ui::widgetMeasurement *ui;
};

#endif // WIDGETMEASUREMENT_H
