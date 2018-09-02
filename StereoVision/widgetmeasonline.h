#ifndef WIDGETMEASONLINE_H
#define WIDGETMEASONLINE_H

#include <QWidget>
#include <appsettings.h>
#include <appwidget.h>
#include <rectifier.h>
#include <stereobm.h>
#include <stereosgbm.h>

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
    void receivePixelValue(int val);

private:
    Ui::widgetMeasOnline *ui;
    QThread *threadRectifier, *threadStereoMatcher;
    Rectifier *rectifier;
    StereoMatcher *stereoMatcher;
    DepthDisplay *disparityDisplay;

};

#endif // WIDGETMEASONLINE_H
