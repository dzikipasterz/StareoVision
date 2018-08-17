#ifndef FRAMEGRABBER_H
#define FRAMEGRABBER_H

#include <QObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class camera : public QObject
{
    Q_OBJECT
public:
    explicit camera(QObject *parent = nullptr);
    ~camera();

    bool setDevice(const int device);
    bool getStatus();
    cv::Mat grabFrame();

private:
    cv::Mat frame;
    cv::Mat emptyFrame;
    cv::VideoCapture *cap;
    bool status;

    void openDevice(const int device);
    void closeDevice();

};

#endif // FRAMEGRABBER_H
