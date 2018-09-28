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

//********** start Function **********//

void start()
{
    string dots = ".";
    for (int i = 0; i < 3; i++)
    {
    system("clear");
    cout << "Game starting" << dots << endl << endl;
    dots.append(".");
    pause(1);
    }
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
void moveAnimal(string playerInput, int* boatPosition, riverbank* leftBank, riverbank* rightBank, animal* adding)
{
    for(int i = 1; i <= 4; i++)
    {
        //if a valid animal/pass...
        if(returnID(playerInput) == i)
        {
            //if is on left move those animals
            if (*boatPosition == 0)
            {
                // and if the animal entered is NOT on this bank AND didn't enter a pass...
                if(i != 4 && leftBank->checkIfExists(adding) == false)
                {
                    cout << "that animal is on the other bank." << endl;        // the comment is in the above window and gets cleared - got to fix where clear takes place
                    pause(2);
                    break;
                }
                // if animal entered is on this bank AND not giving a pass
                if (i != 4)
                {
                    leftBank->removeAnimal(adding);
                    rightBank->addAnimal(adding);
                    
                }
                // as long as any valid input was given, move the boat to the other side.
                 *boatPosition = 1;
                 break;
            }
            // else is on right...
            else if (*boatPosition == 1)
            {
                // and if the animal entered is NOT on this bank AND didn't enter a pass...
                if(i != 4 && rightBank->checkIfExists(adding) == false)
                {
                    cout << "that animal is on the other bank." << endl;        // the comment is in the above window and gets clear - got to fix where clear takes place
                    pause(2);
                    break;
                }
                // if animal entered is on this bank AND not giving a pass
                if (i != 4)
                {
                    leftBank->addAnimal(adding);
                    rightBank->removeAnimal(adding);
                }
                // as long as any valid input was given, move the boat to the other side.
                *boatPosition = 0;
                 break;
            }
        }
    }

}


//********** Print Bank Status **********//

void printBankStatus(riverbank* leftBank, riverbank* rightBank, int * boatPosition)
{
    // print game status
            // print left bank info
                cout << "There are " << leftBank->countAnimals() << " animals on the Left Bank. ";
                // if there is at least 1 animal on the bank...
                if(leftBank->countAnimals() != 0)
                {
                    // if there is exactly 1 animal...
                    if(leftBank->countAnimals() == 1)
                    {
                        cout << "It is the ";
                    }
                    // if there are 1+ animals...
                    else
                    {
                        cout << "They are ";
                    }
                    // regardless, list the animal(s)
                    leftBank->printBankStatus();
                }
                cout << endl;

            // print right bank info
                cout << "There are " << rightBank->countAnimals() << " animals on the Right Bank. ";
                // if there is at least 1 animal on the bank...
                if(rightBank->countAnimals() != 0)
                {
                    // if there is exactly 1 animal...
                    if(rightBank->countAnimals() == 1)
                    {
                        cout << "It is the ";
                    }
                    // if there are 1+ animals...
                    else
                    {
                        cout << "They are ";
                    }
                    // regardless, list the animal(s)
                    rightBank->printBankStatus();
                }
                cout << endl;

            // print/draw boat info
                cout << "The boat is currently on the ";
                if(*boatPosition == 0)
                {
                    cout << "Left Bank." << endl;
                }
                else
                {
                    cout << "Right Bank." << endl;
                }

            cout << endl;
}


//********** check if there is a losing combination Function **********//
//i.e. the dog and the cat are together and the boat is on the opposite riverbank


bool checkIfLosingCombo(riverbank* leftBank, riverbank* rightBank, int* boatPosition)
{
    // check if a game losing combination (ie gameover)
    if ((leftBank->checkPrey() == 1 && *boatPosition == 1) || (rightBank->checkPrey() == 1 && *boatPosition == 0))
    {
        cout << "You Lose! The dog ate the cat!" << endl;
        return true;
    }
    else if ((leftBank->checkPrey() == 2 && *boatPosition == 1) || (rightBank->checkPrey() == 2 && *boatPosition == 0))
    {
        cout << "You Lose! The cat ate the mouse!" << endl;
        return true;
    }
    else if ((leftBank->checkPrey() == 3 && *boatPosition == 1) || (rightBank->checkPrey() == 3 && *boatPosition == 0))
    {
        cout << "You Lose! The cat ate the mouse then the dog ate the cat!" << endl;
        return true;
    }
    return false;
}

//********** Animal to Add Function **********//


//basically uses the input from the player and returns the animal it corresponds to
animal* animalToAdd(string playerInput, animal* puppy, animal* kitten, animal* stuart, animal* blank)
{
    if(returnID(playerInput) == 1)
        return puppy;
    else if(returnID(playerInput) == 2)
        return kitten;
    else if (returnID(playerInput) == 3)
        return stuart;
    else
        return blank; // placeholder, shouldn't use this value but gauntees an 'adding' for proceeding function
} 



//********** TERMINATION **********//

//deleting memory allocated
void clearMemory(cat* kitten, dog* puppy, mouse* stuart, int* boatPosition, riverbank* leftBank, riverbank* rightBank, animal* blank)
{
    delete kitten;
    delete puppy;
    delete stuart;
    delete boatPosition;
    delete leftBank;
    delete rightBank;
    delete blank;
}
