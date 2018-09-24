// console compile line:
	// g++ -o testGame main-game.cpp animal.cpp cat.cpp dog.cpp mouse.cpp riverbank-array-two.cpp returnID.cpp

#include <iostream>
#include <string>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "mouse.h"
#include "riverbank-array-two.h"

using namespace std;

extern int returnID(string word);

int main(void)
{
//********** INITIALIZATION **********//
	// create animals
		cat* kitten = new cat;
		dog* puppy = new dog;
		mouse* stuart = new mouse;

	// create banks
		riverbank leftBank;
		leftBank.initialiseNULL();
		leftBank.addAnimal(kitten);
		leftBank.addAnimal(puppy);
		leftBank.addAnimal(stuart);

		riverbank rightBank;
		rightBank.initialiseNULL();

	// other initializations
		bool gameOver = false;
		string playerInput;
		int boatPosition = 0;	// 0 = boat on leftBank, 1 = boat on rightBank	//	can only add an animal to opposite bank and remove from current bank
	
	

//********** PLAY THE GAME **********//
	cout << "Game starting..." << endl << endl;

	// each run of this loop is a "turn"
	while(gameOver == false)
	{
		// at the beginning of each "turn", reset the playerInput (prevent looping an animal)
		playerInput = "null";

		// print game status
			// print left bank info
				cout << "There are " << leftBank.countAnimals() << " animals on the Left Bank. ";
				// if there is at least 1 animal on the bank...
				if(leftBank.countAnimals() != 0)
				{
					// if there is exactly 1 animal...
					if(leftBank.countAnimals() == 1)
					{
						cout << "It is the ";
					}
					// if there are 1+ animals...
					else
					{
						cout << "They are ";
					}
					// regardless, list the animal(s)
					leftBank.printBankStatus();
				}
				cout << endl;

			// print right bank info
				cout << "There are " << rightBank.countAnimals() << " animals on the Right Bank. ";
				// if there is at least 1 animal on the bank...
				if(rightBank.countAnimals() != 0)
				{
					// if there is exactly 1 animal...
					if(rightBank.countAnimals() == 1)
					{
						cout << "It is the ";
					}
					// if there are 1+ animals...
					else
					{
						cout << "They are ";
					}
					// regardless, list the animal(s)
					rightBank.printBankStatus();
				}
				cout << endl;

			// print/draw boat info
				cout << "The boat is currently on the ";
				if(boatPosition == 0)
				{
					cout << "Left Bank." << endl;
				}
				else
				{
					cout << "Right Bank." << endl;
				}

			cout << endl;



		// give user a chance for input
			cout << "Type an animal name to place that animal into the boat and send it to the other side, or PASS to move an empty boat." << endl;
			// while an invalid input
			while(returnID(playerInput) == 99)
			{	
				cin >> playerInput;
				//if still invalid after input, display message.
				if(returnID(playerInput) == 99)
				{
					cout << playerInput << " is an invalid input. Try again." << endl;
				}
			}

		// check if a game winning or losing combination (ie gameover) OR if game will go for another turn/loop

			// TEST ONLY - force gameOver after 1 move
				gameOver = true;
	}

	cout << endl << "Game closing..." << endl;



//********** TERMINATION **********//
	//deleting memory allocated
		delete kitten;
		delete puppy;
		delete stuart;
	return 0;
}
