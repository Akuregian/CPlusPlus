/*
 *
 * File: Polynomial.cpp
 * Description: Class Methods for polynomial class. 
 * Author: AnthonyKuregian@yahoo.com  ||  anthonyk3371@student.vvc.edu
 *
 * */

#include<iostream>
#include<string>
#include "Polynomial.h"

Polynomial::Polynomial() 
{
}

Polynomial::Polynomial(Term t) 
{
	m_polynomial.push_back(t);
}

void Polynomial::add(Term t)
{
	m_polynomial.push_back(t);
}

Polynomial Polynomial::multiply(Polynomial p)
{
	Polynomial productPolynomial; // Init the new poly class to store the new terms in
	std::list<Term> tmpList = p.returnList(); // Temp List of the other classes

	int a = tmpList.size(); // checks to see if one list is larger than the other
	int b = m_polynomial.size();
	int sumCoeff = 0;
	int sumPower = 0;


	if(a > b) // tmpList is larger, Iterate through m_poly
	{
		std::list<Term>::iterator It = m_polynomial.begin(); // Creates Iterator needed other classes list of Terms
		std::list<Term>::iterator tmpIt = tmpList.begin(); // Creates Iterator needed for this classes list of Terms
		// only Multiply numbers that have the same exponent number.

		while (It != m_polynomial.end())
		{
			sumCoeff = It->coefficient * tmpIt->coefficient; // Multiplies 1st coeff from class 1 and 1st coeff from class 2
			sumPower = It->power + tmpIt->power;
			productPolynomial.add(Term(sumCoeff, sumPower));
			It++;
			tmpIt++;
		}

		if (tmpIt != tmpList.end())
		{
			while (tmpIt != tmpList.end())
			{
				productPolynomial.add(Term(tmpIt->coefficient, tmpIt->power));
				tmpIt++;
			}
		}
	}
	else if(a < b) // m_polynomial is larger
	{
		std::list<Term>::iterator It = m_polynomial.begin(); // Creates Iterator needed other classes list of Terms
		std::list<Term>::iterator tmpIt = tmpList.begin(); // Creates Iterator needed for this classes list of Terms
		// only Multiply numbers that have the same exponent number.
		while (tmpIt != tmpList.end())
		{
			sumCoeff = It->coefficient * tmpIt->coefficient; // Multiplies 1st coeff from class 1 and 1st coeff from class 2
			sumPower = It->power + tmpIt->power;
			productPolynomial.add(Term(sumCoeff, sumPower));
			tmpIt++;
			It++;
		}
		if (It != m_polynomial.end())
		{
			while (It != m_polynomial.end())
			{
				productPolynomial.add(Term(It->coefficient, It->power));
				It++;
			}
		}
	}
	else if (a == b)
	{
		std::list<Term>::iterator It = m_polynomial.begin(); // Creates Iterator needed other classes list of Terms
		std::list<Term>::iterator tmpIt = tmpList.begin(); // Creates Iterator needed for this classes list of Terms
		// only Multiply numbers that have the same exponent number.
		while (tmpIt != tmpList.end() && It != m_polynomial.end())
		{
			sumCoeff = It->coefficient * tmpIt->coefficient; // Multiplies 1st coeff from class 1 and 1st coeff from class 2
			sumPower = It->power + tmpIt->power;
			productPolynomial.add(Term(sumCoeff, sumPower));
			tmpIt++;
			It++;
		}
	}
	
	return productPolynomial;
}

std::list<Term> Polynomial::returnList()
{
	return m_polynomial;
}

void Polynomial::printTerm()
{
	std::list<Term>::iterator it; // Creates Iterator for List<Term>
	for(it = m_polynomial.begin(); it != m_polynomial.end(); it++)
	{
		std::string coeff = std::to_string(std::abs(it->coefficient));
		std::string power = std::to_string(it->power);
		if (it->coefficient >= 0 && it != m_polynomial.begin())
		{
			std::cout << "+ ";
		}
		else if (it->coefficient < 0 && it != m_polynomial.begin())
		{
			std::cout << "- ";
		}
		std::cout << coeff + "x^" + power + " ";
	}
}
