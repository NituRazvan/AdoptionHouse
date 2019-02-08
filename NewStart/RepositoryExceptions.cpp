#include "RepositoryExceptions.h"

FileException::FileException(const std::string & msg) : message(msg) {}

const char * FileException::what()
{
	return message.c_str();
}

RepositoryException::RepositoryException() : exception{}, message{ "" } {}

RepositoryException::RepositoryException(const std::string & msg) : message{ msg } {}

const char * RepositoryException::what()
{
	return this->message.c_str();
}

const char * DuplicateDogException::what()
{
	return "\n There is another dog with the same breed and name! \n";
}

const char * DoesntExistDogException::what()
{
	return "\n The dog doesn`t exists! \n";
}

