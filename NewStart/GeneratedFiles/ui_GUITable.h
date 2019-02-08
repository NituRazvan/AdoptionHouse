/********************************************************************************
** Form generated from reading UI file 'GUITable.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUITABLE_H
#define UI_GUITABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUITable
{
public:
    QListWidget *repoList;
    QPushButton *moveDogButton;
    QTableView *adoptionList;

    void setupUi(QWidget *GUITable)
    {
        if (GUITable->objectName().isEmpty())
            GUITable->setObjectName(QStringLiteral("GUITable"));
        GUITable->resize(1045, 812);
        repoList = new QListWidget(GUITable);
        repoList->setObjectName(QStringLiteral("repoList"));
        repoList->setGeometry(QRect(20, 30, 991, 241));
        moveDogButton = new QPushButton(GUITable);
        moveDogButton->setObjectName(QStringLiteral("moveDogButton"));
        moveDogButton->setGeometry(QRect(490, 690, 75, 23));
        adoptionList = new QTableView(GUITable);
        adoptionList->setObjectName(QStringLiteral("adoptionList"));
        adoptionList->setGeometry(QRect(20, 290, 991, 231));

        retranslateUi(GUITable);

        QMetaObject::connectSlotsByName(GUITable);
    } // setupUi

    void retranslateUi(QWidget *GUITable)
    {
        GUITable->setWindowTitle(QApplication::translate("GUITable", "GUITable", nullptr));
        moveDogButton->setText(QApplication::translate("GUITable", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUITable: public Ui_GUITable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUITABLE_H
