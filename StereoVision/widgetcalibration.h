#ifndef WIDGETCALIBRATION_H
#define WIDGETCALIBRATION_H

#include <QWidget>
#include <appwidget.h>
#include <cornersfinder.h>
#include <picturetaker.h>

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

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);

protected:
    void startup();

private slots:
    void on_pushButtonTurnCameraOn_toggled(bool checked);

    void on_pushButtonTakePicture_clicked();

private:
    Ui::widgetCalibration *ui;
    QThread * threadCornersFinder;
    CornersFinder * cornersFinder;
    PictureTaker * pictureTaker;
    bool cameraInitialized;

    void openCamera();
};

#endif // WIDGETCALIBRATION_H
