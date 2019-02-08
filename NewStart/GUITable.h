#pragma once
#include <QWidget>
#include "ui_GUITable.h"
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qbuttongroup.h>
#include "Controller.h"
#include "RepositoryExceptions.h"
#include "Dog.h"
#include "DogModel.h"

class GUITable : public QWidget
{
	Q_OBJECT

public:
	GUITable(Controller& c, QWidget* parent = Q_NULLPTR);
	~GUITable();

private:
	Ui::GUITable ui;
	Controller& ctrl;
	DogModel* model;
	std::vector<Dog> elemsRepo;
	std::vector<Dog> elemsAdoptionList;
	void populateRepo();
	int getRepoIndex();
	private slots:
	void on_moveDogButton_clicked();
	void on_saveFileButton_clicked();
	void on_openFileButton_clicked();
};
