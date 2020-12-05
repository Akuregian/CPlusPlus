/*
 *
 * File: main.cpp
 * Description: This File will contain the driver code for the Polynomail class. Polynomail class will used linked lists
 * 		to store polynomails such as p(x) = 5x^10 + 9x^7 - x - 10 as (5, 10),(9, 7),(-1, 1),(10, 0). Member function will be added to add, mulitply and print polynomails.
 * 		Also Polynomial consutructors can make a single term using Polynomial(Term(-10, 0));
 * Author: AnthonyKuregian@yahoo.com  ||  anthonyk3371@student.vvc.edu
 *
 * */

#include<iostream>
#include"Polynomial.h"

int main()
{
	Polynomial p1(Term(10, 2));
	p1.add(Term(-1, 5));
	p1.add(Term(3, 2));
	p1.add(Term(7, 3));

	Polynomial p2(Term(2, 5));
	p2.add(Term(7, 1));
	p2.add(Term(3, 0));
//	p2.add(Term(4, 4)); // Can Commented out or add more terms if you wanted

	std::cout << "(";
	p1.printTerm(); 
	std::cout << ") * (";
	p2.printTerm(); 
	std::cout << ")";

	Polynomial product = p1.multiply(p2);
	std::cout << " = ("; 
	product.printTerm(); std::cout << ")" <<std::endl;

	return 0;
};
