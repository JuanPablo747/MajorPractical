// ------ // ------ // set-up // ------ // ------ //
#include <string>
#include <iostream>
#include "riverbank-array.h"
#include "animal.h"

using namespace std;

// ------ // constructors & destructors // ------ //

riverbank::riverbank()
{
	capacity = 3;
	stored_animals = 0;
	animal** bankStorage = new animal*[capacity];
}

riverbank::~riverbank()
{
	delete[] bankStorage;
}

// ------ // ------ // getters // ------ // ------ //

//returns the array of the animal pointers
animal** riverbank::returnArray()
{
	return bankStorage;
}

//Prints the status of the bank or what is in the array
void riverbank::printBankStatus()
{
	cout << "Animals on riverbank: ";
	for (int i = 0; i < getMaxCapacity(); i++)
	{
		//if the animal isnt a 'blank' animal, it will print it's species to the screen
		if (bankStorage[i]->getInitial() != 'x')
		{
			cout << bankStorage[i]->getSpecies() << " ";
		}
	}
	cout << endl;
}

//checks whether the array has all the animals in it (will use with the while loop)
	// -> returns true if all animals are in the array, false if not
	// -> dog = d cat = c mouse = m
bool riverbank::checkBank()
{
	if (getStoredAnimals() == getMaxCapacity())
	{
		return true;
	}
	else
	{
		return false;
	}
  
}

// get capacity
int riverbank::getMaxCapacity()
{
	return capacity;
}

// get current stored_animals
int riverbank::getStoredAnimals()
{
	return stored_animals;
}

// ------ // ------ // setters // ------ // ------ //

//adds an animal to the animal array
void riverbank::addAnimal(animal* aAnimal)
{
	// move along array and find an element containing a 'blank animal', then replace it with the new animal
	for (int i = 0; i < getMaxCapacity(); i++)
	{
		if (bankStorage[i] == NULL) 
		{
			bankStorage[i] = aAnimal;
			stored_animals = stored_animals + 1;
		}
	}
}

//subtracts an animal to the animal array
void riverbank::removeAnimal(animal* aAnimal)
{
	// move along array and find an element containing 'aAnimal', then replace it with the 'blank animal'
	for (int i = 0; i < getMaxCapacity(); i++)
	{
		if (bankStorage[i] == aAnimal) 
		{
			bankStorage[i] = NULL;
			stored_animals = stored_animals - 1;
		}
	}
}
