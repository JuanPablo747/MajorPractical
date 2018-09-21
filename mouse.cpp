#include "mouse.h"
#include <string>

using namespace std;

mouse::mouse() : animal(){
	initial = 'm';
	species = "Mouse";
}

string mouse::makeSound(int repeats){
	string squeak = "";
	for(int i = 0; i < repeats; i++)
	{
		squeak = squeak + "Skrrr";
		// if going for another loop, add a space
		if(i+1 != repeats)
		{
			squeak = squeak + " ";
		}
	}
	return squeak;
}

mouse::~mouse(){};
