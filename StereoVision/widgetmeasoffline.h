#ifndef WIDGETMEASOFFLINE_H
#define WIDGETMEASOFFLINE_H

#include <QWidget>
#include <QImage>
#include <QFileDialog>
#include <QDateTime>
#include <QTextStream>
#include <appwidget.h>
#include <appsettings.h>
#include <depthdisplay.h>
#include <imagereader.h>
#include <videoreader.h>
#include <rectifier.h>
#include <stereomatcher.h>
#include <stereobmcpu.h>
#include <stereobmcuda.h>
#include <stereosgbmcpu.h>
#include <stereobpcuda.h>
#include <stereocsbpcuda.h>
#include <postfilter.h>
#include <disparityconverter.h>

namespace Ui {
class widgetMeasOffline;
}

class widgetMeasOffline : public AppWidget
{
    Q_OBJECT

public:
    explicit widgetMeasOffline(AppSettings *sett);
    ~widgetMeasOffline();

signals:
    void sendStartMeas();
    void sendStopMeas();
    void sendCoords(int x, int y);

public slots:
    void receiveDisparity(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat disparity);
    void receiveDistance(double distance);
    void receiveCoords(int x, int y);
    void receiveFPS(double fps);

private slots:
    void on_pushButtonLeftSource_clicked();

    void on_pushButtonRightSource_clicked();

    void on_spinBoxX_valueChanged(int x);

    void on_spinBoxY_valueChanged(int y);

    void on_pushButtonWrite_toggled(bool write);

    void on_pushButtonStart_toggled(bool checked);

private:
    Ui::widgetMeasOffline *ui;
    DepthDisplay *depthDisplay;
    QString leftSourcePath;
    QString rightSourcePath;
    QString lastPath;
    QFile results;
    QTextStream output;
    bool writeToFile;
    double FPS;
    SourceReader *sourceReader;
    Rectifier *rectifier;
    StereoMatcher *stereoMatcher;
    QThread *threadSourceReader;
    QThread *threadRectifier;
    QThread *threadStereoMatcher;
    bool isVideo;

    void setupMeasurement();
    void stopThreads();
    void openFile();
    void closeFile();
};

#endif // WIDGETMEASOFFLINE_H
