#include "NewStart.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/qmessagebox.h>
#include "GUIAdmin.h"
#include "GUIUser.h"
#include "GUITable.h"
#include "HTMLAdoptionList.h"
#include "CSVAdoptionList.h"
#include "Repository.h"

int main(int argc, char *argv[])
{
	QApplication ap(argc, argv);
	Repository repo{ "database.txt" };
	FileAdoptionList* a = nullptr;
	DogValidator val;


	QMessageBox file{};
	file.setWindowTitle("M");
	file.setText("What type of file would you like to use to store the ADOPTIONlist(CSV / HTML) ?");
	QPushButton *csv = file.addButton("CSV", QMessageBox::ActionRole);
	QPushButton *html = file.addButton("HTML", QMessageBox::AcceptRole);
	file.exec();

	if (file.clickedButton() == csv)
	{
		a = new CSVAdoptionList{ "Adoption.csv" };
	}
	else if (file.clickedButton() == html)
	{
		a = new HTMLAdoptionList{ "Adoption.htm" };
	}
	Controller ctrl(repo, a, val);
	
	QMessageBox start{};
	start.setWindowTitle("M");
	start.setText("In wich mode do you want to enter in the aplication?");
	QPushButton *admin = start.addButton("ADMIN", QMessageBox::ActionRole);
	QPushButton *user = start.addButton("USER", QMessageBox::AcceptRole);
	QPushButton *user1 = start.addButton("TABLE", QMessageBox::AcceptRole);
	start.exec();
	if (start.clickedButton() == admin)
	{
		GUIAdmin Gadmin{ ctrl };
		Gadmin.show();
		return ap.exec();
	}
	else if (start.clickedButton() == user)
	{
		GUIUser Guser{ ctrl };
		Guser.show();
		return ap.exec();
	}
	else if (start.clickedButton() == user1)
	{
		GUITable Table{ ctrl };
		Table.show();
		return ap.exec();
	}
	delete a;
	return ap.exec();
}

