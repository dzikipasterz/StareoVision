#ifndef WIDGETMEASONLINE_H
#define WIDGETMEASONLINE_H

#include <QWidget>
#include <appsettings.h>
#include <appwidget.h>
#include <rectifier.h>
#include <stereobmcpu.h>
#include <stereosgbmcpu.h>
#include <stereobpcuda.h>
#include <stereocsbpcuda.h>
#include <stereobmcuda.h>


namespace Ui {
class widgetMeasOnline;
}

class widgetMeasOnline : public AppWidget
{
    Q_OBJECT

public:
    explicit widgetMeasOnline(AppSettings *sett);
    ~widgetMeasOnline();

public slots:
    void receiveDisparity(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat disparity);
    void receiveDistance(double distance);

private:
    Ui::widgetMeasOnline *ui;
    QThread *threadRectifier, *threadStereoMatcher;
    Rectifier *rectifier;
    StereoMatcher *stereoMatcher;
    DepthDisplay *disparityDisplay;

};

#endif // WIDGETMEASONLINE_H
