#ifndef WIDGETCALIBRATION_H
#define WIDGETCALIBRATION_H

#include <QWidget>
#include <appwidget.h>

namespace Ui {
class widgetCalibration;
}

class widgetCalibration : public AppWidget
{
    Q_OBJECT

public:
    explicit widgetCalibration(QWidget *parent = nullptr);
    ~widgetCalibration();

private:
    Ui::widgetCalibration *ui;
};

#endif // WIDGETCALIBRATION_H
