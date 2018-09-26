#include <iostream>
#include <string>
#include <cstdlib>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "mouse.h"
#include "riverbank-array-two.h"

using namespace std;

//********** PAUSE Function **********//

void pause(int dur)
{
    int temp = time(NULL) + dur;
    
    while(temp > time(NULL));
}



//********** return ID Function **********//



//this function will take in a string (which was originally gotten from the user) and return an integer. If the string is any
//variation of dog e.g. (dog, Dog, dOg, DOG, doG) it will return 1, same with cat but 2, mouse 3 and pass 4. If it doesnt satisfy any
//of these then it will return 99
int returnID(string word)
{
    //lenght of the word that was passed in
    int len = word.length();
    //Number of animals (always 4)
    const int noOfAnimals = 4;
    //string of the possible animals
    string animals[noOfAnimals] = {"dog", "cat", "mouse", "pass"};
    //different counters needed
    int counter;
    int animalID = 1;

    //This will iterate over every word in the animals[] array
    for (int k = 0; k < noOfAnimals; k++)
    {
        counter = 0;

        // if the length of the word passed in matches the length of the k'th animal in the animals array 
        if (len == animals[k].length())
        {
            // for each character in the word...
            for (int i = 0; i < len; i++)
            {
                // if any letter in the word entered is uppercase, change it to lowercase
                if (isupper(word[i]))
                {
                    word[i] = tolower(word[i]);
                }
                // if any character in the word passed in does not match the character in the word of the animals array
                //counter is increased by 1
                if (word[i] != animals[k][i])
                {
                    counter++;
                }
            }
            // if the word matches the word that is in the array, return animalID
            if (counter == 0)
            {
                return animalID;
            }
        }
        // animalID + 1 as we are moving onto the next animal in the array
        animalID++;
    }
    return 99;
}



//********** moveAnimal Function **********//



// function to move boat from 1 bank to another and move an animal (if any)
void moveAnimal(string playerInput, int* boatPosition, riverbank* leftBank, riverbank* rightBank, animal* adding){
	
	//We are using a for loop so need to store what animal we are adding that corresponds to the input
	for(int i = 1; i <= 4; i++)
	{
		//if a valid animal/pass...
		if(returnID(playerInput) == i)
		{
			// and the boat position is on the left
			//and i isnt the value for 'pass'
			if (i != 4)
			{
				//if on left move those animals
				if (*boatPosition == 0)
				{
					leftBank->removeAnimal(adding);
					rightBank->addAnimal(adding);
					*boatPosition = 1;
					break;
				}
				// else on right...
				else if (*boatPosition == 1)
				{
					leftBank->addAnimal(adding);
					rightBank->removeAnimal(adding);
					*boatPosition = 0;
					break;
				}

			}
			// if entered pass do 'special' move boat
			else if (i == 4)
			{
				if (*boatPosition == 0)
				{
					*boatPosition = 1;
					break;
				}
				else if (*boatPosition == 1)
				{
					*boatPosition = 0;
					break;
				}
			}
		}
	}
}
