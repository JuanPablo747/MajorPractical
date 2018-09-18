// 'guards' to prevent redeclaration of Panda class
#ifndef RIVERBANK_H
#define RIVERBANK_H

#include <string>
#include <vector>
#include "animal.h"

// no namespaces in include file!!!

// Class definition
class riverbank
{
	//*States*
	int capacity;
	int stored_animals;
	(animal*)* bankStorage;

	//*Behaviours*
	public:
	//*Constructors*
	riverbank();

	// setter: adds an animal to the animal array
	void addAnimal(animal* a);

	// setter: an animal to the animal array
	void removeAnimal(animal* a);

	// getter: returns the array of the animals
	animal* returnArray();

	// getter: Prints the status of the bank or what is in the array
	void printBankStatus();

	// getter: checks whether the array has all the animals in it (will use with the while loop)
	bool checkBank();

	// getter: get capacity
	int getMaxCapacity();

	// getter: get current stored_animals
	int getStoredAnimals();
	
	//*destructors*
	~riverbank();
};

#endif
