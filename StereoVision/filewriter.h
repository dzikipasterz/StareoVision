#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>

class FileWriter : public QObject
{
    Q_OBJECT
public:
    explicit FileWriter(QObject *parent = nullptr);

signals:

public slots:
    void receiveFrame(cv::Mat frame);

protected:
    void virtual executeReceiveFrame(cv::Mat frame)=0;
    void virtual executeStartWriting();
    void virtual executeStopWriting();
};

#endif // FILEWRITER_H
