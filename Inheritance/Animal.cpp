#include "Animal.h"

Animal::Animal()
{
	std::cout << "Animal::Animal()[BASE CLASS]" << std::endl;
}

void Animal::eat()
{
	std::cout << "Animal is eating" << std::endl;
}
