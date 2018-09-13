/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionExit;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayoutMenu;
    QPushButton *pushButtonMeasOnline;
    QPushButton *pushButtonMeasOffline;
    QPushButton *pushButtonRecord;
    QPushButton *pushButtonCalibration;
    QPushButton *pushButtonSettings;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QPushButton *pushButtonInfo;
    QPushButton *pushButtonExit;
    QMenuBar *menuBar;
    QMenu *menuPlik;
    QMenu *menuPomoc;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(1024, 768);
        MainWindow->setMinimumSize(QSize(1024, 768));
        MainWindow->setMaximumSize(QSize(1920, 1080));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayoutMenu = new QVBoxLayout();
        verticalLayoutMenu->setSpacing(6);
        verticalLayoutMenu->setObjectName(QStringLiteral("verticalLayoutMenu"));
        verticalLayoutMenu->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayoutMenu->setContentsMargins(0, -1, 0, 0);
        pushButtonMeasOnline = new QPushButton(centralWidget);
        pushButtonMeasOnline->setObjectName(QStringLiteral("pushButtonMeasOnline"));
        pushButtonMeasOnline->setMinimumSize(QSize(131, 31));
        pushButtonMeasOnline->setMaximumSize(QSize(131, 31));

        verticalLayoutMenu->addWidget(pushButtonMeasOnline);

        pushButtonMeasOffline = new QPushButton(centralWidget);
        pushButtonMeasOffline->setObjectName(QStringLiteral("pushButtonMeasOffline"));
        pushButtonMeasOffline->setMinimumSize(QSize(131, 31));
        pushButtonMeasOffline->setMaximumSize(QSize(131, 31));

        verticalLayoutMenu->addWidget(pushButtonMeasOffline);

        pushButtonRecord = new QPushButton(centralWidget);
        pushButtonRecord->setObjectName(QStringLiteral("pushButtonRecord"));
        pushButtonRecord->setMinimumSize(QSize(131, 31));
        pushButtonRecord->setMaximumSize(QSize(131, 31));

        verticalLayoutMenu->addWidget(pushButtonRecord);

        pushButtonCalibration = new QPushButton(centralWidget);
        pushButtonCalibration->setObjectName(QStringLiteral("pushButtonCalibration"));
        pushButtonCalibration->setMinimumSize(QSize(131, 31));
        pushButtonCalibration->setMaximumSize(QSize(131, 31));

        verticalLayoutMenu->addWidget(pushButtonCalibration);

        pushButtonSettings = new QPushButton(centralWidget);
        pushButtonSettings->setObjectName(QStringLiteral("pushButtonSettings"));
        pushButtonSettings->setMinimumSize(QSize(131, 31));
        pushButtonSettings->setMaximumSize(QSize(131, 31));

        verticalLayoutMenu->addWidget(pushButtonSettings);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutMenu->addItem(verticalSpacer);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayoutMenu->addWidget(label);

        pushButtonInfo = new QPushButton(centralWidget);
        pushButtonInfo->setObjectName(QStringLiteral("pushButtonInfo"));
        pushButtonInfo->setMinimumSize(QSize(131, 31));
        pushButtonInfo->setMaximumSize(QSize(131, 31));

        verticalLayoutMenu->addWidget(pushButtonInfo);

        pushButtonExit = new QPushButton(centralWidget);
        pushButtonExit->setObjectName(QStringLiteral("pushButtonExit"));
        pushButtonExit->setMinimumSize(QSize(131, 31));
        pushButtonExit->setMaximumSize(QSize(131, 31));

        verticalLayoutMenu->addWidget(pushButtonExit);


        horizontalLayout->addLayout(verticalLayoutMenu);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 22));
        menuPlik = new QMenu(menuBar);
        menuPlik->setObjectName(QStringLiteral("menuPlik"));
        menuPomoc = new QMenu(menuBar);
        menuPomoc->setObjectName(QStringLiteral("menuPomoc"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPlik->menuAction());
        menuBar->addAction(menuPomoc->menuAction());
        menuPlik->addSeparator();
        menuPlik->addAction(actionExit);
        menuPomoc->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "O programie", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Zako\305\204cz", nullptr));
        pushButtonMeasOnline->setText(QApplication::translate("MainWindow", "Pomiar online", nullptr));
        pushButtonMeasOffline->setText(QApplication::translate("MainWindow", "Pomiar offline", nullptr));
        pushButtonRecord->setText(QApplication::translate("MainWindow", "Nagrywanie", nullptr));
        pushButtonCalibration->setText(QApplication::translate("MainWindow", "Kalibracja", nullptr));
        pushButtonSettings->setText(QApplication::translate("MainWindow", "Ustawienia", nullptr));
        label->setText(QString());
        pushButtonInfo->setText(QApplication::translate("MainWindow", "O programie", nullptr));
        pushButtonExit->setText(QApplication::translate("MainWindow", "Wyj\305\233cie", nullptr));
        menuPlik->setTitle(QApplication::translate("MainWindow", "Plik", nullptr));
        menuPomoc->setTitle(QApplication::translate("MainWindow", "Pomoc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
