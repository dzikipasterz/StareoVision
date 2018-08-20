#include "calibrator.h"

Calibrator::Calibrator(QObject *parent) :
    QObject(parent),
    capture(false),
    capturedSetsCounter(0)
{

}

void Calibrator::setPatternSize(cv::Size size)
{
    patternSize = size;
}

void Calibrator::setSquareSideSize(float size)
{
    squareSideSize = size;
}

void Calibrator::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{

    if(capture)
    {
        cv::Mat leftProcessed;
        cv::Mat rightProcessed;
        bool status = false;
        cv::cvtColor(leftFrame, leftProcessed, cv::COLOR_RGB2GRAY);
        cv::cvtColor(rightFrame, rightProcessed, cv::COLOR_RGB2GRAY);
        bool leftFound = findChessboardCorners(leftProcessed, patternSize, leftCenters, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_NORMALIZE_IMAGE);
        bool rightFound = findChessboardCorners(leftProcessed, patternSize, rightCenters, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_NORMALIZE_IMAGE);
        if(leftFound && rightFound)
        {
            cv::cornerSubPix(leftProcessed, leftCenters, cv::Size(11,11), cv::Size(-1,-1), cvTermCriteria(CV_TERMCRIT_ITER, 30, 0.01) );
            leftCorners.push_back(leftCenters);
            cv::cornerSubPix(rightProcessed, rightCenters, cv::Size(11,11), cv::Size(-1,-1), cvTermCriteria(CV_TERMCRIT_ITER, 30, 0.01) );
            leftCorners.push_back(rightCenters);
            capturedSetsCounter++;
            status = false; //no error
        }
        else status=true; //error

        emit sendCalibratorStatus(capturedSetsCounter, status);
        capture=false;

        leftProcessed.release();
        rightProcessed.release();
    }
    leftFrame.release();
    rightFrame.release();
}

void Calibrator::receiveTakePicture()
{
    capture=true;
}

void Calibrator::receiveStartCalibration()
{

}
