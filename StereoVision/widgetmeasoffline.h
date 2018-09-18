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
#include <disparityconverter.h>

enum disparityMode {fromRaw, fromFile};

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
    void sendJobDone();

public slots:
    void receiveDisparityAndRaw(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat disparity);
    void receiveDisparity(cv::Mat disparity);
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

    void on_comboBoxMode_activated(int index);

    void on_pushButtonDisparity_clicked();

private:
    Ui::widgetMeasOffline *ui;
    DepthDisplay *depthDisplay;
    QString leftSourcePath, rightSourcePath, disparityPath;
    QString lastPath;
    QFile results;
    QTextStream output;
    bool writeToFile;
    double FPS;
    bool isVideo;
    disparityMode mode;
    SourceReader *sourceReader;
    Rectifier *rectifier;
    StereoMatcher *stereoMatcher;
    QThread *threadSourceReader;
    QThread *threadRectifier;
    QThread *threadStereoMatcher;


    void setupMeasurement();
    void readDisparity();
    void setupSourceReader();
    void stopThreads();
    void openFile();
    void closeFile();
};

#endif // WIDGETMEASOFFLINE_H
