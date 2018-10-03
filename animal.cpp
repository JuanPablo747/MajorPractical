// ------ // ------ // set-up // ------ // ------ //
#include <string>
#include "animal.h"

using namespace std;

// ------ // constructors & destructors // ------ //

animal::animal()
{
	// default constructor to be left empty. Only used for making sublcasses
}

animal::animal(char aInitial, string aSpecies)
{
	initial = aInitial;
	species = aSpecies;
}

animal::~animal()
{
	// leave blank for now
}

// ------ // ------ // getters // ------ // ------ //

char animal::getInitial()
{
	return initial;
}

string animal::getSpecies()
{
	return species;
}

// string animal::makeSound(int repeats){
// 	// even if virtual, still needs to be defined. But can leave empty
// 	//return "generic animal sound";
// }	// changed to pure virtual; don't define here anymore

// ------ // ------ // setters // ------ // ------ //

void animal::setInitial(char aInitial)
{
	initial = aInitial;
}

void animal::setSpecies(string aSpecies)
{
	species = aSpecies;
}
