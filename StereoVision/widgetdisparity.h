#ifndef WIDGETDISPARITY_H
#define WIDGETDISPARITY_H

#include <appwidget.h>
#include <appsettings.h>
#include <QWidget>
#include <QFileDialog>
#include <QDateTime>
#include <imagereader.h>
#include <imagewriter.h>
#include <videoreader.h>
#include <videowriter.h>
#include <rectifier.h>
#include <stereomatcher.h>
#include <stereobmcpu.h>
#include <stereosgbmcpu.h>
#include <stereobpcuda.h>
#include <stereocsbpcuda.h>
#include <stereobmcuda.h>


namespace Ui {
class WidgetDisparity;
}

class WidgetDisparity : public AppWidget
{
    Q_OBJECT

public:
    explicit WidgetDisparity(AppSettings *sett);
    ~WidgetDisparity();

signals:
    void sendStartProcessing();

public slots:
    void receiveEnd();

private slots:
    void on_pushButtonSource_clicked();

    void on_pushButtonResults_clicked();

    void on_pushButtonStart_clicked();

private:
    Ui::WidgetDisparity *ui;
    QString sourcesDir, resultsDir, lastDir, status;
    QString leftSource, rightSource;
    std::vector<QString> filesVector;
    std::vector<QString>::iterator iter;
    SourceReader *sourceReader;
    Rectifier *rectifier;
    StereoMatcher *stereoMatcher;
    FileWriter *fileWriter;
    QThread *threadSourceReader;
    QThread *threadRectifier;
    QThread *threadStereoMatcher;
    QThread *threadFileWriter;
    bool isVideo;

    void stopThreads();
    void grabNextFiles();
};

#endif // WIDGETDISPARITY_H
