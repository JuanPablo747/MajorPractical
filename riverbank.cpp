#include <string>
#include <iostream>
#include "riverbank.h"

using namespace std;

//constructors
Riverbank::Riverbank()
{
    bankName = new animal[3];
}

Riverbank::Riverbank(std::string name)
{
	//variables
}

//getters
//setters

Riverbank::~Riverbank()
{
	//delete any memory allocated by new
}
