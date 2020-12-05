#include "Person.h"

Person::Person()
{
	m_last_name = "No Name Inputed";
	m_first_name = "No Name Inputed";
	m_age = 0 ;
}

Person::Person(std::string first, std::string last, int age) :
	m_last_name(last),
	m_first_name(first),
	m_age(age)
{

}

void Person::set_first_name(std::string name)
{
	m_first_name = name;
}

void Person::set_last_name(std::string name)
{
	m_last_name = name;
}

void Person::set_age(int age)
{
	m_age = age;
}

int Person::get_age()
{
	return m_age;
}

void Person::increment_age(int inc)
{
	m_age += inc;
}

std::string Person::to_string()
{
	return m_last_name + " " + m_first_name;
}
