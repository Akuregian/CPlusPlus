/*
   File: main.cpp
   Description: {Inheritance and Poymorphism} This File Uses Inheritance to create a base class called Animal, which will derive 3 sub classes, Reptile, Mammal and Insect. Each class will use POLYMORPHISM.
   Author: Anthony Kuregian
   Email: AnthonyKuregian@yahoo.com  ||  Anthonk3371@student.vvc.edu
*/
#include <vector>
#include "Mammal.h"
#include "Reptile.h"
#include "Insect.h"


int main()
{
	std::vector<Animal*> zoo; // Creates A Vector of Different Species

	zoo.push_back(new Mammal); // Push_back a Mammal
	zoo.push_back(new Reptile); // Push_back a Reptile
	zoo.push_back(new Insect); // Push_back a Insect

	for(Animal* animal : zoo)
	{
		animal->eat(); // Iterate through and print the eat func from each class, seperartly [virtual]
	}


   return 0;
}
