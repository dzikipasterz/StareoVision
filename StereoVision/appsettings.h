/*
    This class implements common settings for the application. It faciilitates access to
    properties, like save paths, calibration file etc.
 */


#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QString>
#include <QSettings>
#include <opencv2/core/core.hpp>

enum Algorithm {BM_cpu, BM_cuda, SGBM_cpu, BP_cuda, CSBP_cuda};

class AppSettings
{
public:
    AppSettings();
    ~AppSettings();

    //selected cameras
    void setLeftCameraId(int cameraId);
    int readLeftCameraId();
    void setRightCameraId(int cameraId);
    int readRightCameraId();

    //default save paths set/get
    void setPictsSavePath(QString path);
    QString readPictSavePath();
    void setCalibFilesDir(QString path);
    QString readCalibFilesDir();
    void setMovFilesDir(QString path);
    QString readMovFilesDir();
    void setResultsDir(QString path);
    QString readResultsDir();

    //selected calibration file set/get
    void setCalibFilePath(QString path);
    QString readCalibFilePath();

    //properties of used calibration chessboard pattern set/get
    void setChessboardRows(int rows);
    int readChessboardRows();
    void setChessboardCols(int cols);
    int readChessboardCols();
    void setChessboardSquareSize(double size);
    double readChessboardSquareSize();
    cv::Size readPatternSize();

    //currently used algorith of stereo pixels matching set/get
    void setAlgorithm(Algorithm alg);
    Algorithm readAlgorithm();

    //reading disparity to depth matrix from calibration file
    cv::Mat readDispToDepthMap();


private:
    QSettings *config; //handle to QSettings object which handles synchronization with *.ini file.
    Algorithm selectedAlgorithm; //currently used algorithm for stereo pixel matching
};

#endif // APPSETTINGS_H
