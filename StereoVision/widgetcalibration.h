#ifndef WIDGETCALIBRATION_H
#define WIDGETCALIBRATION_H

#include <QWidget>
#include <appwidget.h>
#include <cornersfinder.h>
#include <calibrator.h>

namespace Ui {
class widgetCalibration;
}

class widgetCalibration : public AppWidget
{
    Q_OBJECT

public:
    explicit widgetCalibration(AppSettings sett);
    ~widgetCalibration();

signals:
    void sendTakePicture();
    void sendAddToCalibSet(cv::Mat leftFrame, cv::Mat rightFrame);

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);
    void receiveCalibratorStatus(int numberOfSets, bool lastSetStatus);

protected:
    void startup();

private slots:
    void on_pushButtonTurnCameraOn_toggled(bool checked);

    void on_pushButtonTakePicture_clicked();

private:
    Ui::widgetCalibration *ui;
    QThread * threadCornersFinder;
    QThread * threadCalibrator;
    CornersFinder * cornersFinder;
    Calibrator * calibrator;
    bool cameraInitialized;
    bool captureFrames;

    void openCamera();
};

#endif // WIDGETCALIBRATION_H
