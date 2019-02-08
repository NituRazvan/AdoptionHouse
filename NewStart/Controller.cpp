#include "FileAdoptionList.h"
#include <algorithm>
#include "Controller.h"
#include "RepositoryExceptions.h"
using namespace std;

void Controller::addDogC(const string& breed, const string& name, int age, const string& photo)
{
	Dog d{ breed, name, age, photo };
	this->validator.validate(d);
	this->repo.addDogR(d);
	this->undoActions.push_back(std::make_unique<UndoAdd>(this->repo, d));
}

void Controller::delDogC(const string& breed, const string& name)
{
	Dog d1 = repo.findByBreedAndName(breed, name);
	this->repo.delDogR(breed, name);
	this->undoActions.push_back(std::make_unique<UndoRemove>(this->repo, d1));
}


void Controller::upDogC(const string& breed, const string& name, int newage, const string& newphoto)
{
	Dog d{ breed, name, newage, newphoto };
	this->validator.validate(d);
	Dog d1 = repo.findByBreedAndName(breed, name);
	this->repo.upDogR(d);
	this->undoActions.push_back(std::make_unique<UndoUpdate>(this->repo, d1, d));
}

void Controller::addDogToAdoptionC(const Dog& dog)
{
	vector <Dog> v = this->adoptionList->getDogs();
	const string& breed = dog.getBreed();
	const string& name = dog.getName();
	auto it = find_if(v.begin(), v.end(), [&breed, &name](const Dog& d) {return (d.getBreed() == breed && d.getName() == name); });
	if (it == v.end())
	{
		this->adoptionList->addL(dog);
	}
}
void Controller::delDogToAdoptionC(const Dog& dog)
{
	vector <Dog> v = this->adoptionList->getDogs();
	const string& breed = dog.getBreed();
	const string& name = dog.getName();
	auto it = find_if(v.begin(), v.end(), [&breed, &name](const Dog& d) {return (d.getBreed() == breed && d.getName() == name); });
	if (it != v.end())
	{
		this->adoptionList->delL(dog);
	}
}


vector <Dog> Controller::filterBreed(const std::string& breed, int age)
{
	vector <Dog> v = this->repo.getDogsR();
	vector <Dog> new1;
	auto it = copy_if(v.begin(), v.end(), back_inserter(new1), [&breed, &age](const Dog& d) {return (d.getBreed() == breed && d.getAge() < age); });
	return new1;
}

void Controller::saveAdoptionList()
{
	if (this->adoptionList == nullptr)
		return;

	this->adoptionList->writeToFile();
}

void Controller::openAdoptionList() const
{
	if (this->adoptionList == nullptr)
		return;
	this->adoptionList->displayAdoptionList();
}

void Controller::undo()
{
	if (undoActions.empty())
	   {
		throw RepositoryException{ "There are no more actions to undo." };
	}

	try
	{
		//undoActions.back()->executeUndo();
		std::unique_ptr<Action> last = std::move(undoActions.back());
		last->executeUndo();
		undoActions.pop_back(); 
		redoActions.push_back(std::move(last));
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}
void Controller::redo()
{
	if (redoActions.empty())
	{
		throw RepositoryException{ "There are no more actions to redo." };
	}

	try
	{
		//undoActions.back()->executeUndo();
		std::unique_ptr<Action> last = std::move(redoActions.back());
		last->executeRedo();
		redoActions.pop_back();
		undoActions.push_back(std::move(last));
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}