#ifndef PICTURETAKER_H
#define PICTURETAKER_H

#include <QObject>
#include <QDateTime>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

class PictureTaker : public QObject
{
    Q_OBJECT
public:
    explicit PictureTaker();

signals:
    void sendImagePath(QString path);

public slots:
    void receiveTakePicture();
    void receiveFrame(cv::Mat frame);
    void receiveSetPath(QString path);

private:
    bool takePictureFlag;
    QString savePath;

};

#endif // PICTURETAKER_H
