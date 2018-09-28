// console compile line:
	// g++ -o testGame main-game.cpp animal.cpp cat.cpp dog.cpp mouse.cpp riverbank-array-two.cpp extraFunctions.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "mouse.h"
#include "riverbank-array-two.h"

using namespace std;

extern void start();
extern int returnID(string word);
extern void moveAnimal(string playerInput, int* boatPosition, riverbank* leftBank, riverbank* rightBank, animal* adding);
extern void pause(int dur);
extern void printBankStatus(riverbank* leftBank, riverbank* rightBank, int * boatPosition);
extern animal* animalToAdd(string playerInput, animal* puppy, animal* kitten, animal* stuart, animal* blank);
extern bool checkIfLosingCombo(riverbank* leftBank, riverbank* rightBank, int* boatPosition);
extern void clearMemory(cat* kitten, dog* puppy, mouse* stuart, int* boatPosition, riverbank* leftBank, riverbank* rightbank, animal* blank);

int main(void)
{
//********** INITIALIZATION **********//

// create animals
	cat* kitten = new cat;
	dog* puppy = new dog;
	mouse* stuart = new mouse;
	animal* blank = new animal('b', "blank animal");
	animal* adding;	// animal we are moving after player enters an input

// create riverbanks
	riverbank *leftBank = new riverbank;
	leftBank->initialiseNULL();
	leftBank->addAnimal(kitten);
	leftBank->addAnimal(puppy);
	leftBank->addAnimal(stuart);

	riverbank *rightBank = new riverbank;
	rightBank->initialiseNULL();

// other initializations
	string playerInput;
	int* boatPosition = new int(0);	// 0 = left, 1 = right
	

//********** PLAY THE GAME **********//

	//clearing the screen and starting the game
	start();

	//Game will run until there are 3 animals in the right riverbank, every time it runs it is a 'turn'
	while(rightBank->checkBank() == false)
	{
		//clears the screen 
		system("clear");

		// at the beginning of each "turn", reset the playerInput (prevent looping an animal)
		playerInput = "null";

		// print game status
		printBankStatus(leftBank, rightBank, boatPosition);

		// give user a chance for input
		cout << "Which animal do you want to move? Type pass to just move the boat: " << endl;

		// while an invalid input
		while(returnID(playerInput) == 99)
		{	
			//geting input from the user
			cin >> playerInput;

			//if the player has given a valid input, proceed
			if(returnID(playerInput) != 99)
			{
				//get which animal is going to be moved and store it in adding
				adding = animalToAdd(playerInput, puppy, kitten, stuart, blank);

				//perform the move from one bank to the next
				moveAnimal(playerInput, boatPosition, leftBank, rightBank, adding);

				//Check if it is a losing combination e.g. The cat and the mouse are together but the boat is on the otherside
				if (checkIfLosingCombo(leftBank, rightBank, boatPosition) == true)
				{
					clearMemory(kitten, puppy, stuart, boatPosition, leftBank, rightBank, blank);
					return 0;
				}	
			}
			//else if still invalid after input, display message.
			else
			{
				cout << playerInput << " is an invalid input. Try again." << endl;
				pause(2);
				break;
			}
		}
	}

	cout << endl << "Game closing..." << endl;



//********** TERMINATION **********//
	clearMemory(kitten, puppy, stuart, boatPosition, leftBank, rightBank, blank);
	return 0;
}
