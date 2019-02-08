/********************************************************************************
** Form generated from reading UI file 'GUIAdmin.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIADMIN_H
#define UI_GUIADMIN_H

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

class Ui_GUIAdmin
{
public:
    QListWidget *repoList;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *breedLabel;
    QLineEdit *breedEdit;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *ageLabel;
    QLineEdit *ageEdit;
    QLabel *photoLabel;
    QLineEdit *photoEdit;
    QPushButton *removeButton;
    QPushButton *updateButton;
    QPushButton *addButton;
    QLabel *label;
    QLineEdit *filter;
    QPushButton *undoButton;
    QPushButton *redoButton;

    void setupUi(QWidget *GUIAdmin)
    {
        if (GUIAdmin->objectName().isEmpty())
            GUIAdmin->setObjectName(QStringLiteral("GUIAdmin"));
        GUIAdmin->resize(1055, 760);
        repoList = new QListWidget(GUIAdmin);
        repoList->setObjectName(QStringLiteral("repoList"));
        repoList->setGeometry(QRect(30, 50, 841, 281));
        repoList->setStyleSheet(QStringLiteral("font: 18pt \"MS Shell Dlg 2\";"));
        formLayoutWidget = new QWidget(GUIAdmin);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 330, 841, 151));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        breedLabel = new QLabel(formLayoutWidget);
        breedLabel->setObjectName(QStringLiteral("breedLabel"));
        QFont font;
        font.setPointSize(12);
        breedLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, breedLabel);

        breedEdit = new QLineEdit(formLayoutWidget);
        breedEdit->setObjectName(QStringLiteral("breedEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, breedEdit);

        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, nameLabel);

        nameEdit = new QLineEdit(formLayoutWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nameEdit);

        ageLabel = new QLabel(formLayoutWidget);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));
        ageLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, ageLabel);

        ageEdit = new QLineEdit(formLayoutWidget);
        ageEdit->setObjectName(QStringLiteral("ageEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ageEdit);

        photoLabel = new QLabel(formLayoutWidget);
        photoLabel->setObjectName(QStringLiteral("photoLabel"));
        photoLabel->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, photoLabel);

        photoEdit = new QLineEdit(formLayoutWidget);
        photoEdit->setObjectName(QStringLiteral("photoEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, photoEdit);

        removeButton = new QPushButton(GUIAdmin);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(890, 330, 161, 111));
        QFont font1;
        font1.setPointSize(28);
        removeButton->setFont(font1);
        updateButton = new QPushButton(GUIAdmin);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setGeometry(QRect(890, 190, 161, 111));
        updateButton->setFont(font1);
        addButton = new QPushButton(GUIAdmin);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(890, 50, 161, 111));
        addButton->setFont(font1);
        label = new QLabel(GUIAdmin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 601, 41));
        QFont font2;
        font2.setPointSize(14);
        label->setFont(font2);
        filter = new QLineEdit(GUIAdmin);
        filter->setObjectName(QStringLiteral("filter"));
        filter->setGeometry(QRect(930, 540, 113, 20));
        undoButton = new QPushButton(GUIAdmin);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setGeometry(QRect(30, 570, 131, 71));
        redoButton = new QPushButton(GUIAdmin);
        redoButton->setObjectName(QStringLiteral("redoButton"));
        redoButton->setGeometry(QRect(210, 570, 131, 71));

        retranslateUi(GUIAdmin);

        QMetaObject::connectSlotsByName(GUIAdmin);
    } // setupUi

    void retranslateUi(QWidget *GUIAdmin)
    {
        GUIAdmin->setWindowTitle(QApplication::translate("GUIAdmin", "GUIAdmin", nullptr));
        breedLabel->setText(QApplication::translate("GUIAdmin", "Breed:", nullptr));
        nameLabel->setText(QApplication::translate("GUIAdmin", "Name", nullptr));
        ageLabel->setText(QApplication::translate("GUIAdmin", "Age:", nullptr));
        photoLabel->setText(QApplication::translate("GUIAdmin", "Photo:", nullptr));
        removeButton->setText(QApplication::translate("GUIAdmin", "REMOVE", nullptr));
        updateButton->setText(QApplication::translate("GUIAdmin", "UPDATE", nullptr));
        addButton->setText(QApplication::translate("GUIAdmin", "ADD", nullptr));
        label->setText(QApplication::translate("GUIAdmin", "The dogs from the shelter are:", nullptr));
        undoButton->setText(QApplication::translate("GUIAdmin", "UNDO", nullptr));
        redoButton->setText(QApplication::translate("GUIAdmin", "REDO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIAdmin: public Ui_GUIAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIADMIN_H
