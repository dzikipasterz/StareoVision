#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QStyle>
#include <QScreen>
#include <QStackedWidget>
#include <QLayout>
#include <QResizeEvent>
#include <QSettings>
#include <window_geometry.h>
#include <appsettings.h>
#include <appwidget.h>
#include "info.h"
#include "closeconfirm.h"
#include "widgetmeasonline.h"
#include "widgetmeasoffline.h"
#include "widgetsettings.h"
#include "widgetcalibration.h"
#include "widgetrecord.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showMeasurementOnlineWidget();
    void showMeasurementOfflineWidget();
    void showSettingsWidget();
    void showCalibrationWidget();
    void showRecordWidget();

public slots:
    void closeApplication();

private slots:
    void on_pushButtonInfo_clicked();
    void on_actionAbout_triggered();
    void on_pushButtonExit_clicked();
    void on_actionExit_triggered();
    void on_pushButtonMeasOnline_clicked();
    void on_pushButtonMeasOffline_clicked();
    void on_pushButtonSettings_clicked();
    void on_pushButtonCalibration_clicked();

    void on_pushButtonRecord_clicked();

private:
    Ui::MainWindow *ui;
    QSize baseSize;
    AppSettings settings;
    AppWidget *widgetPanel;

    void showAppInfo();
    void showCloseConfirmation();
    void initPanelWidget();
};

#endif // MAINWINDOW_H
