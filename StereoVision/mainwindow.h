#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QStyle>
#include <window_geometry.h>
#include "info.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButtonInfo_clicked();

    void on_actionO_programie_triggered();


private:
    Ui::MainWindow *ui;
    void showAppInfo();
};

#endif // MAINWINDOW_H
