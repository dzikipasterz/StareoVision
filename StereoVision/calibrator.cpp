#include "calibrator.h"

Calibrator::Calibrator(QObject *parent) :
    QObject(parent),
    capture(false),
    capturedSetsCounter(0),
    patternSize(6,9)
{

}

void Calibrator::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    if(capture)
    {
        bool status;
        bool leftFound = findChessboardCorners(leftFrame, patternSize, leftCenters, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_NORMALIZE_IMAGE);
        bool rightFound = findChessboardCorners(rightFrame, patternSize, rightCenters, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_NORMALIZE_IMAGE);
        if(leftFound && rightFound)
        {
            cv::cornerSubPix(leftFrame, leftCenters, cv::Size(5,5), cv::Size(-1,-1), cvTermCriteria(CV_TERMCRIT_ITER, 30, 0.01) );
            leftCorners.push_back(leftCenters);
            cv::cornerSubPix(leftFrame, rightCenters, cv::Size(5,5), cv::Size(-1,-1), cvTermCriteria(CV_TERMCRIT_ITER, 30, 0.01) );
            leftCorners.push_back(rightCenters);
            capturedSetsCounter++;
            status = false; //no error
        }
        else status=true; //error

        emit sendStoreStatus(capturedSetsCounter, status);
        capture=false;
    }
    leftFrame.release();
    rightFrame.release();
}

void Calibrator::receiveTakePicture()
{
    capture=true;
}
