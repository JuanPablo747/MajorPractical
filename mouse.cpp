// ------ // ------ // set-up // ------ // ------ //
#include "mouse.h"
#include <string>

using namespace std;

// ------ // constructors & destructors // ------ //

mouse::mouse() : animal(){
	initial = 'm';
	species = "Mouse";
}

mouse::~mouse(){};

// ------ // ------ // getters // ------ // ------ //

string mouse::makeSound(int repeats){
	string squeak = "";
	for(int i = 0; i < repeats; i++)
	{
		squeak = squeak + "Skrr";
		// if going for another loop, add a space
		if(i+1 != repeats)
		{
			squeak = squeak + " ";
		}
	}
	return squeak;
}
// ------ // ------ // setters // ------ // ------ //
