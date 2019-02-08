#pragma once
#include "FileAdoptionList.h"
#include <string>

class CSVAdoptionList : public FileAdoptionList
{
public:
	CSVAdoptionList(const std::string& filename) : FileAdoptionList{ filename } {}

	/*
	Writes the playlist to file.
	Throws: FileException - if it cannot write.
	*/
	void writeToFile() override;

	/*
	Displays the playlist using Microsof Excel.
	*/
	void displayAdoptionList() const override;
};

