#ifndef WIDGETSETTINGS_H
#define WIDGETSETTINGS_H

#include <QWidget>
#include <QLabel>
#include <QThread>
#include <QTimer>
#include "framegrabber.h"

namespace Ui {
class widgetSettings;
}

class widgetSettings : public QWidget
{
    Q_OBJECT

public:
    explicit widgetSettings(QWidget *parent = nullptr);
    ~widgetSettings();

signals:
    void sendLeftCameraSetup(const int device);
    void sendRightCameraSetup(const int device);

public slots:
    void receiveFrameLeft(cv::Mat frame);
    void receiveFrameRight(cv::Mat frame);

private slots:
    void on_leftCameraId_valueChanged(int arg1);

    void on_rightCameraId_valueChanged(int arg1);

private:
    Ui::widgetSettings *ui;
    QThread * threadLeftCameraFrameGrabber;
    QThread * threadRightCameraFrameGrabber;
    QThread * threadGrabberTimer;
    void displayFrame(cv::Mat frame, QLabel * display);
    void startup();
};

#endif // WIDGETSETTINGS_H
