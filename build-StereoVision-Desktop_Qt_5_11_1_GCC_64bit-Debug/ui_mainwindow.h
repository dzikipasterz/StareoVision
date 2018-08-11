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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionO_programie;
    QAction *actionZako_cz;
    QWidget *centralWidget;
    QPushButton *pushButtonPomiar;
    QPushButton *pushButtonKalibracja;
    QPushButton *pushButtonUstawienia;
    QPushButton *pushButtonWyjscie;
    QPushButton *pushButtonInfo;
    QWidget *widget;
    QMenuBar *menuBar;
    QMenu *menuPlik;
    QMenu *menuPomoc;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1004, 492);
        MainWindow->setMinimumSize(QSize(1004, 492));
        actionO_programie = new QAction(MainWindow);
        actionO_programie->setObjectName(QStringLiteral("actionO_programie"));
        actionZako_cz = new QAction(MainWindow);
        actionZako_cz->setObjectName(QStringLiteral("actionZako_cz"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonPomiar = new QPushButton(centralWidget);
        pushButtonPomiar->setObjectName(QStringLiteral("pushButtonPomiar"));
        pushButtonPomiar->setGeometry(QRect(10, 10, 131, 31));
        pushButtonKalibracja = new QPushButton(centralWidget);
        pushButtonKalibracja->setObjectName(QStringLiteral("pushButtonKalibracja"));
        pushButtonKalibracja->setGeometry(QRect(10, 90, 131, 31));
        pushButtonUstawienia = new QPushButton(centralWidget);
        pushButtonUstawienia->setObjectName(QStringLiteral("pushButtonUstawienia"));
        pushButtonUstawienia->setGeometry(QRect(10, 50, 131, 31));
        pushButtonWyjscie = new QPushButton(centralWidget);
        pushButtonWyjscie->setObjectName(QStringLiteral("pushButtonWyjscie"));
        pushButtonWyjscie->setGeometry(QRect(10, 390, 131, 31));
        pushButtonInfo = new QPushButton(centralWidget);
        pushButtonInfo->setObjectName(QStringLiteral("pushButtonInfo"));
        pushButtonInfo->setGeometry(QRect(10, 350, 131, 31));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(150, 10, 841, 411));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1004, 22));
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
        menuPlik->addAction(actionZako_cz);
        menuPomoc->addAction(actionO_programie);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionO_programie->setText(QApplication::translate("MainWindow", "O programie", nullptr));
        actionZako_cz->setText(QApplication::translate("MainWindow", "Zako\305\204cz", nullptr));
        pushButtonPomiar->setText(QApplication::translate("MainWindow", "Pomiar", nullptr));
        pushButtonKalibracja->setText(QApplication::translate("MainWindow", "Kalibracja", nullptr));
        pushButtonUstawienia->setText(QApplication::translate("MainWindow", "Ustawienia", nullptr));
        pushButtonWyjscie->setText(QApplication::translate("MainWindow", "Wyj\305\233cie", nullptr));
        pushButtonInfo->setText(QApplication::translate("MainWindow", "O programie", nullptr));
        menuPlik->setTitle(QApplication::translate("MainWindow", "Plik", nullptr));
        menuPomoc->setTitle(QApplication::translate("MainWindow", "Pomoc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
