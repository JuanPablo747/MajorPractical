#include <string>
#include <iostream>
#include "riverbank.h"
#include "animal.h"

using namespace std;

//constructors
riverbank::riverbank()
{
    bankName = new animal[3];
    count = 0;
}

//returns the array of the animals
animal* riverbank::returnArray()
{
	return bankName;
}

//adds an animal to the animal array
void riverbank::addAnimal(animal a)
{
	//add the animal to the array
	bankName[count] = a; 
	//total animals count ++ if it isnt the blank animal
	if(a.getInitial() != 'x')
	{
	count++;
	}
}

//subtracts an animal to the animal array
void riverbank::removeAnimal(animal a)
{
	//creates a blank animal with initial 'X'
	animal blank;

	//iterates over the animal array and sees if that animal exists in the bankName array
	for (int i = 0; i < 3; i++)
	{
		//if it does exist, make it a 'blank' animal i.e. not a cat, dog or mouse
		//basically clears the memory slot
		if (a.getInitial() == bankName[i].getInitial())
		{
			bankName[i] = blank;
		}
	}
	//take away one from the total animals in the array
	count--;
}

//Prints the status of the bank or what is in the array
void riverbank::printBankStatus()
{
	cout << "Animals on riverbank: ";
	for (int i = 0; i < 3; i++)
	{
		//if the animal isnt a 'blank' animal, it will print it's species to the screen
		if (bankName[i].getInitial() != 'x')
		{
			cout << bankName[i].getSpecies() << " ";
		}
	}
	cout << endl;
}

//checks whether the array has all the animals in it (will use with the while loop)
//returns true if all animals are in the array, false if not
// dog = d cat = c mouse = m
bool riverbank::checkBank()
{
  int counter = 0;
  if (count != 3)
  {
    return false;
  }
  for (int i = 0; i < 3; i++)
  {
  	if (bankName[i].getInitial() == 'd' || bankName[i].getInitial() == 'c' || bankName[i].getInitial() == 'm') 
  	{
  		counter++;
  	}
  }
  if (counter == 3)
  {
  	return true;
  }
  return false;
}

riverbank::~riverbank()
{
	delete [] bankName;
}
