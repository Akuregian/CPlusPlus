/*
   File: AddressBook.cpp
   Description: AndressBook Class Methods.
   Author: Anthony Kuregian
   Email: AnthonyKureian || Anthonk3371@student.vvc.edu
*/
#include"AddressBook.h"

AddressBook::AddressBook()
{
	m_street = "";
	m_city = "";
	m_state = "";
	m_zipcode = "";
	m_country = "";
}


AddressBook::AddressBook(std::string street, std::string city, std::string state, std::string zip, std::string country)
	: m_street(street), m_city(city), m_state(state), m_zipcode(zip), m_country(country)
{

}

void AddressBook::add_Resident(Person* p)
{
	Residents.push_back(p);
}

void AddressBook::print_residents()
{
	std::cout<< "--> Residents of Home: " << to_string() << std::endl;
	for(auto i : Residents)
	{
		std::cout << "- " << i->to_string() << std::endl;
	}
	std::cout<<std::endl;
}


void AddressBook::changeAddress(std::string street, std::string city, std::string state, std::string zip, std::string country)
{
	m_street = street;
	m_city = city;
	m_state = state;
	m_zipcode = zip;
	m_country = country;
}


void AddressBook::addAddress(std::string street, std::string city, std::string state, std::string zip, std::string country)
{
	m_street = street;
	m_city = city;
	m_state = state;
	m_zipcode = zip;
	m_country = country;
}

bool AddressBook::searchResident(std::string fname, std::string lname)
{
	for(int i = 0; i < Residents.size(); i++)
	{
		if(Residents[i]->getFirst() == fname && Residents[i]->getLast() == lname)
		{
			std::cout << "Found" <<std::endl;
			Residents[i]->changeName(fname, lname);
			return true;
		}

	}
	return false;
}

bool AddressBook::searchAddress(std::string street, std::string city, std::string state)
{
	bool var = false;
	if(m_street == street && m_city == city && m_state == state)
	{
		std::cout << "Found" <<std::endl;
		var = true;
	}
	else { var = false;}
	return var;
}

void AddressBook::changeResidentName(std::string fname, std::string lname, std::string newFirst, std::string newLast)
{
	for(int i = 0; i < Residents.size(); i++)
	{
		if(Residents[i]->getFirst() == fname && Residents[i]->getLast() == lname)
		{
			std::cout << "Found" <<std::endl;
			Residents[i]->changeName(newFirst, newLast);
		}
	}
}


std::string AddressBook::to_string()
{
	return m_street + ", " + m_city + ", " + m_state + ", " + m_zipcode + ", " + m_country;
}


std::string AddressBook::Residents_to_string(std::ofstream& file)
{
	for(auto i : Residents)
	{
		file <<  "\t- " << i->to_string() << ", " << std::endl;
	}
}

