#include "AdoptionList.h"


AdoptionList::AdoptionList()
{
	this->current = 0;
}

int AdoptionList::addL(const Dog& dog)
{
	for (auto t : this->dogs)
	{
		if (t.getBreed() == dog.getBreed() && t.getName() == dog.getName())
		{ 
			return 0;
		}
	}
	this->dogs.push_back(dog);
	return 1;
}

int AdoptionList::delL(const Dog& dog)
{
	int poz = 0;
	for (auto t : this->dogs)
	{
		if (t.getBreed() == dog.getBreed() && t.getName() == dog.getName())
		{
			this->dogs.erase(dogs.begin()+poz);
			return 1;
		}
		poz = poz + 1;
		
	}
	return 0;
}

bool AdoptionList::isEmpty()
{
	return this->dogs.size() == 0;
}
