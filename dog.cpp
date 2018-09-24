// ------ // ------ // set-up // ------ // ------ //
#include <string>
#include "dog.h"

using namespace std;

// ------ // constructors & destructors // ------ //

dog::dog() : animal(){
	initial = 'd';
	species = "Dog";
	eats = "cat";
}

dog::~dog(){};

// ------ // ------ // getters // ------ // ------ //

string dog::makeSound(int repeats){
	string bark = "";
	for(int i=0;i<repeats;i++){
		bark = bark + "WOOF!";
		// if going for another loop, add a space
		if(i+1 != repeats)
		{
			bark = bark + " ";
		}
	}
	return bark;
}
// ------ // ------ // setters // ------ // ------ //
