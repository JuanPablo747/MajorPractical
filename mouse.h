#ifndef MOUSE_H
#define MOUSE_H

#include "animal.h"
#include <string>

class mouse : public animal{
	//*States*

	//*Behaviours*
	public:
		mouse();
		std::string makeSound(int repeats);
		void drawAnimal(int frame);
		~mouse();
};

#endif
