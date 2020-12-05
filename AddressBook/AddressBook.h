/*
   File: AddressBook.h 
   Description: AndressBook Class. The Address Class will contain a vector of <*Person> that stores each person	living at that address. I will have an array of AddressBooks, storing there own residents and addresses. Option will be giving to print out all the addresses to a text file.
   Author: Anthony Kuregian
   Email: AnthonyKureian || Anthonk3371@student.vvc.edu
*/

#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include<iostream>
#include<fstream>
#include<vector>
#include"Person.h"

class Person;

class AddressBook
{
	public:
		AddressBook();
		AddressBook(std::string, std::string, std::string, std::string, std::string);
		void add_Resident(Person*);
		void changeAddress(std::string, std::string, std::string, std::string, std::string);
		void addAddress(std::string, std::string, std::string, std::string, std::string);
		void print_residents();
		void changeResidentName(std::string, std::string, std::string, std::string);
		bool searchResident(std::string, std::string);
		bool searchAddress(std::string, std::string, std::string);

		std::string Residents_to_string(std::ofstream&);
		std::string to_string();

	private:
		std::vector<Person*> Residents;
		std::string m_FullAddy;
		std::string m_street;
		std::string m_city;
		std::string m_state;
		std::string m_zipcode;
		std::string m_country;

};

#endif
