#ifndef DOG_H
#define DOG_H

#include "animal.h"
#include <string>

class dog : public animal{
	//*States*
	std::string eats;
	//*Behaviours*
	public:
		dog();
		std::string makeSound(int repeats);
		~dog();
};

#endif
