//*include files*
#include <string>
#include "cat.h"

//*using namespace*
using namespace std;
					
//*Constructors*
cat::cat() : animal()
{
	initial = 99;	// in ASCII 99 = c
	species = "Cat";
	eats = "mouse";
}
		
//*getters*
string cat::makeSound(int repeats){
	string cry = "";
	for(int i = 0; i < repeats; i++)
	{
		cry = cry + "Meow";
		// if going for another loop, add a space
		if(i+1 != repeats)
		{
			cry = cry + " ";
		}
	}
	return cry;
}

//*setters*


//*destructors*
cat::~cat()
{
	// leave blank for now
}