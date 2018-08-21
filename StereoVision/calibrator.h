#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include <QObject>
#include <QDateTime>
#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <stdio.h>
#include <iostream>
#include <fstream>


class Calibrator : public QObject
{
    Q_OBJECT
public:
    explicit Calibrator(QObject *parent = nullptr);

    void setPatternSize(cv::Size size);
    void setSquareSideSize(float size);

signals:
    void sendCalibratorStatus(int numberOfSets, bool lastSetStatus);
    void calibrationProgres(float progress);

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);
    void receiveTakePicture();
    void receiveStartCalibration();

private:
    bool capture;
    int capturedSetsCounter;
    std::vector<std::vector<cv::Point2f>> leftCorners;
    std::vector<std::vector<cv::Point2f>> rightCorners;
    cv::Size patternSize;
    std::vector<cv::Point2f> leftCenters;
    std::vector<cv::Point2f> rightCenters;
    float squareSideSize;
    std::vector<std::vector<cv::Point3f>> chessboardKnownPosition;
    cv::Size imgSize;
    cv::Mat leftCamMat, rightCamMat, leftDistCoeff, rightDistCoeff;
    std::vector<cv::Mat> leftRvecs, rightRvecs, leftTvecs, rightTvecs;
    cv::Mat rotMat, transMat, essMat, fundMat;
    double leftErr, rightErr, stereoErr;
    cv::Mat leftRotMat, rightRotMat, leftProjMat, rightProjMat, perspectiveMat;

    void generateChessboard();


};

#endif // CALIBRATOR_H
