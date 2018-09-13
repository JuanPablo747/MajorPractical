#include <iostream>

#include "animal.h"
#include "riverbank.h"

using namespace std;

int main(void)
{
	//intilise 3 'blank' animals
	animal blank1;
	animal blank2;
	animal blank3;

	//initialise a blank riverbank
	riverbank A;

	//add the blank animals to the array (we need them so the printer knows what to print)
	A.addAnimal(blank1);
	A.addAnimal(blank2);
	A.addAnimal(blank3);

	//print empty array
	A.printBankStatus();

	//initialise a dog, cat and mouse
	animal dog('d', "dog");
	animal cat('c', "cat");
	animal mouse('m', "mouse");

	//add those animals to the riverbank
	A.addAnimal(dog);
	A.addAnimal(cat);
	A.addAnimal(mouse);

	//print that riverbank with the animals
	A.printBankStatus();

	cout << "Are all animals in the array? ";
	if (A.checkBank() == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	//remove an animal
	A.removeAnimal(dog);

	//print the riverbank with the dog removed
	A.printBankStatus();

	cout << "Are all animals in the array? ";
	if (A.checkBank() == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;



	return 0;
}