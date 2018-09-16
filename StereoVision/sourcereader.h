#ifndef SOURCEREADER_H
#define SOURCEREADER_H

#include <QObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>


enum SourceReaderMode {stereo, mono};

class SourceReader : public QObject
{
    Q_OBJECT
public:
    explicit SourceReader(QObject *parent = nullptr);

    void setSourcePaths(QString leftSource, QString rightSource="");

signals:
    void sendFrames(cv::Mat leftFrame, cv::Mat rightFrame);
    void sendFrame(cv::Mat frame);
    void sendEnd();

public slots:
    void receiveStart();
    void receiveStop();
    void receivePause();
    void receiveResume();
    void receiveJobDone();

protected:
    void virtual executeStart()=0;
    void virtual executeStop();
    void virtual executePause();
    void virtual executeResume();
    void virtual executeJobDone();

protected:
    QString leftSourcePath;
    QString rightSourcePath;
    SourceReaderMode mode;
};

#endif // SOURCEREADER_H
