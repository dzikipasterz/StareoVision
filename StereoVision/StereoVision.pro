#-------------------------------------------------
#
# Project created by QtCreator 2018-08-07T21:49:02
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = StereoVision
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    info.cpp \
    window_geometry.cpp \
    closeconfirm.cpp \
    widgetmeasurement.cpp \
    widgetsettings.cpp \
    widgetcalibration.cpp \
    timerregulator.cpp \
    stereocamera.cpp \
    camera.cpp \
    appsettings.cpp \
    appwidget.cpp \
    cornersfinder.cpp \
    picturetaker.cpp \
    calibrator.cpp \
    widgetrecord.cpp \
    videowriter.cpp \
    widgetmeasoffline.cpp \
    widgetmeasonline.cpp \
    depthdisplay.cpp \
    stereomatcher.cpp \
    sourcereader.cpp \
    imagereader.cpp \
    rectifier.cpp \
    disparityconverter.cpp \
    postfilter.cpp \
    stereobm.cpp \
    stereosgbm.cpp \
    stereobp.cpp

HEADERS += \
        mainwindow.h \
    info.h \
    window_geometry.h \
    closeconfirm.h \
    widgetmeasurement.h \
    widgetsettings.h \
    widgetcalibration.h \
    timerregulator.h \
    stereocamera.h \
    camera.h \
    appsettings.h \
    appwidget.h \
    cornersfinder.h \
    picturetaker.h \
    calibrator.h \
    widgetrecord.h \
    videowriter.h \
    widgetmeasoffline.h \
    widgetmeasonline.h \
    depthdisplay.h \
    stereomatcher.h \
    sourcereader.h \
    imagereader.h \
    rectifier.h \
    disparityconverter.h \
    postfilter.h \
    stereobm.h \
    stereosgbm.h \
    stereobp.h

FORMS += \
        mainwindow.ui \
    info.ui \
    closeconfirm.ui \
    widgetmeasurement.ui \
    widgetsettings.ui \
    widgetcalibration.ui \
    widgetrecord.ui \
    widgetmeasoffline.ui \
    widgetmeasonline.ui


LIBS += -lopencv_cudaarithm -lopencv_cudabgsegm -lopencv_cudacodec -lopencv_cudafeatures2d -lopencv_cudafilters -lopencv_cudaimgproc -lopencv_cudalegacy -lopencv_cudaobjdetect -lopencv_cudaoptflow -lopencv_cudawarping -lopencv_cudev -lopencv_cudastereo -lopencv_highgui -lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_calib3d -lopencv_imgcodecs -lopencv_ximgproc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
