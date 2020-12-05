/*
   File: Main.cpp
   Description: Has Car and Person Class. Car Class Points to the Owner and Drivers while representing its model
   Author: Anthony Kuregian
   Email: AnthonyKuregian@yahoo.com || Anthonk3371@student.vvc.edu
*/

#include <iostream>
#include "Person.h"
#include "Car.h"

int main()
{
	Person *pPtr1 = new Person("Anthony", "Kuregian", 26); // Owner
	Person *pPtr2 = new Person("Ronald","Steales", 61); // Driver
	Person *pPtr3 = new Person("Stewart", "Martinio", 21); // Driver
	Person *pPtr4 = new Person("Harley", "Foogazi", 43); // Owner
	Person *pPtr5 = new Person("Marky", "Mark", 22); // Driver
	Person *pPtr6 = new Person("Breezey","Ocean", 86); // Owner
	Person *pPtr7 = new Person("Wendy","Breeze", 71); // Owner
	Person *pPtr8 = new Person("Markus", "Montgomery", 16); // Driver

	Car *c1 = new Car("01", "Porche");
	Car *c2 = new Car("02", "Ferrarri Enzo");
	Car *c3 = new Car("03", "Tesla");

	/*------------------------------------------------------------------ Add Owners and Drivers*/

	c1->add_Owner(pPtr1);
	c1->add_Driver(pPtr2);
	c1->add_Driver(pPtr3);

	c2->add_Owner(pPtr4);
	c2->add_Driver(pPtr5);
	 
	c3->add_Owner(pPtr6);
	c3->add_Owner(pPtr7);
	c3->add_Driver(pPtr8);

	/*------------------------------------------------------------------------------------------*/

	
	/*------------------------------------------------------------------ Print Out Owners, Drivers and Model*/

	std::cout << "-------------------------------------" << std::endl;
	std::cout << c1->to_string() << std::endl;
	c1->print_owners();
	c1->print_drivers();
	std::cout << "-------------------------------------" << std::endl;

	std::cout << "-------------------------------------" << std::endl;
	std::cout << c2->to_string() << std::endl;
	c2->print_owners();
	c2->print_drivers();
	std::cout << "-------------------------------------" << std::endl;


	std::cout << "-------------------------------------" << std::endl;
	std::cout << c3->to_string() << std::endl;
	c3->print_owners();
	c3->print_drivers();
	std::cout << "-----------------------------------------------------------" << std::endl;


	std::cout << "...Incrementing Ages of ALL drivers" << std::endl;

	int AGE_INCREMENTATION = 1;

	c1->increment_ages(AGE_INCREMENTATION);
	c2->increment_ages(AGE_INCREMENTATION);
	c3->increment_ages(AGE_INCREMENTATION);
	
	std::cout << "-----------------------------------------------------------" << std::endl;
	std::cout << c1->to_string() << std::endl;
	c1->print_owners();
	c1->print_drivers();
	std::cout << "-------------------------------------" << std::endl;

	std::cout << "-------------------------------------" << std::endl;
	std::cout << c2->to_string() << std::endl;
	c2->print_owners();
	c2->print_drivers();
	std::cout << "-------------------------------------" << std::endl;


	std::cout << "-------------------------------------" << std::endl;
	std::cout << c3->to_string() << std::endl;
	c3->print_owners();
	c3->print_drivers();
	std::cout << "-------------------------------------" << std::endl << std::endl;

 	return 0;
}
