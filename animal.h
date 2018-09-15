// guards
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class animal
{
	//*States*						// protected,since child inherets from parent
	protected:				
		char initial;				// first letter of species name for easier input
		std::string species; 		// whole species name (cat, dog, mouse)
	//*Behaviours*
	public:					
		//*Constructors*
		animal();					// default constructor to allow creation of children classes
		animal(char aInitial, std::string aSpecies);	// this constructor could be subject to change if we add more characteristics, or we could use setters

		//*getters*
		char getInitial();			// could use for searching what is stored at a pointer
		std::string getSpecies();	// mainly used for displaying to player
		virtual std::string makeSound(int repeats);
			// -> don't want "pure virtual, ie "virtual std::string makeSound() = 0" because we can have a "generic animal", its the unclassified one. We aren't buidling a subclass for it.
			// -> choose string so we can choose to print it or not later. This could be changed later.

		//*setters*					// we may not need these and could take them out later, but could be useful at least for testing, etc
		void setInitial(char aInitial);
		void setSpecies(std::string aSpecies);
		
		//*destructors*
		~animal();
};

#endif