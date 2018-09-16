/*
    This class implements calibration mechanism of the application. It receives frames, which are added
    to calibration set when slot "receiveTakePicture" is activated.
    Then, when slot "receiveStartCalibration" is activated, calibration set is used to generate model of
    cameras.
*/
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

    //set properties of used pattern
    void setPatternSize(cv::Size size);
    void setSquareSideSize(float size);
    void setSaveCalibrationDir(QString dir);


signals:
    void sendCalibrationStatus(QString status);
    void sendCreatedFilePath(QString filepath);
    void sendCollectionStatus(int setsNumber, bool lastSetStatus);

public slots:
    void receiveSetPatternSize(cv::Size size);
    void receiveSetSquareSideSize(float size);
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);
    void receiveTakePicture();
    void receiveStartCalibration();

private:
    bool capture;
    int capturedSetsCounter;
    float squareSideSize;
    QString calibrationSavePath;
    double leftErr, rightErr, stereoErr;
    cv::Size patternSize;
    cv::Size imgSize;
    std::vector<std::vector<cv::Point2f>> leftCorners, rightCorners;
    std::vector<cv::Point2f> leftCenters, rightCenters;
    std::vector<std::vector<cv::Point3f>> chessboardKnownPosition;
    cv::Mat leftCamMat, rightCamMat, leftDistCoeff, rightDistCoeff;
    std::vector<cv::Mat> leftRvecs, rightRvecs, leftTvecs, rightTvecs;
    cv::Mat rotMat, transMat, essMat, fundMat; 
    cv::Mat leftRotMat, rightRotMat, leftProjMat, rightProjMat, dispToDepthMat;
    cv::Mat leftMap1, leftMap2, rightMap1, rightMap2;

    void generateChessboard();


};

#endif // CALIBRATOR_H
