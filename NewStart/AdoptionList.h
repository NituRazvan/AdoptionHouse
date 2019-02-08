#pragma once
#include "Dog.h"
#include <vector>
#include <iostream>
class AdoptionList
{
protected:
	std::vector<Dog> dogs;
	int current;

public:

	AdoptionList();
	AdoptionList(const AdoptionList& ctrl) = delete; 
	void operator=(const AdoptionList& ctrl) = delete;
	int addL(const Dog& dog);
	int delL(const Dog& dog);
	bool isEmpty();
	int getSize() const{
		return this->dogs.size();
	}
	std::vector <Dog> getDogs() const { return dogs; }
	virtual ~AdoptionList() {}
};

