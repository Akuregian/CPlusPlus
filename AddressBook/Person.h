/*
   File: Person.h 
   Description: Person Class. Class Contains the informatio regarding each resident that lives insides the home. This Class will be implemented as an vector within the AddressBook class.
   Author: Anthony Kuregian
   Email: AnthonyKureian || Anthonk3371@student.vvc.edu
*/

#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>

class Person // Struct Person Contained points too the Address of Each Person
{
	public:
		Person();
		Person(std::string, std::string);
		void setFirst(std::string);
		void setLast(std::string);
		void changeName(std::string fn, std::string ln);
		std::string getFirst();
		std::string getLast();

		std::string to_string();

	private:
		std::string m_first;
		std::string m_last;
};

#endif
