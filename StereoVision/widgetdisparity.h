#ifndef WIDGETDISPARITY_H
#define WIDGETDISPARITY_H

#include <QWidget>
#include <QFileDialog>
#include <imagereader.h>
#include <videoreader.h>
#include <videowriter.h>


namespace Ui {
class WidgetDisparity;
}

class WidgetDisparity : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetDisparity(QWidget *parent = nullptr);
    ~WidgetDisparity();

private slots:
    void on_pushButtonSource_clicked();

    void on_pushButtonResults_clicked();

private:
    Ui::WidgetDisparity *ui;
    QString sourcesDir, resultsDir, lastDir;
};

#endif // WIDGETDISPARITY_H
