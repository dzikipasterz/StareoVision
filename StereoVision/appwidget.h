#ifndef APPWIDGET_H
#define APPWIDGET_H

#include <QWidget>
#include <appsettings.h>


class AppWidget : public QWidget
{
    Q_OBJECT

public:
    AppWidget(QWidget *parent = nullptr);
    ~AppWidget();

protected:
    AppSettings settings;

private:
};

#endif // APPWIDGET_H
