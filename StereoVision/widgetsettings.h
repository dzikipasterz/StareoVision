#ifndef WIDGETSETTINGS_H
#define WIDGETSETTINGS_H

#include <QWidget>
#include <QLabel>
#include <QThread>
#include <QTimer>
#include <QPicture>
#include "camera.h"
#include "stereocamera.h"
#include "timerregulator.h"

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
    void sendStereoCameraSetup(const int leftCameraId, const int rightCameraId);

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);
    void receiveCameraStatus(bool leftCameraStatus, bool rightCameraStatus);
    void receiveTimerInterval(int interval);

private slots:
    void on_leftCameraId_valueChanged(int arg1);
    void on_rightCameraId_valueChanged(int arg1);

private:
    Ui::widgetSettings *ui;
    int leftCamera;
    int rightCamera;
    QThread * threadStereoCamera;
    QThread * threadTimer;
    QSize baseSize;
    void displayFrame(cv::Mat frame, QLabel * display);
    void displayCameraStatus(bool status, QLabel * labelStatus);
    void startup();
};

#endif // WIDGETSETTINGS_H
