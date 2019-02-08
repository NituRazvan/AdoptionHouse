#include "Dog.h"
#include <string>
#include <iostream>
#include "Utils.h"

using namespace std;

Dog::Dog() : breed(""), name(""), age(0), photo("") {}

Dog::Dog(const string& breed, const string& name, int age, const string& photo)
{
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photo = photo;
}
istream& operator>>(istream & stream, Dog & d)
{
	string line;
	getline(stream, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4)
		return stream;

	d.breed = tokens[0];
	d.name = tokens[1];
	d.age = stoi(tokens[2]);
	d.photo = tokens[3];

	return stream;
}
ostream& operator<<(ostream & stream, const Dog & d)
{
	stream << d.breed << "," << d.name << "," << d.age << "," << d.photo << "\n";
	return stream;
}