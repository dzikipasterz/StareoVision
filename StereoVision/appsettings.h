#ifndef APPSETTINGS_H
#define APPSETTINGS_H


class AppSettings
{
public:
    AppSettings();
    ~AppSettings();

    void setLeftCameraId(int cameraId);
    int readLeftCameraId();
    void setRightCameraId(int cameraId);
    int readRightCameraId();

private:
    int leftCameraId;
    int rightCameraId;
};

#endif // APPSETTINGS_H
