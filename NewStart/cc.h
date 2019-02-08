#include "Tema1012.h"
#include <qstring.h>
#include "CSVPlaylist.h"
#include "FileHtml.h"
Tema1012::Tema1012(Controller& c) : c(c)
{

	ui.setupUi(this);
	QObject::connect(this->ui.pushButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));

}

void Tema1012::buttonClicked() {
	int option = ui.lineEdit_2->text().toInt();
	int option2 = ui.lineEdit->text().toInt();
	FileAdoption* p = nullptr;
	if (option2 == 1) {
		p = new CSVPlaylist{};

	}
	else {
		p = new HTMLPlaylist{};
	}


	if (option == 1)
	{
		window1 *w1 = new window1{ this->c };
		w1->show();
	}
	else {

		//window1 *w2 = new window2{ this->c };
		//w2->show();
	}
}

