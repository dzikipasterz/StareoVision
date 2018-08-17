#ifndef CORNERSFINDER_H
#define CORNERSFINDER_H

#include <QObject>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include <sstream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>

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

private:
    cv::Size patternSize;
    std::vector<cv::Point2f> centers;

};

#endif // CORNERSFINDER_H
