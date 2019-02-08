/********************************************************************************
** Form generated from reading UI file 'GUIUser.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIUSER_H
#define UI_GUIUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIUser
{
public:
    QListWidget *repoList;
    QListWidget *adoptionList;
    QPushButton *moveDogButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *filterButton;
    QPushButton *saveFileButton;
    QPushButton *openFileButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *breedLabel;
    QLineEdit *breedEdit;
    QLabel *ageLabel;
    QLineEdit *ageEdit;

    void setupUi(QWidget *GUIUser)
    {
        if (GUIUser->objectName().isEmpty())
            GUIUser->setObjectName(QStringLiteral("GUIUser"));
        GUIUser->resize(1123, 669);
        repoList = new QListWidget(GUIUser);
        repoList->setObjectName(QStringLiteral("repoList"));
        repoList->setGeometry(QRect(40, 50, 501, 371));
        repoList->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        adoptionList = new QListWidget(GUIUser);
        adoptionList->setObjectName(QStringLiteral("adoptionList"));
        adoptionList->setGeometry(QRect(600, 50, 501, 371));
        adoptionList->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        moveDogButton = new QPushButton(GUIUser);
        moveDogButton->setObjectName(QStringLiteral("moveDogButton"));
        moveDogButton->setGeometry(QRect(40, 570, 121, 81));
        QFont font;
        font.setPointSize(20);
        moveDogButton->setFont(font);
        label = new QLabel(GUIUser);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 401, 21));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label_2 = new QLabel(GUIUser);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(600, 10, 371, 41));
        label_2->setFont(font1);
        filterButton = new QPushButton(GUIUser);
        filterButton->setObjectName(QStringLiteral("filterButton"));
        filterButton->setGeometry(QRect(40, 470, 121, 81));
        filterButton->setFont(font);
        saveFileButton = new QPushButton(GUIUser);
        saveFileButton->setObjectName(QStringLiteral("saveFileButton"));
        saveFileButton->setGeometry(QRect(600, 570, 121, 81));
        saveFileButton->setFont(font);
        openFileButton = new QPushButton(GUIUser);
        openFileButton->setObjectName(QStringLiteral("openFileButton"));
        openFileButton->setGeometry(QRect(980, 570, 121, 81));
        openFileButton->setFont(font);
        formLayoutWidget = new QWidget(GUIUser);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(170, 480, 371, 51));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        breedLabel = new QLabel(formLayoutWidget);
        breedLabel->setObjectName(QStringLiteral("breedLabel"));
        QFont font2;
        font2.setPointSize(11);
        breedLabel->setFont(font2);

        formLayout->setWidget(0, QFormLayout::LabelRole, breedLabel);

        breedEdit = new QLineEdit(formLayoutWidget);
        breedEdit->setObjectName(QStringLiteral("breedEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, breedEdit);

        ageLabel = new QLabel(formLayoutWidget);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));
        QFont font3;
        font3.setPointSize(12);
        ageLabel->setFont(font3);

        formLayout->setWidget(1, QFormLayout::LabelRole, ageLabel);

        ageEdit = new QLineEdit(formLayoutWidget);
        ageEdit->setObjectName(QStringLiteral("ageEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ageEdit);


        retranslateUi(GUIUser);

        QMetaObject::connectSlotsByName(GUIUser);
    } // setupUi

    void retranslateUi(QWidget *GUIUser)
    {
        GUIUser->setWindowTitle(QApplication::translate("GUIUser", "GUIUser", nullptr));
        moveDogButton->setText(QApplication::translate("GUIUser", "ADOPT", nullptr));
        label->setText(QApplication::translate("GUIUser", "The dogs from the shelter are:", nullptr));
        label_2->setText(QApplication::translate("GUIUser", "The dogs from the shelter are:", nullptr));
        filterButton->setText(QApplication::translate("GUIUser", "FILTER", nullptr));
        saveFileButton->setText(QApplication::translate("GUIUser", "SaveFile", nullptr));
        openFileButton->setText(QApplication::translate("GUIUser", "OpenFile", nullptr));
        breedLabel->setText(QApplication::translate("GUIUser", "Breed:", nullptr));
        ageLabel->setText(QApplication::translate("GUIUser", "Age:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIUser: public Ui_GUIUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIUSER_H
