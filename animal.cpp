//*include files*
#include <string>
#include "animal.h"

//*using namespace*
using namespace std;
					
//*Constructors*
animal::animal()
{
	// default constructor to be left empty. Only used for making sublcasses
}
animal::animal(char aInitial, string aSpecies)
{
	initial = aInitial;
	species = aSpecies;
}
		
//*getters*
char animal::getInitial()
{
	return initial;
}

string animal::getSpecies()
{
	return species;
}
string animal::makeSound(int repeats){
	// even if virtual, still needs to be defined. But can leave empty
	return "generic animal sound";
}

//*setters*
void animal::setInitial(char aInitial)
{
	initial = aInitial;
}
void animal::setSpecies(string aSpecies)
{
	species = aSpecies;
}

//*destructors*
animal::~animal()
{
	// leave blank for now
}
