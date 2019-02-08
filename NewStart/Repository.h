#pragma once
#include "Dog.h"
#include <vector>

class Repository
{
private:
	std::vector<Dog> dogs;
	std::string filename;
	

public:
	Repository(const std::string& filename);
	/*
	Default constructor.
	Initializes an object of type Repository.
	*/
	void addDogR(const Dog& d);
	/*
	Adds a Dog d in the Repository;
	in:  a pointer to the Dog "d";
	out: 0 if the Dog existed/ 1 if the Dog doesn`t exists and was added;
	*/
	void delDogR(const std::string& breed, const std::string& name);
	/*
	Removes a Dog that has exact the "breed" and the "name" from the Repository;
	in: a pointer to the string "breed", a pointer to the string "name";
	out: 0 if the Dog doesn`t exists/ 1 if the Dog exists and was deleted;
	*/
	void upDogR(const Dog& d);
	/*
	Adds a Dog that has exact the "breed" and the "name" of the Dog d in the Repository;
	in:  a pointer to the Dog "d";
	out: 0 if the Dog doesn`t exists/ 1 if the Dog exists and was updated;
	*/
	Dog findByBreedAndName(const std::string& breed, const std::string& name) const;
	/*
	Find a Dog that has exact the "breed" and the "name" from the Repository;
	in: a pointer to the string "breed", a pointer to the string "name";
	out: the empty Dog {} if doesn`t exist a dog that has exactly the "breed" and the "name"/ the Dog
	*/
	int posfindByBreedAndName(const std::string& breed, const std::string& name);
	/*
	Find the position of Dog that has exact the "breed" and the "name" from the Repository;
	in: a pointer to the string "breed", a pointer to the string "name";
	out: -1 if the Dog doesn`t exists/ the position of Dog in the Repository
	*/
	std::vector <Dog> getDogsR() const { return dogs; }
	/*
	Get all the dogs from the Repository
	*/
private:
	void readFromFile();
	void writeToFile();
};