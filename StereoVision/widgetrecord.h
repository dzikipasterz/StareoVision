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
    explicit widgetRecord(AppSettings *sett);
    ~widgetRecord();

signals:
    void sendTakePicture();
    void sendStartRecording();
    void sendStopRecording();
    void sendSetLeftSavePath(QString);
    void sendSetRightSavePath(QString);
    void sendLeftVideoPath(QString path);
    void sendRightVideoPath(QString path);

public slots:
        void receiveLeftFrame(cv::Mat leftFrame);
        void receiveRightFrame(cv::Mat rightFrame);
        void receiveImagesPaths(QString leftPath, QString rightPath);
        void receiveLeftMoviePath(QString leftPath);
        void receiveRightMoviePath(QString leftPath);

private slots:
        void on_pushButtonTakePicture_clicked();

        void on_pushButtonMakeMovie_toggled(bool checked);

private:
    Ui::widgetRecord *ui;
    QThread *threadRecord;
    PictureTaker *pictureTaker;
    VideoWriter *leftVideoWriter, *rightVideoWriter;
};

#endif // WIDGETRECORD_H
