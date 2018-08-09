#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QStyle>
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

    void centerChild(QWidget *parent, QWidget *child);

private slots:
    void on_pushButtonInfo_clicked();

    void on_actionO_programie_triggered();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
