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

    void setLeftCameraId(int cameraId);
    int readLeftCameraId();
    void setRightCameraId(int cameraId);
    int readRightCameraId();
    void setPictsSavePath(QString path);
    QString readPictSavePath();
    void setCalibFilesDir(QString path);
    QString readCalibFilesDir();
    void setCalibFilePath(QString path);
    QString readCalibFilePath();
    void setMovFilesDir(QString path);
    QString readMovFilesDir();
    void setResultsDir(QString path);
    QString readResultsDir();
    void setChessboardRows(int rows);
    int readChessboardRows();
    void setChessboardCols(int cols);
    int readChessboardCols();
    void setChessboardSquareSize(double size);
    double readChessboardSquareSize();
    void setAlgorithm(Algorithm alg);
    Algorithm readAlgorithm();
    cv::Size readPatternSize();
    cv::Mat readDispToDepthMap();


private:
    QSettings *config;
    Algorithm selectedAlgorithm;
};

#endif // APPSETTINGS_H
