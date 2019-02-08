#pragma once
#include "Dog.h"
#include "Repository.h"

class Action
{
public:
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
	// virtual destructor!
	virtual ~Action() {};
};

class UndoAdd : public Action
{
private:
	Dog addedDog;
	Repository& repo;	// we keep a reference to the repository to be able to undo the action
public:
	UndoAdd(Repository& _repo, const Dog& d) : repo{ _repo }, addedDog{ d } {}

	/*
	For the add operation, the reverse operation that must be executed is "remove".
	*/
	void executeUndo() override
	{
		this->repo.delDogR(addedDog.getBreed(), addedDog.getName());
	}
	void executeRedo() override
	{
		this->repo.addDogR(addedDog);
	}
};

class UndoRemove : public Action
{
private:
	Dog deletedDog;
	Repository& repo;
public:
	UndoRemove(Repository& _repo, const Dog& d) : repo{ _repo }, deletedDog{ d } {}

	void executeUndo() override
	{
		this->repo.addDogR(deletedDog);
	}
	void executeRedo() override
	{
		this->repo.delDogR(deletedDog.getBreed(), deletedDog.getName());
	}
};

class UndoUpdate : public Action
{
private:
	Dog updatedDog;
	Dog updatedDog1;
	Repository& repo;

public:
	UndoUpdate(Repository& _repo, const Dog& d, const Dog& d1) : repo{ _repo }, updatedDog{ d }, updatedDog1{ d1 } {}

	void executeUndo() override
	{
		this->repo.upDogR(updatedDog);
	}
	void executeRedo() override
	{
		this->repo.upDogR(updatedDog1);
	}
};