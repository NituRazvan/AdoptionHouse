#include "Repository.h"
#include <string>
#include <fstream>
#include "Utils.h"
#include "RepositoryExceptions.h"
#include <algorithm>
using namespace std;

Repository::Repository(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}
void Repository::addDogR(const Dog& d)
{
	int pos = posfindByBreedAndName(d.getBreed(), d.getName());
	if (pos == -1)
	{
		this->dogs.push_back(d);
		this->writeToFile();
	}
	else throw DuplicateDogException();

}

void Repository::delDogR(const std::string& breed, const std::string& name)
{
	int pos = posfindByBreedAndName(breed, name);
	if (pos != -1)
	{
		this->dogs.erase(dogs.begin() + pos);
		this->writeToFile();
	}
	else throw DoesntExistDogException();

}

void Repository::upDogR(const Dog& d)
{
	int pos = posfindByBreedAndName(d.getBreed(), d.getName());
	if (pos != -1)
	{
		this->dogs[pos] = d;
		this->writeToFile();
	}
	else throw DoesntExistDogException();

}
Dog Repository::findByBreedAndName(const std::string& breed, const std::string& name) const
{
	for (auto d : this->dogs)
	{
		if (d.getBreed() == breed && d.getName() == name)
			return d;
	}

	return Dog{};
}


int Repository::posfindByBreedAndName(const std::string& breed, const std::string& name)
{
	vector <Dog> v = this->dogs;
	auto it = find_if(v.begin(), v.end(), [&breed, &name](const Dog& d) {return (d.getBreed() == breed && d.getName() == name); });
	if (it != v.end())
	{
		auto index = distance(v.begin(), it);
		return index;
	}

	return -1;
}

void Repository::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	Dog d;
	while (file >> d)
		this->dogs.push_back(d);

	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	for (auto it : this->dogs)
	{
		file << it;
	}

	file.close();
}