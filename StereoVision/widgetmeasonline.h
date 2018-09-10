#ifndef WIDGETMEASONLINE_H
#define WIDGETMEASONLINE_H

#include <QWidget>
#include <QTextStream>
#include <QDateTime>
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

signals:
    void sendCoords(int x, int y);

public slots:
    void receiveDisparity(cv::Mat lFrameRaw, cv::Mat rFrameRaw, cv::Mat disp);
    void receiveDistance(double distance);
    void receiveCoords(int x, int y);

private slots:
    void on_spinBoxX_valueChanged(int arg1);

    void on_spinBoxY_valueChanged(int arg1);

    void on_pushButtonWrite_toggled(bool write);

private:
    Ui::widgetMeasOnline *ui;
    QThread *threadRectifier, *threadStereoMatcher;
    QFile results;
    QTextStream output;
    bool writeToFile;
    Rectifier *rectifier;
    StereoMatcher *stereoMatcher;
    DepthDisplay *disparityDisplay;

    void openFile();
    void closeFile();
};

#endif // WIDGETMEASONLINE_H
