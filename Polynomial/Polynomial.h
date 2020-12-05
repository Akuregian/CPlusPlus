/*
 *
 * File: Polynomial.h
 * Description: Polynomail class will used linked lists to store polynomails 
 * such as p(x) = 5x^10 + 9x^7 - x - 10 as (5, 10),(9, 7),(-1, 1),(10, 0). 
 * Member function will be added to add, mulitply and print polynomails.
 * Author: AnthonyKuregian@yahoo.com  ||  anthonyk3371@student.vvc.edu
 *
 * */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<list>

struct Term
{
	Term(int c, int p)
		: coefficient(c), power(p) { }
	int coefficient;
	int power;
};

class Polynomial
{
	public:
		Polynomial();
		Polynomial(Term);
		void add(Term);
		void printTerm();
		std::list<Term> returnList();
		Polynomial multiply(Polynomial);

	private:
		std::list<Term> m_polynomial;

};

#endif
