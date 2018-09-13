//*include files*
#include <iostream>
#include <string>
#include "animal.h"
#include "cat.h"

//*using namespace*
using namespace std;

//*main*
int main(void)
{
	// start of main
	cout << "==== ==== ==== ==== ====" << endl << "Program starts here" << endl << "==== ==== ==== ==== ====" << endl;
	// create default animal using 2 input constructor
	animal defaultAnimal(117, "Undefined Animal");	// 117 = u
	cout << defaultAnimal.getSpecies() << " has the initial " << defaultAnimal.getInitial() << endl;
		// test setters
		defaultAnimal.setInitial(102);	//102 = f
		defaultAnimal.setSpecies("Fake Mouse");
		cout << defaultAnimal.getSpecies() << " has the initial " << defaultAnimal.getInitial() << endl;

	cout << endl;

	// create cat using default constructor
	cat kitten;
	cout << kitten.getSpecies() << " has the initial " << kitten.getInitial() << ". " << kitten.getSpecies() << "s go " << kitten.makeSound(2) <<endl;
		// test setters
		kitten.setInitial(100);	// 100 = d
		kitten.setSpecies("Dog");
		// still want to make cat sound as no matter what you call a cat, it doesn't change the fact that it IS a cat
		cout << kitten.getSpecies() << " has the initial " << kitten.getInitial() << ". " << kitten.getSpecies() << "s go " << kitten.makeSound(1) << "?" <<endl;

	// terminate main
	cout << "==== ==== ==== ==== ====" << endl << "Program ends here" << endl << "==== ==== ==== ==== ====" << endl;
	return 0;
}