#include "appsettings.h"

AppSettings::AppSettings() :
    config(new QSettings("../config/config.ini", QSettings::IniFormat))
{

}

AppSettings::~AppSettings()
{
    delete config;
}

void AppSettings::setLeftCameraId(int cameraId)
{
    config->setValue("app_settings/left_camera_id", cameraId);
}

int AppSettings::readLeftCameraId()
{
    return config->value("app_settings/left_camera_id", 0).toInt();
}

void AppSettings::setRightCameraId(int cameraId)
{
    config->setValue("app_settings/right_camera_id", cameraId);
}

int AppSettings::readRightCameraId()
{
    return config->value("app_settings/right_camera_id", 0).toInt();
}

void AppSettings::setPictsSavePath(QString path)
{
    config->setValue("app_settings/pictures_dir", path);
}

QString AppSettings::readPictSavePath()
{
    return config->value("app_settings/pictures_dir", "/home/").toString();
}

void AppSettings::setCalibFilesDir(QString path)
{
    config->setValue("app_settings/calibration_dir", path);
}

QString AppSettings::readCalibFilesDir()
{
    return config->value("app_settings/calibration_dir", "/home/").toString();
}

void AppSettings::setCalibFilePath(QString path)
{
    config->setValue("app_settings/calibration_file", path);
}

QString AppSettings::readCalibFilePath()
{
    return config->value("app_settings/calibration_file", "/home/").toString();
}

void AppSettings::setMovFilesDir(QString path)
{
    config->setValue("app_settings/movies_dir", path);
}

QString AppSettings::readMovFilesDir()
{
    return config->value("app_settings/movies_dir", "/home/").toString();
}

void AppSettings::setChessboardRows(int rows)
{
    config->setValue("app_settings/chessboard_rows", rows);
}

int AppSettings::readChessboardRows()
{
    return config->value("app_settings/chessboard_rows", 6).toInt();
}

void AppSettings::setChessboardCols(int cols)
{
    config->setValue("app_settings/chessboard_cols", cols);
}

int AppSettings::readChessboardCols()
{
    return config->value("app_settings/chessboard_cols", 9).toInt();
}

void AppSettings::setChessboardSquareSize(double size)
{
    config->setValue("app_settings/square_size", size);
}

double AppSettings::readChessboardSquareSize()
{
    return config->value("app_settings/square_size", 36.33).toDouble();
}

cv::Size AppSettings::readPatternSize()
{
    return cv::Size(readChessboardCols()-1, readChessboardRows()-1);
}

void AppSettings::readConfigFile()
{
    config->sync();
    this->setCalibFilePath(config->value("app_settings/calibration_file", "/home/").toString());
    this->setCalibFilesDir(config->value("app_settings/calibration_dir","/home/").toString());
    this->setMovFilesDir(config->value("app_settings/movies_dir","/home/").toString());
    this->setPictsSavePath(config->value("app_settings/pictures_dir","/home/").toString());
    this->setLeftCameraId(config->value("app_settings/left_camera_id", 0).toInt());
    this->setRightCameraId(config->value("app_settings/right_camera_id", 1).toInt());
    this->setChessboardRows(config->value("app_settings/chessboard_rows", 6).toInt());
    this->setChessboardCols(config->value("app_settings/chessboard_cols", 8).toInt());
    this->setChessboardSquareSize(config->value("app_settings/square_size", 36.33).toDouble());
}

