#include "appsettings.h"

AppSettings::AppSettings() :
    config(new QSettings("../config/config.ini", QSettings::IniFormat))
{

}

AppSettings::~AppSettings()
{
    config->sync();
    delete config;
}

void AppSettings::setLeftCameraId(int cameraId)
{
    config->setValue("app_settings/left_camera_id", cameraId);
    config->sync();
}

int AppSettings::readLeftCameraId()
{
    return config->value("app_settings/left_camera_id", 0).toInt();
}

void AppSettings::setRightCameraId(int cameraId)
{
    config->setValue("app_settings/right_camera_id", cameraId);
    config->sync();
}

int AppSettings::readRightCameraId()
{
    return config->value("app_settings/right_camera_id", 0).toInt();
}

void AppSettings::setPictsSavePath(QString path)
{
    config->setValue("app_settings/pictures_dir", path);
    config->sync();
}

QString AppSettings::readPictSavePath()
{
    return config->value("app_settings/pictures_dir", "/home/").toString();
}

void AppSettings::setCalibFilesDir(QString path)
{
    config->setValue("app_settings/calibration_dir", path);
    config->sync();
}

QString AppSettings::readCalibFilesDir()
{
    return config->value("app_settings/calibration_dir", "/home/").toString();
}

void AppSettings::setCalibFilePath(QString path)
{
    config->setValue("app_settings/calibration_file", path);
    config->sync();
}

QString AppSettings::readCalibFilePath()
{
    return config->value("app_settings/calibration_file", "/home/").toString();
}

void AppSettings::setMovFilesDir(QString path)
{
    config->setValue("app_settings/movies_dir", path);
    config->sync();
}

QString AppSettings::readMovFilesDir()
{
    return config->value("app_settings/movies_dir", "/home/").toString();
}

void AppSettings::setResultsDir(QString path)
{
    config->setValue("app_settings/results_dir", path);
    config->sync();
}

QString AppSettings::readResultsDir()
{
    return config->value("app_settings/results_dir", "/home/").toString();
}

void AppSettings::setChessboardRows(int rows)
{
    config->setValue("app_settings/chessboard_rows", rows);
    config->sync();
}

int AppSettings::readChessboardRows()
{
    return config->value("app_settings/chessboard_rows", 6).toInt();
}

void AppSettings::setChessboardCols(int cols)
{
    config->setValue("app_settings/chessboard_cols", cols);
    config->sync();
}

int AppSettings::readChessboardCols()
{
    return config->value("app_settings/chessboard_cols", 9).toInt();
}

void AppSettings::setChessboardSquareSize(double size)
{
    config->setValue("app_settings/square_size", size);
    config->sync();
}

double AppSettings::readChessboardSquareSize()
{
    return config->value("app_settings/square_size", 36.33).toDouble();
}

cv::Size AppSettings::readPatternSize()
{
    return cv::Size(readChessboardCols()-1, readChessboardRows()-1);
}

void AppSettings::setAlgorithm(Algorithm alg)
{
    config->setValue("app_settings/algorithm", int(alg));
    config->sync();
}

Algorithm AppSettings::readAlgorithm()
{
    return Algorithm(config->value("app_settings/algorithm", 0).toInt());
}

cv::Mat AppSettings::readDispToDepthMap()
{
    cv::FileStorage file(this->readCalibFilePath().toUtf8().constData(), cv::FileStorage::READ);
    cv::Mat Map;
    file["dispToDepthMat"] >> Map;

    file.release();

    return Map;
}

