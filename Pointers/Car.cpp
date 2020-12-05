#include "Car.h"

Car::Car()
{
	m_Model = "No Model";
}

Car::Car(std::string id, std::string model) :
	m_Model(model), m_id(id)
{

}
void Car::add_Owner(Person *p)
{
	m_owners.push_back(p);
}

std::string Car::to_string()
{
	return m_id + ", " + m_Model;
}

std::string Car::print_owners()
{
	std::cout << "Vehicle Owners are: " << std::endl;
	for(auto o : m_owners)
	{
		std::cout << "\t" << o->to_string() + ", ";
		std::cout << "Owners Age: " << o->get_age() << std::endl;
	}
	std::cout << std::endl;
}

void Car::add_Driver(Person *person)
{
	m_drivers.push_back(person);
}

std::string Car::print_drivers()
{
	std::cout << "Vehicle Drivers are: " << std::endl << "\t";
	for(auto d : m_drivers)
	{
		std::cout << " - " <<d->to_string() << ", Age: " << d->get_age();
	}
	std::cout << std::endl;
}


void Car::increment_ages(int incrementation)
{
	for(auto p : m_owners)
	{
		p->increment_age(incrementation);
	}

	for(auto p : m_drivers)
	{
		p->increment_age(incrementation);
	}
}
