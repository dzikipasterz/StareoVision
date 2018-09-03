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

void Calibrator::setSaveCalibrationDir(QString dir)
{
    CalibrationSavePath = dir;
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
        bool rightFound = findChessboardCorners(rightProcessed, patternSize, rightCenters, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_NORMALIZE_IMAGE);
        if(leftFound && rightFound)
        {
            cv::cornerSubPix(leftProcessed, leftCenters, cv::Size(5,5), cv::Size(-1,-1), cvTermCriteria(CV_TERMCRIT_ITER, 30, 0.01) );
            leftCorners.push_back(leftCenters);
            cv::cornerSubPix(rightProcessed, rightCenters, cv::Size(5,5), cv::Size(-1,-1), cvTermCriteria(CV_TERMCRIT_ITER, 30, 0.01) );
            rightCorners.push_back(rightCenters);
            capturedSetsCounter++;
            status = false; //no error
        }
        else status=true; //error

        emit sendCollectionStatus(capturedSetsCounter, status);
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
    emit sendCalibrationStatus("Kalibracja rozpoczęta");
    generateChessboard();
    //int flag = CV_CALIB_FIX_K4 | CV_CALIB_FIX_K5;
    int flag = CV_CALIB_FIX_PRINCIPAL_POINT | CV_CALIB_FIX_ASPECT_RATIO | CV_CALIB_ZERO_TANGENT_DIST | CV_CALIB_RATIONAL_MODEL | CV_CALIB_FIX_K3 | CV_CALIB_FIX_K4 | CV_CALIB_FIX_K5;
    //int flag = CV_CALIB_FIX_PRINCIPAL_POINT | CV_CALIB_RATIONAL_MODEL | CV_CALIB_FIX_K3;

    emit sendCalibrationStatus("Kalibracja lewej kamery w toku");
    leftErr = cv::calibrateCamera(chessboardKnownPosition, leftCorners, imgSize, leftCamMat, leftDistCoeff, leftRvecs, leftTvecs, flag, cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 1000, 1e-9));

    emit sendCalibrationStatus("Kalibracja prawej kamery w toku");
    rightErr = cv::calibrateCamera(chessboardKnownPosition, rightCorners, imgSize, rightCamMat, rightDistCoeff, rightRvecs, rightTvecs, flag, cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 1000, 1e-9));

    emit sendCalibrationStatus("Stereokalibracja w toku");
    stereoErr = cv::stereoCalibrate(chessboardKnownPosition, leftCorners, rightCorners, leftCamMat, leftDistCoeff, rightCamMat, rightDistCoeff, imgSize, rotMat, transMat, essMat, fundMat, CV_CALIB_FIX_INTRINSIC | CV_CALIB_SAME_FOCAL_LENGTH , cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, 1e-9));

    emit sendCalibrationStatus("Wyznaczanie parametrów rektyfikacji w toku");
    cv::Rect roi1, roi2;
    cv::stereoRectify(leftCamMat, leftDistCoeff, rightCamMat, rightDistCoeff, imgSize, rotMat, transMat, leftRotMat, rightRotMat, leftProjMat, rightProjMat, dispToDepthMat, cv::CALIB_ZERO_DISPARITY, 0.0, imgSize, &roi1, &roi2);

    emit sendCalibrationStatus("Budowa mapy rektyfikacji dla lewej kamery w toku");
    cv::initUndistortRectifyMap(leftCamMat, leftDistCoeff, leftRotMat, leftProjMat, imgSize,  CV_16SC2, leftMap1, leftMap2);

    emit sendCalibrationStatus("Budowa mapy rektyfikacji dla prawej kamery w toku");
    cv::initUndistortRectifyMap(rightCamMat, rightDistCoeff, rightRotMat, rightProjMat, imgSize,  CV_16SC2, rightMap1, rightMap2);

    emit sendCalibrationStatus("Zapis do pliku kalibracyjnego rozpoczęty");

    QDateTime currentTime = QDateTime::currentDateTime();
    QString filename = CalibrationSavePath.append(currentTime.toString(Qt::ISODate)).append("_calib.xml");
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
    file << "dispToDepthMat" << dispToDepthMat;
    file << "roi1" << roi1;
    file << "roi2" << roi2;
    file << "leftMap1" << leftMap1;
    file << "leftMap2" << leftMap2;
    file << "rightMap1" << rightMap1;
    file << "rightMap2" << rightMap2;

    file.release();

    emit sendCalibrationStatus(QString("Kalibracja zapisana do pliku ").append(filename).append("."));
    emit sendCreatedFilePath(filename);

}
