#ifndef WIDGETMEASUREMENT_H
#define WIDGETMEASUREMENT_H

#include <QWidget>

namespace Ui {
class widgetMeasurement;
}

class widgetMeasurement : public QWidget
{
    Q_OBJECT

public:
    explicit widgetMeasurement(QWidget *parent = nullptr);
    ~widgetMeasurement();

private:
    Ui::widgetMeasurement *ui;
};

#endif // WIDGETMEASUREMENT_H
