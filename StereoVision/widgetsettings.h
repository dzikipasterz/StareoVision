#ifndef WIDGETSETTINGS_H
#define WIDGETSETTINGS_H

#include <QWidget>
#include <QLabel>
#include <QThread>
#include <QTimer>
#include <QPicture>
#include <QFileDialog>
#include "appwidget.h"


namespace Ui {
class widgetSettings;
}



class widgetSettings : public AppWidget
{
    Q_OBJECT

public:
    explicit widgetSettings(AppSettings *sett);
    ~widgetSettings();

signals:
    void sendStereoCameraSetup(const int leftCameraId, const int rightCameraId);

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);
    void receiveCameraStatus(bool leftCameraStatus, bool rightCameraStatus);

private slots:
    void on_leftCameraId_valueChanged(int id);
    void on_rightCameraId_valueChanged(int id);

    void on_pushButtonSelectPicDir_clicked();

    void on_pushButtonSelectCalibFile_clicked();

    void on_pushButtonSelectMovDir_clicked();

    void on_pushButtonSelectCalibDir_clicked();    

    void on_comboBoxAlgorithm_activated(int index);

private:
    Ui::widgetSettings *ui;

    void displayCameraStatus(bool status, QLabel * labelStatus);
};

#endif // WIDGETSETTINGS_H
