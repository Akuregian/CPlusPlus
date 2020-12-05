#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{

	public:
		Person();
		Person(std::string, std::string, int);

		void set_last_name(std::string);
		void set_first_name(std::string);
		void set_age(int);

		std::string get_first_name();
		std::string get_last_name();
		int get_age();

		void add_driver();
		void increment_age(int);

		std::string to_string();

	private:
		std::string m_first_name;
		std::string m_last_name;
		int m_age;

};

#endif
