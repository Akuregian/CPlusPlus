/*
 * File: BigInteger.h
 * Description: Class BigInteger Takes Large integers read in by strings and stores them as integers in a vector, while useing operator overloading too + - * / these class values.
 * Author: Anthony Kuregian
 * Email: anthonk3371@student.vvc.edu
*/

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstdlib>

class BigInteger
{
	public:
		BigInteger();
		~BigInteger();
		BigInteger(std::string);
		std::string operator+(BigInteger);
		std::string operator-(BigInteger);
		std::string operator*(BigInteger);

		void operator<<(std::ostream& BigInteger);
	private:
		std::vector<int> m_values;
		std::string m_resultString;
		
};


#endif
