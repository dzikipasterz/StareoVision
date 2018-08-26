#ifndef WIDGETRECORD_H
#define WIDGETRECORD_H

#include <QWidget>
#include <appwidget.h>
#include <videowriter.h>
#include <appsettings.h>
#include <picturetaker.h>

namespace Ui {
class widgetRecord;
}

class widgetRecord : public AppWidget
{
    Q_OBJECT

public:
    explicit widgetRecord(AppSettings sett);
    ~widgetRecord();

signals:
    void sendTakePicture();
    void sendStartRecording();
    void sendStopRecording();

public slots:
        void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);
        void receiveImagesPaths(QString leftPath, QString rightPath);
        void receiveMoviesPaths(QString leftPath, QString rightPath);

private slots:
        void on_pushButtonTakePicture_clicked();

        void on_pushButtonMakeMovie_toggled(bool checked);

private:
    Ui::widgetRecord *ui;
    QThread *threadRecord;
    PictureTaker *pictureTaker;
    VideoWriter *videoWriter;
};

#endif // WIDGETRECORD_H
