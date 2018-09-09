#ifndef WIDGETCALIBRATION_H
#define WIDGETCALIBRATION_H

#include <QWidget>
#include <QFileDialog>
#include <QDir>
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
    explicit widgetCalibration(AppSettings *sett);
    ~widgetCalibration();

signals:
    void sendTakePicture();
    void sendLoadPicture();
    void sendStartCalibration();
    void sendLoadedFrames(cv::Mat leftFrame, cv::Mat rightMat);

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);
    void receiveCalibratorStatus(int numberOfSets, bool lastSetStatus);
    void receiveCalibrationStatus(QString status);
    void receiveCalibrationFilePath(QString path);

private slots:
    //void on_pushButtonTurnCameraOn_toggled(bool checked);

    void on_pushButtonTakePicture_clicked();

    void on_pushButtonCalibrate_clicked();

    void on_spinBoxRows_valueChanged(int arg1);

    void on_spinBoxCols_valueChanged(int arg1);

    void on_doubleSpinBoxSquareSize_valueChanged(double arg1);

    void on_pushButtonChooseDirToLoad_clicked();

    void on_pushButtonLoad_clicked();


private:
    Ui::widgetCalibration *ui;
    QThread * threadCornersFinder;
    QThread * threadCalibrator;
    CornersFinder * cornersFinder;
    Calibrator * calibrator;
    bool cameraInitialized;

    void openCamera();
};

#endif // WIDGETCALIBRATION_H
