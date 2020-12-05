/*
   File: Person.cpp
   Description: Person Class Methods.
   Author: Anthony Kuregian
   Email: AnthonyKureian || Anthonk3371@student.vvc.edu
*/
#include "Person.h"

Person::Person()
{
	m_first = "";
	m_last = "";
}

Person::Person(std::string first, std::string last) 
	: m_first(first), m_last(last)
{
}

void Person::setFirst(std::string f)
{
	m_first = f;
}

void Person::setLast(std::string l)
{
	m_last = l;
}

std::string Person::to_string()
{
	return m_last + " " +  m_first;
}

void Person::changeName(std::string fn, std::string ln)
{
	m_last = ln;
	m_first = fn;
}

std::string Person::getFirst()
{
	return m_first;
}

std::string Person::getLast()
{
	return m_last;
}
