#include "GUIAdmin.h"
#define foreach Q_FOREACH
using namespace std;

GUIAdmin::GUIAdmin(Controller& c, QWidget* parent) : ctrl(c), QWidget{ parent }
{
	ui.setupUi(this);
	ui.repoList;
	this->elemsRepo = this->ctrl.getRepo().getDogsR();
	this->populateRepo();
}

GUIAdmin::~GUIAdmin()
{
}
void GUIAdmin::populateRepo()
{
	if (ui.repoList->count() > 0)
		ui.repoList->clear();

	for (auto t : this->elemsRepo)
	{
		QString itemInList = QString::fromStdString(t.getBreed() + " - " + t.getName() + " - " + std::to_string(t.getAge()) + " - " + t.getPhoto());
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		this->ui.repoList->addItem(item3);
	}
	if (this->elemsRepo.size() > 0)
		this->ui.repoList->setCurrentRow(0);

}
int GUIAdmin::getRepoIndex()
{
	if (this->ui.repoList->count() == 0)
		return -1;

	QModelIndexList index = this->ui.repoList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
	this->ui.breedEdit->clear();
	this->ui.nameEdit->clear();
	this->ui.ageEdit->clear();
	this->ui.photoEdit->clear();

	return -1;
	}

	int idx = index.at(0).row();
	return idx;
	/*vector<int> indexList;
	foreach (QModelIndex index, indexes)
	{
		return index.row();
		indexList.push_back(index.row());

	}*/
}
void GUIAdmin::on_addButton_clicked()
{
	string breed = this->ui.breedEdit->text().toStdString();
	string name = this->ui.nameEdit->text().toStdString();
	int age = stoi(this->ui.ageEdit->text().toStdString());
	string photo = this->ui.photoEdit->text().toStdString();
	try
	{
		this->ctrl.addDogC(breed, name, age, photo);
		this->elemsRepo = this->ctrl.getRepo().getDogsR();
		this->populateRepo();
	}
	catch (DogException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid data!"));
	}
	catch (DuplicateDogException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Duplicate elements!");
	}
}
void GUIAdmin::on_undoButton_clicked()
{
	try
	{
		this->ctrl.undo();
		this->elemsRepo = this->ctrl.getRepo().getDogsR();
		this->populateRepo();
	}
	catch (RepositoryException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}
void GUIAdmin::on_redoButton_clicked()
{
	try
	{
		this->ctrl.redo();
		this->elemsRepo = this->ctrl.getRepo().getDogsR();
		this->populateRepo();
	}
	catch (RepositoryException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}
void GUIAdmin::on_removeButton_clicked()
{
	string breed = this->ui.breedEdit->text().toStdString();
	string name = this->ui.nameEdit->text().toStdString();
	try
	{
		this->ctrl.delDogC(breed, name);
		this->elemsRepo = this->ctrl.getRepo().getDogsR();
		this->populateRepo();
	}
	catch (DogException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid data!"));
	}
	catch (DoesntExistDogException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "The dog does not exist!");
	}
}

void GUIAdmin::on_updateButton_clicked()
{
	string breed = this->ui.breedEdit->text().toStdString();
	string name = this->ui.nameEdit->text().toStdString();
	int age = stoi(this->ui.ageEdit->text().toStdString());
	string photo = this->ui.photoEdit->text().toStdString();
	try
	{
		this->ctrl.upDogC(breed, name, age, photo);
		// refresh the list
		this->elemsRepo = this->ctrl.getRepo().getDogsR();
		this->populateRepo();
	}
	catch (DogException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid data!"));
	}
	catch (DoesntExistDogException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "The dog does not exist!");
	}
}


void GUIAdmin::on_filter_textChanged()
{
	this->ui.repoList->clear();
	QString sear = this->ui.filter->text();
	for (auto t : this->elemsRepo)
	{
		QString itemInList = QString::fromStdString(t.getBreed() + " - " + t.getName() + " - " + std::to_string(t.getAge()) + " - " + t.getPhoto());
		if(itemInList.contains(sear))
		{ 
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		this->ui.repoList->addItem(item3);
		}
	}
}