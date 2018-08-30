#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QString>
#include <QSettings>
#include <opencv2/core/core.hpp>

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
    void setChessboardRows(int rows);
    int readChessboardRows();
    void setChessboardCols(int cols);
    int readChessboardCols();
    void setChessboardSquareSize(double size);
    double readChessboardSquareSize();
    cv::Size readPatternSize();

private:
    QSettings *config;
    void readConfigFile();
};

#endif // APPSETTINGS_H
