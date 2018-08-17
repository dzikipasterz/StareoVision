#ifndef WIDGETCALIBRATION_H
#define WIDGETCALIBRATION_H

#include <QWidget>
#include <appwidget.h>
#include <cornersfinder.h>

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
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);

protected:
    void startup();

private:
    Ui::widgetCalibration *ui;
    QThread * threadCornersFinder;
    CornersFinder * cornersFinder;
};

#endif // WIDGETCALIBRATION_H
