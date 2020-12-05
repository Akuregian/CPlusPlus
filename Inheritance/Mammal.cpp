#include "Mammal.h"
#include <iostream>


Mammal::Mammal()
{
	std::cout << "Mammal::Mammal()" << std::endl;
}

void Mammal::eat()
{
	std::cout << "The Mammal Eats" << std::endl;
}
