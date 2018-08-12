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
    ~frameGrabber();

private:
    cv::Mat _frameOriginal;
    cv::Mat _frameProcessed;
    cv::VideoCapture *cap;
    bool status;

    void openDevice(const int device);
    void closeDevice();

signals:
    void sendStatus(const int status);

public slots:
    void receiveGrabFrame();
    void receiveSetup(const int device);
};

#endif // FRAMEGRABBER_H
