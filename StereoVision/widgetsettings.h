#ifndef WIDGETSETTINGS_H
#define WIDGETSETTINGS_H

#include <QWidget>

namespace Ui {
class widgetSettings;
}

class widgetSettings : public QWidget
{
    Q_OBJECT

public:
    explicit widgetSettings(QWidget *parent = nullptr);
    ~widgetSettings();

private:
    Ui::widgetSettings *ui;
};

#endif // WIDGETSETTINGS_H
