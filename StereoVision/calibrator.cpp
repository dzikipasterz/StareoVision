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
        imgSize = leftFrame.size();
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
            rightCorners.push_back(rightCenters);
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


void Calibrator::generateChessboard()
{
    std::vector<cv::Point3f> corners;

    for(int i = 0; i < patternSize.height; i++)
    {
        for(int j = 0; j < patternSize.width; j++)
        {
            corners.push_back(cv::Point3f(j*squareSideSize, i*squareSideSize, 0.0f));
        }
    }

    for(int i = 0; i < capturedSetsCounter; i++)
    {
        chessboardKnownPosition.push_back(corners);
    }


}

void Calibrator::receiveTakePicture()
{
    capture=true;
}

void Calibrator::receiveStartCalibration()
{
    generateChessboard();
    int flag = CV_CALIB_FIX_K4 | CV_CALIB_FIX_K5;
    leftErr = cv::calibrateCamera(chessboardKnownPosition, leftCorners, imgSize, leftCamMat, leftDistCoeff, leftRvecs, leftTvecs, flag);
    rightErr = cv::calibrateCamera(chessboardKnownPosition, rightCorners, imgSize, rightCamMat, rightDistCoeff, rightRvecs, rightTvecs, flag);
    stereoErr = cv::stereoCalibrate(chessboardKnownPosition, leftCorners, rightCorners, leftCamMat, leftDistCoeff, rightCamMat, rightDistCoeff, imgSize, rotMat, transMat, essMat, fundMat);
    cv::stereoRectify(leftCamMat, leftDistCoeff, rightCamMat, rightDistCoeff, imgSize, rotMat, transMat, leftRotMat, rightRotMat, leftProjMat, rightProjMat, perspectiveMat);
    cv::initUndistortRectifyMap(leftCamMat, leftDistCoeff, leftRotMat, leftProjMat, imgSize,  CV_16SC2, leftMap1, leftMap2);
    cv::initUndistortRectifyMap(rightCamMat, rightDistCoeff, rightRotMat, rightProjMat, imgSize,  CV_16SC2, rightMap1, rightMap2);

    QDateTime currentTime = QDateTime::currentDateTime();
    QString filename = (currentTime.toString()).append("_calib.xml");
    cv::FileStorage file(filename.toUtf8().constData(), cv::FileStorage::WRITE);

    file << "leftErr" << leftErr;
    file << "rightErr" << rightErr;
    file << "stereoErr" << stereoErr;
    file << "leftCamMat" << leftCamMat;
    file << "rightCamMat" << rightCamMat;
    file << "leftDistCoeff" << leftDistCoeff;
    file << "rightDistCoeff" << rightDistCoeff;
    file << "rotMat" << rotMat;
    file << "transMat" << transMat;
    file << "leftRotMat" << leftRotMat;
    file << "rightRotMat" << rightRotMat;
    file << "leftProjMat" << leftProjMat;
    file << "rightProjMat" << rightProjMat;
    file << "leftMap1" << leftMap1;
    file << "leftMap2" << leftMap2;
    file << "rightMap1" << rightMap1;
    file << "rightMap2" << rightMap2;

    file.release();

}
