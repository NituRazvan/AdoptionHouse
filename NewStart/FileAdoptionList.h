#pragma once
#include "AdoptionList.h"

class FileAdoptionList : public AdoptionList
{
protected:
	std::string filename;

public:
	FileAdoptionList(const std::string& filename);
	virtual ~FileAdoptionList() {}

	virtual void writeToFile() = 0;
	virtual void displayAdoptionList() const = 0;
};
