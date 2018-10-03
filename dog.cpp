// ------ // ------ // set-up // ------ // ------ //
#include <string>
#include <iostream>
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
		bark = bark + "Woof";
		// if going for another loop, add a space
		if(i+1 != repeats)
		{
			bark = bark + " ";
		}
	}
	return bark;
}

void dog::drawAnimal(int frame){
	if(frame == 1)
	{
		cout << "    ╱▏      ▕╲▕╲" << endl;
		cout << "    ▏▏      ▕▏▔▔╲" << endl;
		cout << "    ▏╲      ╱ ▔ ▔╲" << endl;
		cout << "    ╲▏▔▔▔▔▔▔╯╯╰┳━━▀" << endl;
		cout << "     ▏╯╯╯╯╯╯╯╯╱┃" << endl;
		cout << "     ┃┏┳┳━━━┫┣┳┃" << endl;
		cout << "     ┃┃┃┃   ┃┃┃┃" << endl;
		cout << "     ┗┛┗┛   ┗┛┗┛" << endl;
	}
	
	else if (frame == 2)
	{
		cout << "    ╱▏      ▕╲▕╲" << endl;
		cout << "    ▏▏      ▕▏▔▔╲" << endl;
		cout << "    ▏╲      ╱ ▔ ▔╲" << endl;
		cout << "    ╲▏▔▔▔▔▔▔╯╯╰┳━━▀" << endl;
		cout << "     ▏╯╯╯╯╯╯╯╯╱┃ / | \\" << endl;
		cout << "     ┃┏┳┳━━━┫┣┳┃  " << makeSound(1) << endl;
		cout << "     ┃┃┃┃   ┃┃┃┃" << endl;
		cout << "     ┗┛┗┛   ┗┛┗┛" << endl;
	}
}

// ------ // ------ // setters // ------ // ------ //
