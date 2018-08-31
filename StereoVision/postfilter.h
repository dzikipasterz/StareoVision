#ifndef POSTPROCESSOR_H
#define POSTPROCESSOR_H

#include <QObject>
#include <opencv2/core/core.hpp>

class PostFilter : public QObject
{
    Q_OBJECT
public:
    explicit PostFilter(QObject *parent = nullptr);

signals:
    void sendFrame(cv::Mat frame);

public slots:
    void receiveFrame(cv::Mat frame);

protected:
    void virtual processFrame(cv::Mat frame);
};

#endif // POSTPROCESSOR_H
