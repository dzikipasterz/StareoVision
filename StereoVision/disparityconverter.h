#ifndef DISPARITYCONVERTER_H
#define DISPARITYCONVERTER_H

#include <QObject>
#include <opencv2/core/core.hpp>

class DisparityConverter : public QObject
{
    Q_OBJECT
public:
    explicit DisparityConverter(QObject *parent = nullptr);

signals:
    void sendDisparityAndRaw(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat distanceFrame);

public slots:
    void receiveDisparity(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat disparityFrame);
};

#endif // DISPARITYCONVERTER_H
