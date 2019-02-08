#pragma once
#include "FileAdoptionList.h"
#include "Repository.h"
#include "DogValidator.h"
#include <memory>
#include "Action.h"
class Controller
{
private:
	AdoptionList adoption;
	Repository repo;
	FileAdoptionList* adoptionList;
	DogValidator validator;
	std::vector<std::unique_ptr<Action>> undoActions;
	std::vector<std::unique_ptr<Action>> redoActions;
	


	
public:
	Controller(const Repository& r, FileAdoptionList* a, DogValidator v) : repo{ r }, adoptionList{ a }, validator{ v } {}

	Controller(const Controller& ctrl) = delete;		// controller cannot be copied now, because it contains unique_ptr
	void operator=(const Controller& ctrl) = delete;
	Repository getRepo() const { return repo; }
	AdoptionList* getAdoptionList() const
	{
		return adoptionList;

	}
	FileAdoptionList* getAdoptionList1() const
	{
		return adoptionList;
	}


	void addDogC(const std::string& breed, const std::string& name, int age, const std::string& photo);
	//void delDogToAdoptionC(const Dog& dog);
	/*
	Adds a dog with the given data to the Repository.
	in:  a pointer to the string "breed", a pointer to the string "name", a pointer to the integer "age"
	a pointer to the string "photo";
	out: 0 if the Dog existed/ 1 if the Dog doesn`t exists and was added;
	*/
	void addDogToAdoptionC(const Dog& dog);
	void delDogToAdoptionC(const Dog& dog);
	/*
	Adds the Dog "dog" to the AdoptionList.
	in:  a object type Dog "dog";
	out: 0 if the Dog existed/ 1 if the Dog doesn`t exists and was added;
	*/
	void delDogC(const std::string& breed, const std::string& name);
	/*
	Removes the dog with the given data from the Repository.
	in:  a pointer to the string "breed", a pointer to the string "name";
	out: 0 if the Dog doesn`t exists/ 1 if the Dog exists and was deleted;
	*/
	void upDogC(const std::string& breed, const std::string& name, int newage, const std::string& newphoto);
	/*
	Update the dog with the given data from the Repository.
	in:  a pointer to the string "breed", a pointer to the string "name"
	a pointer to the integer "newage", a pointer to the string "newPhoto";
	out: 0 if the Dog doesn`t exists/ 1 if the Dog exists and was deleted;
	*/
	std::vector <Dog> filterBreed(const std::string& breed, int age);
	/*
	Filter the dogs with the given breed that had age lees than the "age".
	in:  a pointer to the string "breed", a pointer to the integer "age";
	*/
	void saveAdoptionList();

	/*
	Opens the playlist, with an appropriate application.
	Throws: FileException - if the given file cannot be opened.
	*/
	void openAdoptionList() const;
	void undo();
	void redo();
};
