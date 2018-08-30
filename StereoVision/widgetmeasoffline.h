#ifndef WIDGETMEASOFFLINE_H
#define WIDGETMEASOFFLINE_H

#include <QWidget>
#include <QImage>
#include <QFileDialog>
#include <appwidget.h>
#include <appsettings.h>
#include <depthdisplay.h>
#include <sourcereader.h>
#include <imagereader.h>
#include <rectifier.h>
#include <stereomatcher.h>
#include <blockmatching.h>

namespace Ui {
class widgetMeasOffline;
}

class widgetMeasOffline : public AppWidget
{
    Q_OBJECT

public:
    explicit widgetMeasOffline(AppSettings *sett);
    ~widgetMeasOffline();

public slots:
    void receivePixelArrCoord(int x, int y);

private slots:
    void on_pushButtonLeftSource_clicked();

    void on_pushButtonRightSource_clicked();

    void on_pushButton_clicked();

private:
    Ui::widgetMeasOffline *ui;
    DepthDisplay *depthDisplay;
    QString leftSourcePath;
    QString rightSourcePath;
    SourceReader *sourceReader;
    Rectifier *rectifier;
    StereoMatcher *stereoMatcher;
    QThread *threadSourceReader;
    QThread *threadRectifier;
    QThread *threadStereoMatcher;
    QThread *threadPostprocessing;
    QThread *threadDispToDist;

    void setupMeasurement();
    void stopThreads();
};

#endif // WIDGETMEASOFFLINE_H
