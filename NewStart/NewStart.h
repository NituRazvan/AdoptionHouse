#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NewStart.h"

class NewStart : public QMainWindow
{
	Q_OBJECT

public:
	NewStart(QWidget *parent = Q_NULLPTR);

private:
	Ui::NewStartClass ui;
};
