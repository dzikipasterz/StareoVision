#ifndef SOURCEREADER_H
#define SOURCEREADER_H

#include <QObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

class SourceReader : public QObject
{
    Q_OBJECT
public:
    explicit SourceReader(QObject *parent = nullptr);

    void setSourcePaths(QString leftSource, QString rightSource);

signals:
    void sendFrames(cv::Mat leftFrame, cv::Mat rightFrame);

public slots:
    void receiveStart();

protected:
    void virtual executeStart();

protected:
    QString leftSourcePath;
    QString rightSourcePath;
};

#endif // SOURCEREADER_H
