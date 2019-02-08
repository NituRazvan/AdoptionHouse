/********************************************************************************
** Form generated from reading UI file 'NewStart.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSTART_H
#define UI_NEWSTART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewStartClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NewStartClass)
    {
        if (NewStartClass->objectName().isEmpty())
            NewStartClass->setObjectName(QStringLiteral("NewStartClass"));
        NewStartClass->resize(600, 400);
        menuBar = new QMenuBar(NewStartClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        NewStartClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NewStartClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NewStartClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(NewStartClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        NewStartClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(NewStartClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NewStartClass->setStatusBar(statusBar);

        retranslateUi(NewStartClass);

        QMetaObject::connectSlotsByName(NewStartClass);
    } // setupUi

    void retranslateUi(QMainWindow *NewStartClass)
    {
        NewStartClass->setWindowTitle(QApplication::translate("NewStartClass", "NewStart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewStartClass: public Ui_NewStartClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSTART_H
