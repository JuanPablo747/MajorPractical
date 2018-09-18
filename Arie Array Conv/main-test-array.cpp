#include <iostream>
#include <vector>

#include "animal.h"
#include "riverbank-array.h"
#include "cat.h"

using namespace std;

int main(void)
{
	//initialise a blank riverbank
	riverbank A;

	//initialise a dog, cat and mouse
	animal* dog = new animal('d', "dog");
	cat* Cat = new cat;
	animal* mouse = new animal('m', "mouse");
	
	//add those animals to riverbank A
	A.bankStorage[0] = dog;
	A.bankStorage[1] = Cat;
	A.bankStorage[2] = mouse;

	//initialise end bank
	riverbank B;
	for(int i = 0; i < B.getMaxCapacity(); i++)
	{
		B.bankStorage[i] = NULL;
	}
	

	//print that riverbank with the animals
	A.printBankStatus();

	cout << "Are all animals in the array? ";
	if (A.checkBank() == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	//remove an animal
	A.removeAnimal(dog);
	cout << Cat->makeSound(2) << endl;

	//print the riverbank with the dog removed
	A.printBankStatus();

	cout << "Are all animals in the array? ";
	if (A.checkBank() == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;


	animal** print = A.returnArray();

	cout << "Making sounds" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << print[i]->makeSound(1) << endl;
	}

	return 0;
}
