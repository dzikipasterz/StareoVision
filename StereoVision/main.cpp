#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            w.size(),
            QGuiApplication::primaryScreen()->availableGeometry()
            )
    );

    w.showMeasurementOnlineWidget();
    w.setWindowTitle("Stereowizyjny estymator odległości");
    w.show();

    return a.exec();
}
