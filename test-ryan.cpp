#include <iostream>
#include "animal.h"
#include "cat.h"
#include "riverbank-array-two.h"

using namespace std;

int main(void)
{
	riverbank A;
	riverbank B;

	A.initialiseNULL();
	B.initialiseNULL();

	animal* dog = new animal('d', "dog");
	cat* Cat = new cat;
	animal* mouse = new animal('m', "mouse");

	A.addAnimal(dog);
	A.addAnimal(Cat);
	A.addAnimal(mouse);

	A.printBankStatus();

	A.removeAnimal(Cat);

	A.printBankStatus();


	return 0;
}