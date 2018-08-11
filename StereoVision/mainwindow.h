#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QStyle>
#include <QScreen>
#include <window_geometry.h>
#include "info.h"
#include "closeconfirm.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void closeApplication();


private slots:
    void on_pushButtonInfo_clicked();
    void on_actionO_programie_triggered();
    void on_pushButtonWyjscie_clicked();
    void on_actionZako_cz_triggered();


private:
    Ui::MainWindow *ui;
    void showAppInfo();
    void showCloseConfirmation();
};

#endif // MAINWINDOW_H
