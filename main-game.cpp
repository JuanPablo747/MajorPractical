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
void pause(int dur);

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
	system("clear");
	cout << "Game starting..." << endl << endl;
	pause(2);
	// each run of this loop is a "turn"
	while(rightBank.checkBank() == false)
	{
		//clears the screen 
		system("clear");

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
				//geting input from the user
				cin >> playerInput;

				//if the player has given a valid input, proceed
				if(returnID(playerInput) != 99)
				{
					//We are using a for loop so need to store what animal we are adding that corresponds to the input
					animal* adding;
					if(returnID(playerInput) == 1)
						adding = puppy;
					else if(returnID(playerInput) == 2)
						adding = kitten;
					else if (returnID(playerInput) == 3)
						adding = stuart;

					//iterate through all possible valid player inputs i.e. 1, 2, 3, 4
					for(int i = 1; i <= 4; i++)
					{
						//if the player input = i
						if(returnID(playerInput) == i)
						{
							//and the boat position is on the left
							if(boatPosition == 0)
							{
								//and i isnt the value for 'pass'
								if (i != 4)
								{
									//move those animals
									leftBank.removeAnimal(adding);
									rightBank.addAnimal(adding);
									//delete adding;
								}
								//always change the position of the boat regardless if it is an animal or 'pass'
								boatPosition = 1;
								//break out of the for loop when an animal has been added/removed
								break;
							}
							//or the boat position is on the right
							else if (boatPosition == 1)
							{
								//and i isnt the value for 'pass'
								if (i != 4)
								{
									//move the animals
									leftBank.addAnimal(adding);
									rightBank.removeAnimal(adding);
									//delete adding;
								}
								//always change the position of the boat regardless if it is an animal or 'pass'
								boatPosition = 0;
								//break out of the for loop when an animal has been added/removed
								break;
							}
						}
					}
				}
				//else if still invalid after input, display message.
				else
				{
					cout << playerInput << " is an invalid input. Try again." << endl;
				}
			}
		

		// check if a game winning or losing combination (ie gameover) OR if game will go for another turn/loop

			// TEST ONLY - force gameOver after 1 move
				//gameOver = true;
	}

	cout << endl << "Game closing..." << endl;



//********** TERMINATION **********//
	//deleting memory allocated
	delete kitten;
	delete puppy;
	delete stuart;
	return 0;
}

void pause(int dur)
{
    int temp = time(NULL) + dur;
    
    while(temp > time(NULL));
}
