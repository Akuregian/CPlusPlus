#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <vector>
#include <string>

#include "Person.h"

class Car

{
	public:
		Car();
		Car(std::string, std::string);
		void add_Owner(Person*);
		void add_Driver(Person*);
		void increment_ages(int);

		std::string print_owners();
		std::string print_drivers();
		std::string to_string();

	private:
		std::string m_Model;
		std::string m_id;
		std::vector<Person*> m_owners;
		std::vector<Person*> m_drivers;
};


#endif
