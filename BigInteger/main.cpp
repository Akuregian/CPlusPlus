/*
 * File: main.cpp
 * Description: Class BigInteger Takes Large integers read in by strings and stores them as integers in a vector, while useing operator overloading too + - * / these class values.
 * Author: Anthony Kuregian
 * Email: anthonk3371@student.vvc.edu
*/

#include <iostream>
#include "BigInteger.h"

int main()
{

	BigInteger b1("123456789");
	BigInteger b2("987654321");

	std::cout << std::endl << "123456789 + 987654321 = " << b1+b2 << " <-- {Addition}" << std::endl;

	std::cout << "123456789 - 987654321 = " << b1-b2 << " <-- {Subtraction}" << std::endl;
	
	
	std::cout << "123456789 * 987654321 = " << b1*b2 << "  <-- Multiplication"<< std::endl;
	return 0;
}
