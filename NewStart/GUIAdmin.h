#pragma once

#include <QWidget>
#include "ui_GUIAdmin.h"
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
#include <vector>
class GUIAdmin : public QWidget
{
	Q_OBJECT

public:
	GUIAdmin(Controller& c, QWidget *parent = Q_NULLPTR);
	~GUIAdmin();

private:
	Ui::GUIAdmin ui;
	Controller& ctrl;
	std::vector<Dog> elemsRepo;
	void populateRepo();
	int getRepoIndex();
	private slots:
	void on_addButton_clicked();
	void on_removeButton_clicked();
	void on_updateButton_clicked();
	void on_undoButton_clicked();
	void on_redoButton_clicked();
	void on_filter_textChanged();
};
