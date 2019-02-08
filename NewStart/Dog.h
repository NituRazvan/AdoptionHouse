#pragma once
#include <iostream>

class Dog
{
public:
	std::string breed;
	std::string name;
	int age;
	std::string photo;

public:
	Dog();

	Dog(const std::string& breed, const std::string& name, int age, const std::string& photo);

	std::string getBreed() const { return breed; }
	std::string getName() const { return name; }
	int getAge() const { return age; }
	std::string getPhoto() const { return photo; }
	friend std::istream& operator>>(std::istream & stream, Dog & d);
	friend std::ostream& operator<<(std::ostream & stream, const Dog & d);
};
