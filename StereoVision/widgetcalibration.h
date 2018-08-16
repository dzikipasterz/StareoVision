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
    explicit widgetCalibration(AppSettings sett);
    ~widgetCalibration();

public slots:

private:
    Ui::widgetCalibration *ui;
    QThread * threadStereoCamera;
    QThread * threadCornersFinder;
    QThread * threadTimer;


    void setup();
};

#endif // WIDGETCALIBRATION_H
