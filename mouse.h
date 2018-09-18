#ifndef MOUSE_H
#define MOUSE_H

#include "animal.h"
#include <string>

class mouse : public animal{

	public:
		mouse();
		std::string makeSound(int repeats);


	~mouse();
};

#endif