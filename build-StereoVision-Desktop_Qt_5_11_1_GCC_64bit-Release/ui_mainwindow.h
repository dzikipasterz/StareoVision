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
    QAction *actionO_programie;
    QAction *actionZako_cz;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayoutMenu;
    QPushButton *pushButtonPomiarOnline;
    QPushButton *pushButtonPomiarOffline;
    QPushButton *pushButtonNagrywanie;
    QPushButton *pushButtonKalibracja;
    QPushButton *pushButtonUstawienia;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QPushButton *pushButtonInfo;
    QPushButton *pushButtonWyjscie;
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
        actionO_programie = new QAction(MainWindow);
        actionO_programie->setObjectName(QStringLiteral("actionO_programie"));
        actionZako_cz = new QAction(MainWindow);
        actionZako_cz->setObjectName(QStringLiteral("actionZako_cz"));
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
        pushButtonPomiarOnline = new QPushButton(centralWidget);
        pushButtonPomiarOnline->setObjectName(QStringLiteral("pushButtonPomiarOnline"));
        pushButtonPomiarOnline->setMinimumSize(QSize(131, 31));
        pushButtonPomiarOnline->setMaximumSize(QSize(131, 31));

        verticalLayoutMenu->addWidget(pushButtonPomiarOnline);

        pushButtonPomiarOffline = new QPushButton(centralWidget);
        pushButtonPomiarOffline->setObjectName(QStringLiteral("pushButtonPomiarOffline"));
        pushButtonPomiarOffline->setMinimumSize(QSize(131, 31));
        pushButtonPomiarOffline->setMaximumSize(QSize(131, 31));

        verticalLayoutMenu->addWidget(pushButtonPomiarOffline);

        pushButtonNagrywanie = new QPushButton(centralWidget);
        pushButtonNagrywanie->setObjectName(QStringLiteral("pushButtonNagrywanie"));
        pushButtonNagrywanie->setMinimumSize(QSize(131, 31));
        pushButtonNagrywanie->setMaximumSize(QSize(131, 31));

        verticalLayoutMenu->addWidget(pushButtonNagrywanie);

        pushButtonKalibracja = new QPushButton(centralWidget);
        pushButtonKalibracja->setObjectName(QStringLiteral("pushButtonKalibracja"));
        pushButtonKalibracja->setMinimumSize(QSize(131, 31));
        pushButtonKalibracja->setMaximumSize(QSize(131, 31));

        verticalLayoutMenu->addWidget(pushButtonKalibracja);

        pushButtonUstawienia = new QPushButton(centralWidget);
        pushButtonUstawienia->setObjectName(QStringLiteral("pushButtonUstawienia"));
        pushButtonUstawienia->setMinimumSize(QSize(131, 31));
        pushButtonUstawienia->setMaximumSize(QSize(131, 31));

        verticalLayoutMenu->addWidget(pushButtonUstawienia);

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

        pushButtonWyjscie = new QPushButton(centralWidget);
        pushButtonWyjscie->setObjectName(QStringLiteral("pushButtonWyjscie"));
        pushButtonWyjscie->setMinimumSize(QSize(131, 31));
        pushButtonWyjscie->setMaximumSize(QSize(131, 31));

        verticalLayoutMenu->addWidget(pushButtonWyjscie);


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
        pushButtonPomiarOnline->setText(QApplication::translate("MainWindow", "Pomiar online", nullptr));
        pushButtonPomiarOffline->setText(QApplication::translate("MainWindow", "Pomiar offline", nullptr));
        pushButtonNagrywanie->setText(QApplication::translate("MainWindow", "Nagrywanie", nullptr));
        pushButtonKalibracja->setText(QApplication::translate("MainWindow", "Kalibracja", nullptr));
        pushButtonUstawienia->setText(QApplication::translate("MainWindow", "Ustawienia", nullptr));
        label->setText(QString());
        pushButtonInfo->setText(QApplication::translate("MainWindow", "O programie", nullptr));
        pushButtonWyjscie->setText(QApplication::translate("MainWindow", "Wyj\305\233cie", nullptr));
        menuPlik->setTitle(QApplication::translate("MainWindow", "Plik", nullptr));
        menuPomoc->setTitle(QApplication::translate("MainWindow", "Pomoc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
