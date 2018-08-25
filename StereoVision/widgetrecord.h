#ifndef WIDGETRECORD_H
#define WIDGETRECORD_H

#include <QWidget>
#include <appwidget.h>
#include <appsettings.h>

namespace Ui {
class widgetRecord;
}

class widgetRecord : public AppWidget
{
    Q_OBJECT

public:
    explicit widgetRecord(AppSettings sett);
    ~widgetRecord();

public slots:
        void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);

private:
    Ui::widgetRecord *ui;
};

#endif // WIDGETRECORD_H
