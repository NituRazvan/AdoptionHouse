#include "HTMLAdoptionList.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"

using namespace std;

void HTMLAdoptionList::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");
	f << "<!DOCTYPE html> \n <html> \n <head> \n <title>AdoptionList</title> \n </head>  \n <body> \n <table border=\"1\">";
	f << " \n <td>Breed</td> \n <td>Name</td> \n <td>Age</td> \n <td>Photo Link</td> \n </tr> \n";
	for (auto d : this->dogs)
		f << "\n <tr> <td>" << d.getBreed() << "</td> \n <td>" << d.getName() << "</td> \n <td>" << d.getAge() << "</td> \n <td> <a href = \"" << d.getPhoto() << "\">Photo</a></td></tr>";

	f << "\n </table> \n </body> \n </html>";
	f.close();
}

void HTMLAdoptionList::displayAdoptionList() const
{
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	//ShellExecuteA(NULL, NULL, "c:\\Program Files\\Microsoft Office\\Office15\\EXCEL.EXE",, NULL, SW_SHOWMAXIMIZED);
}
