#ifndef CORNERSFINDER_H
#define CORNERSFINDER_H

#include <QObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class CornersFinder : public QObject
{
    Q_OBJECT

public:
    CornersFinder(QObject *parent = nullptr);

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);

signals:
    void sendProcessedFrames(cv::Mat leftFrame, cv::Mat rightFrame);
    void sendJobDone();

};

#endif // CORNERSFINDER_H
