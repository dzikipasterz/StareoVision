#ifndef FRAMEGRABBER_H
#define FRAMEGRABBER_H

#include <QObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class frameGrabber : public QObject
{
    Q_OBJECT
public:
    explicit frameGrabber(QObject *parent = nullptr);

private:
    cv::Mat _frameOriginal;
    cv::Mat _frameProcessed;
    cv::VideoCapture *cap;
    bool status;

signals:
    void sendStatus();

public slots:
    void receiveGrabFrame();
    void receiveSetup();
};

#endif // FRAMEGRABBER_H
