// Use this to complile tests
// g++ -o testAll testAll.cpp animal.cpp cat.cpp dog.cpp mouse.cpp riverbank-array-two.cpp extraFunctions.cpp

#include <iostream>
#include <string>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "mouse.h"
#include "riverbank-array-two.h"

using namespace std;

extern int returnID(string word);
extern void moveAnimal(string playerInput, int* boatPosition, riverbank* leftBank, riverbank* rightBank, animal* adding);
extern void pause(int dur);

int main(void)
{
	cout << endl << "==== ==== ==== ==== ====" << endl << "Program starts here" << endl << "==== ==== ==== ==== ====" << endl << endl;

	//********** Testing creating all the animals **********//

	//Testing creating an animal and setting it's initial and species

	cout << "TESTING ANIMALS" << endl << endl;

	// cout << "test: create animal with default generic animal constructor..." << endl;
	// animal defaultAnimal(117, "Undefined Animal");	// 117 = u, pure virtual; can't do this anymore 

	//testing getters
		// cout << defaultAnimal.getSpecies() << " has the initial " << defaultAnimal.getInitial() << endl;
		// cout << endl;

	// // test setters
	// cout << "test: use setters to re-define undefined animal..." << endl;
	// defaultAnimal.setInitial(99);	//102 = c
	// defaultAnimal.setSpecies("Fake Cat");
	// cout << defaultAnimal.getSpecies() << " has the initial " << defaultAnimal.getInitial() << endl;
	// cout << endl;

	// Creating animal pointers to a cat, dog and mouse and testing their functions
	cout << "test: create cat with cat constructor, then get species, initial and sound..." << endl;
	cat* kitten = new cat;
	cout << kitten->getSpecies() << " has the initial " << kitten->getInitial() << ", " << kitten->getSpecies() << "'s go " << kitten->makeSound(2) <<endl;
	cout << endl;
	cout << "test: create dog with dog constructor, then get species, initial and sound..." << endl;
	dog* puppy = new dog;
	cout << puppy->getSpecies() << " has the initial " << puppy->getInitial() << ", " << puppy->getSpecies() << "'s go " << puppy->makeSound(2)<<endl;
	cout << endl;
	cout << "test: create mouse with mouse constructor, then get species, initial and sound..." << endl;
	mouse* stuart = new mouse;
	cout << stuart->getSpecies() << " has the initial " << stuart->getInitial() << ", " << stuart->getSpecies() << "'s go " << stuart->makeSound(2)<<endl;
	

	//********** Testing returnID function **********//

	//the function take a string and retuns an integer 1 for dog or any variation (dOg, Dog, doG), 2 for cat, 3 for mouse or 4 for pass
	cout << endl << endl <<"TESTING RETURN ID FUNCTION" << endl;
	cout << "the following tests return the ID of the animal when different inputs are inserted..." << endl;
	cout << "// 1 = dog; 2 = cat; 3 = mouse; 4 = successful_pass; 99 = failed entry" << endl << endl;

	cout << "test: different casing of the same word..." << endl;
	cout << "Dog - If this works, will print 1: " << returnID("dog") << endl;
	cout << "DOg - If this works, will print 1: " << returnID("dOg") << endl;
	cout << "DoG - If this works, will print 1: " << returnID("doG") << endl;
	cout << "DOG - If this works, will print 1: " << returnID("DOG") << endl;
	cout << endl;

	cout << "test: different valid words..." << endl;
	cout << "Cat - If this works, will print 2: " << returnID("cat") << endl;
	cout << "Mouse - If this works, will print 3: " << returnID("mouse") << endl;
	cout << "Pass - If this works, will print 4: " << returnID("pass") << endl;
	cout << endl;

	cout << "test: an unrecognised word..." << endl;
	cout << "Blah - If this works, will print 99: " << returnID("Blah") << endl;


	//********** Testing riverbank class and its functions **********//

	cout << endl << endl << "TESTING RIVERBANK CLASS" << endl << endl;
	// default riverbank constructor
	riverbank A;

	//initialiseNULL() test
	A.initialiseNULL();
	animal** a = A.returnArray();
	cout << "Testing initialiseNULL() function" << endl;
		cout << "if it prints NULL three times, the function works" << endl;
		cout << "// NULL = empty entry in i'th element of array" << endl;
		cout << "Prints: ";
	for(int i = 0; i < 3; i++)
		if (a[i]==NULL)
			cout << "NULL" << " ";

	cout << endl;

	cout << endl << endl << "Testing checkPrey() function" << endl;
		cout << "if it prints 0, the function works" << endl;
		cout << "// 0 = empty bank, impossible for this bank to cause Game Over" << endl;
		cout << "Prints: " << A.checkPrey();
	cout << endl << endl;

	//testing adding animals to the array and the print function
	cout << "Testing addAnimal() function" << endl;
	A.addAnimal(kitten);
	A.addAnimal(puppy);
	A.addAnimal(stuart); 
	cout << "If this works, will print Cat Dog and Mouse" << endl;
	cout << "Prints: ";
	A.printBankStatus();

	//testing the make sound function (polymorphism)
	cout << endl << "Testing makeSound() function" << endl;
	cout << endl << "tests if its possible to call sound of animals in riverbank array" << endl;
	animal** b = A.returnArray();
	for(int j = 0; j < 3; j++) cout << b[j]->makeSound(5) << endl;
	

	cout << endl << "Testing checkPrey() function" << endl;
		cout << "if it prints 3, the function works" << endl;
		cout << "// 3 = full bank, impossible for this bank to cause Game Over" << endl;
		cout << "Prints: " << A.checkPrey();
	cout << endl;


	//if all animals are in the array, returns true
	cout << "Testing checkBank() function on full array" << endl;
	cout << "if it prints true, the function works" << endl;
	cout << "// true = full array; false = there is a null/empty element(s)" << endl;
	if (A.checkBank() == true)
		cout << "Prints: true" << endl << endl;

	//testing removing animals to the array
	cout << "Testing removeAnimal() function - remove a dog" << endl;
	A.removeAnimal(puppy);
	cout << "If this works, will print Cat and Mouse" << endl;
	cout << "Prints: ";
	A.printBankStatus();

	cout << endl << "Testing checkPrey() function" << endl;
		cout << "if it prints 2, the function works" << endl;
		cout << "// 2 = cat eats mouse" << endl;
		cout << "Prints: " << A.checkPrey();

	cout << endl << "Testing checkPrey() function on array with Cat and Mouse" << endl;
	cout << "if it prints true, the function works" << endl;
	if (A.checkPrey() == 2)
		cout << "Prints: true" << endl << endl;

	cout << endl << "Testing checkBank() function on partly full array" << endl;
	cout << "if it prints false, the function works" << endl;
	if (A.checkBank() == false)
		cout << "Prints: false" << endl << endl;

	cout << "Testing checkIfExists() function on array with Cat and Mouse (searching for cat)" << endl;
	cout << "purpose: ensure can 'collect' cat if cat DOES exist in this bank" << endl;
	cout << "if it prints true, the function works" << endl;
	if (A.checkIfExists(kitten) == true)
		cout << "Prints: true" << endl << endl;


	cout << "Testing checkIfExists() function on array with Cat and Mouse (searching for dog)" << endl;
	cout << "purpose: ensure can't 'collect' dog if dog isn't in this bank" << endl;
	cout << "if it prints false, the function works" << endl;
	if (A.checkIfExists(puppy) == false)
		cout << "Prints: false" << endl;


	//deleting memory allocated
	delete kitten;
	delete puppy;
	delete stuart;

	cout << endl << "==== ==== ==== ==== ====" << endl << "Program ends here" << endl << "==== ==== ==== ==== ====" << endl;


}

