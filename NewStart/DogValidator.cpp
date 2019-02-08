#include "DogValidator.h"

using namespace std;

DogException::DogException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> DogException::getErrors() const
{
	return this->errors;
}

void DogValidator::validate(const Dog & d)
{
	vector<string> errors;
	if (d.getBreed().size() == 0)
		errors.push_back("The breed name cannot be empty!\n");
	if (!isupper(d.getBreed()[0]))
		errors.push_back(string("The breed name must start with a capital letter!\n"));
	if (d.getName().size() == 0)
		errors.push_back("The dog name cannot be empty!\n");
	if (!isupper(d.getName()[0]))
		errors.push_back(string("The dog name must start with a capital letter!\n"));

	if (d.getAge() <= 0)
		errors.push_back(string("The dog age cannot be negative or 0!\n"));

	size_t posWww = d.getPhoto().find("www");
	size_t posHttp = d.getPhoto().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The source must start with one of the following strings: \"www\" or \"http\"");

	if (errors.size() > 0)
		throw DogException(errors);
}
