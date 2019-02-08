#include "GUIUser.h"
using namespace std;

GUIUser::GUIUser(Controller& c, QWidget* parent) : ctrl(c), QWidget{ parent }
{
	ui.setupUi(this);
	ui.repoList;
	ui.adoptionList;
	this->elemsRepo = this->ctrl.getRepo().getDogsR();
	this->elemsAdoptionList = this->ctrl.getAdoptionList()->getDogs();
	this->populateRepo();
	this->populateAdoptionList();
}

GUIUser::~GUIUser()
{
}

void GUIUser::populateRepo()
{
	if (this->ui.repoList->count() > 0)
		this->ui.repoList->clear();

	for (auto t : this->elemsRepo)
	{
		QString itemInList = QString::fromStdString(t.getBreed() + " - " + t.getName() + " - " + std::to_string(t.getAge()) + " - " + t.getPhoto());
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		this->ui.repoList->addItem(item3);
	}

	if (this->elemsRepo.size() > 0)
		this->ui.repoList->setCurrentRow(0);
}

void GUIUser::populateAdoptionList()
{

	if (this->ui.adoptionList->count() > 0)
		this->ui.adoptionList->clear();

	for (auto t : this->ctrl.getAdoptionList()->getDogs())
	{
		QString itemInList = QString::fromStdString(t.getBreed() + " - " + t.getName() + " - " + std::to_string(t.getAge()) + " - " + t.getPhoto());
		this->ui.adoptionList->addItem(itemInList);
	}
}
int GUIUser::getRepoIndex()
{
	if (this->ui.repoList->count() == 0)
		return -1;

	QModelIndexList index = this->ui.repoList->selectionModel()->selectedIndexes();
	int idx = index.at(0).row();
	return idx;
}
void GUIUser::on_moveDogButton_clicked()
{
	int idx = this->getRepoIndex();
	if (idx == -1 || idx >= this->elemsRepo.size())
		return;

	const Dog& d = this->elemsRepo[idx];
	this->ctrl.addDogToAdoptionC(d);
	this->populateAdoptionList();
}

void GUIUser::on_filterButton_clicked()
{
	string breed = this->ui.breedEdit->text().toStdString();
	int age = stoi(this->ui.ageEdit->text().toStdString());
	if (this->ui.repoList->count() > 0)
		this->ui.repoList->clear();
	for (auto t : this->ctrl.filterBreed(breed,age))
	{
		QString itemInList = QString::fromStdString(t.getBreed() + " - " + t.getName() + " - " + std::to_string(t.getAge()) + " - " + t.getPhoto());
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		this->ui.repoList->addItem(item3);
	}
	if (this->elemsRepo.size() > 0)
		this->ui.repoList->setCurrentRow(0);
}

void GUIUser::on_saveFileButton_clicked()
{
	this->ctrl.saveAdoptionList();
}
void GUIUser::on_openFileButton_clicked()
{
	this->ctrl.openAdoptionList();
}

