// ------ // ------ // set-up // ------ // ------ //
#include <string>
#include <iostream>
#include "cat.h"

using namespace std;

// ------ // constructors & destructors // ------ //

cat::cat() : animal()
{
	initial = 'c';
	species = "Cat";
	eats = "mouse";
}

cat::~cat()
{
	// leave blank for now
}

// ------ // ------ // getters // ------ // ------ //

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

void cat::drawAnimal(int frame){
	if(frame == 1)
	{
		cout << "      ╱╲    ╱╲  ╭━╮" << endl; 
		cout << "     ╱╱╲╲__╱╱╲╲ ╰╮┃" << endl;
		cout << "     ▏┏┳╮ ╭┳┓ ▕  ┃┃" << endl;
		cout << "     ▏╰┻┛▼┗┻╯ ▕  ┃┃" << endl;
		cout << "     ╲  ╰┻╯   ╱▔▔ ┃" << endl;
		cout << "      ╰━┳━━━ ╯    ┃" << endl;
		cout << "        ┃┏┓┣━━┳┳┓┃" << endl;
		cout << "        ┗┛┗┛  ┗┛┗┛" << endl;
	}
	
	else if (frame == 2)
	{
		cout << "      ╱╲    ╱╲  ╭━╮" << endl; 
		cout << "     ╱╱╲╲__╱╱╲╲ ╰╮┃" << endl;
		cout << "     ▏┏┳╮ ╭┳┓ ▕  ┃┃" << endl;
		cout << "  _  ▏╰┻┛▼┗┻╯ ▕  ┃┃" << endl;
		cout << "     ╲  ╰┻╯   ╱▔▔ ┃" << endl;
		cout << "  /  |╰━┳━━━ ╯    ┃" << endl;
		cout << " " << makeSound(1) << "   ┃┏┓┣━━┳┳┓┃" << endl;
		cout << "        ┗┛┗┛  ┗┛┗┛" << endl;
	}
}

// ------ // ------ // setters // ------ // ------ //
