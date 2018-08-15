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
#include "info.h"
#include "closeconfirm.h"
#include "widgetmeasurement.h"
#include "widgetsettings.h"
#include "widgetcalibration.h"


namespace Ui {

static QWidget *widgetPanel;

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showMeasurementWidget();
    void showSettingsWidget();
    void showCalibrationWidget();

public slots:
    void closeApplication();


private slots:
    void on_pushButtonInfo_clicked();
    void on_actionO_programie_triggered();
    void on_pushButtonWyjscie_clicked();
    void on_actionZako_cz_triggered();
    void on_pushButtonPomiarOnline_clicked();
    void on_pushButtonUstawienia_clicked();
    void on_pushButtonKalibracja_clicked();

private:
    Ui::MainWindow *ui;
    QSize baseSize;
    void showAppInfo();
    void showCloseConfirmation();
    void initPanelWidget();

};

#endif // MAINWINDOW_H
