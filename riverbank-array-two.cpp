#include <string>
#include <iostream>
#include "riverbank-array-two.h"
#include "animal.h"

using namespace std;

//constructors
riverbank::riverbank()
{
    bankName = new animal*[3];
    count = 0;
}

//returns the array of the animals
animal** riverbank::returnArray()
{
	return bankName;
}

//adds an animal to the animal array
void riverbank::addAnimal(animal* a)
{
	for (int i = 0; i < 3; i++)
	{
		if (bankName[i] == NULL)
		{
			bankName[i] = a; 
			count++;
		}
	}
}

void riverbank::initialiseNULL()
{
	for(int i = 0; i < 3; i++)
	{
		bankName[i] = NULL;
	}
}

//subtracts an animal to the animal array
void riverbank::removeAnimal(animal* a)
{
	for (int i = 0; i < 3; i++)
	{
		if (a->getInitial() == bankName[i]->getInitial())
		{
			bankName[i] = NULL;
			count--;
			break;
		}
	}

}

//Prints the status of the bank or what is in the array
void riverbank::printBankStatus()
{
	cout << "Animals on riverbank: ";
	for (int i = 0; i < 3; i++)
	{
		//if the animal isnt a 'blank' animal, it will print it's species to the screen
		if (bankName[i] != NULL)
		{
			cout << bankName[i]->getSpecies() << " ";
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
  	if (bankName[i]->getInitial() == 'd' || bankName[i]->getInitial() == 'c' || bankName[i]->getInitial() == 'm') 
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