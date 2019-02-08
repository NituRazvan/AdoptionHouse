#include "GUITable.h"
using namespace std;

GUITable::GUITable(Controller& c, QWidget* parent) : ctrl(c), QWidget{ parent }
{
	ui.setupUi(this);
	model = new DogModel{ c.getAdoptionList1() };
	ui.repoList;
	this->elemsRepo = this->ctrl.getRepo().getDogsR();
	this->elemsAdoptionList = this->ctrl.getAdoptionList()->getDogs();
	this->populateRepo();

	ui.adoptionList->setModel(model);
	for (int c = 1; c < ui.adoptionList->horizontalHeader()->count(); ++c)
	{
		ui.adoptionList->horizontalHeader()->setSectionResizeMode(
			c, QHeaderView::Stretch);
	}
	for (int c = 0; c < ui.adoptionList->verticalHeader()->count(); ++c)
	{
		ui.adoptionList->verticalHeader()->setSectionResizeMode(
			c, QHeaderView::Stretch);
	}
}

GUITable::~GUITable()
{
}

void GUITable::populateRepo()
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

int GUITable::getRepoIndex()
{
	if (this->ui.repoList->count() == 0)
		return -1;

	QModelIndexList index = this->ui.repoList->selectionModel()->selectedIndexes();
	int idx = index.at(0).row();
	return idx;
}
void GUITable::on_moveDogButton_clicked()
{
	int idx = this->getRepoIndex();
	if (idx == -1 || idx >= this->elemsRepo.size())
		return;

	const Dog& d = this->elemsRepo[idx];
	model->addDog(d);
}

void GUITable::on_saveFileButton_clicked()
{
	this->ctrl.saveAdoptionList();
}
void GUITable::on_openFileButton_clicked()
{
	this->ctrl.openAdoptionList();
}
