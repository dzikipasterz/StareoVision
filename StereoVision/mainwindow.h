#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QStyle>
#include <QScreen>
#include <QStackedWidget>
#include <QLayout>
#include <QResizeEvent>
#include <window_geometry.h>
#include <appsettings.h>
#include <appwidget.h>
#include "info.h"
#include "closeconfirm.h"
#include "widgetmeasurement.h"
#include "widgetmeasonline.h"
#include "widgetmeasoffline.h"
#include "widgetsettings.h"
#include "widgetcalibration.h"
#include "widgetrecord.h"



namespace Ui {
class MainWindow;
}

static AppWidget *widgetPanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showMeasurementWidget();
    void showMeasurementOnlineWidget();
    void showMeasurementOfflineWidget();
    void showSettingsWidget();
    void showCalibrationWidget();
    void showRecordWidget();

public slots:
    void closeApplication();
    void receiveAppSettings(AppSettings sett);


private slots:
    void on_pushButtonInfo_clicked();
    void on_actionO_programie_triggered();
    void on_pushButtonWyjscie_clicked();
    void on_actionZako_cz_triggered();
    void on_pushButtonPomiarOnline_clicked();
    void on_pushButtonUstawienia_clicked();
    void on_pushButtonKalibracja_clicked();

    void on_pushButtonNagrywanie_clicked();

    void on_pushButtonPomiarOffline_clicked();

private:
    Ui::MainWindow *ui;
    QSize baseSize;
    AppSettings settings;

    void showAppInfo();
    void showCloseConfirmation();
    void initPanelWidget();
    AppSettings readSettingsFile();
    int writeSettingsFile(AppSettings newSettings);
};

#endif // MAINWINDOW_H
