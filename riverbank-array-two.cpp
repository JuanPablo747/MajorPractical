// ------ // ------ // set-up // ------ // ------ //
#include <string>
#include <iostream>
#include "riverbank-array-two.h"
#include "animal.h"

using namespace std;

// ------ // constructors & destructors // ------ //

riverbank::riverbank()
{
    bankName = new animal*[3];
    count = 0;
}

riverbank::~riverbank()
{
	delete [] bankName;
}

// ------ // ------ // getters // ------ // ------ //

//returns the array of the animals
animal** riverbank::returnArray()
{
	return bankName;
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

//Prints the status of the bank or what is in the array
void riverbank::printBankStatus()
{
  int And = 0;

	for (int i = 0; i < 3; i++)
	{
		//if the animal isnt a 'blank' animal, it will print it's species to the screen
		if (bankName[i] != NULL)
		{
			cout << bankName[i]->getSpecies() << " ";
      			And++;
			if((And == (count - 1)) && (count > 1))
    			{
      				cout << "and ";
    			}
		}
    		
	}
	cout << endl;
}


//Function to ceck if two animals will eat each other and return a unique int if they do to show which animal ate waht
int riverbank::checkPrey()
{
  //return false if there are no animals, 1 animal or 3 animals
  int counter = 0;
  for (int i = 0; i < 3; i++)
    if (bankName[i] == NULL)
      counter++;

  if (counter == 3 || counter == 2)
      return 0;
  if (counter == 0)
      return 3;

  //getting the two animals that are in the array
  char a;
  char b;
  int counter2 = 0;
  for (int j = 0; j < 3; j++)
  {
    if (bankName[j] != NULL)
    {
      if (counter2 == 0)
      {
        a = bankName[j]->getInitial();
        counter2++;
      }
      if (counter2 == 1)
      {
        b = bankName[j]->getInitial();
      }
    }
  }

  if ((a == 'd' && b == 'c') || (a == 'c' && b == 'd'))
    return 1;
  if ((a == 'c' && b == 'm') || (a == 'm' && b == 'c'))
    return 2;

  return 0;
}

bool riverbank::checkIfExists(animal* a)
{
  for (int i = 0; i < 3; i++)
  {
    if (bankName[i] != NULL)
    {
      if(bankName[i]->getInitial() == a->getInitial())
      {
        return true;
      }
    }
  }
  return false;
}

int riverbank::countAnimals()
{
  return count;
}

// ------ // ------ // setters // ------ // ------ //

//adds an animal to the animal array
void riverbank::addAnimal(animal* a)
{
	for (int i = 0; i < 3; i++)
	{
		if (bankName[i] == NULL)
		{
			bankName[i] = a; 
			count++;
			break;
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
        if (bankName[i] != NULL)
        {
            if (a->getInitial() == bankName[i]->getInitial())
            {
                bankName[i] = NULL;
                count--;
                break;
            }
        }
	}

}
