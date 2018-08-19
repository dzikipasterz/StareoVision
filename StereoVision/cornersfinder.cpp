#include "cornersfinder.h"

using namespace cv;
using namespace std;

CornersFinder::CornersFinder(QObject *parent) :
    QObject(parent),
    patternSize(6,9)
{

}

void CornersFinder::receiveFrames(Mat leftFrame, Mat rightFrame)
{
    bool found = findChessboardCorners(leftFrame, patternSize, centers, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_NORMALIZE_IMAGE | CV_CALIB_CB_FAST_CHECK);
    if (found)
        drawChessboardCorners(leftFrame, patternSize, Mat(centers), found);

    found = findChessboardCorners(rightFrame, patternSize, centers, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_NORMALIZE_IMAGE | CV_CALIB_CB_FAST_CHECK);
    if (found)
        drawChessboardCorners(rightFrame, patternSize, Mat(centers), found);

    emit sendProcessedFrames(leftFrame, rightFrame);
    emit sendJobDone();
}
