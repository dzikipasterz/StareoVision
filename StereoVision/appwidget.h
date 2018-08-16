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

    void setSettings(AppSettings settings);

protected:
    AppSettings sett;

private:
};

#endif // APPWIDGET_H
