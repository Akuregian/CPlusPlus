/*
 * File: main.cpp
 * Description: All the Methods from the BigInteger.h class 
 * Author: Anthony Kuregian
 * Email: anthonk3371@student.vvc.edu
*/

#include "BigInteger.h"

BigInteger::BigInteger()
{
	std::cout << "No Values were inputed" << std::endl;
}
BigInteger::~BigInteger()
{
	m_values.clear();
}


BigInteger::BigInteger(std::string num)
{
	if(num.length() == 1 && num[0] == '0')
	{
		std::cout << "Value is 0" << std::endl;
	}

	for(int i = 0; i < num.length(); i++)
	{
		int t = int(num[i] - '0'); // Basically Subtracts the Ascii Values, resulting in the chars number.
		m_values.push_back(t);
	}
}	

std::string BigInteger::operator+(BigInteger a)
{
	int sum = 0;
	int carry = 0; // Creates Carry Variable
	std::string m_resultValue; // String var to hold the sum

	if(m_values.size() != a.m_values.size()) // Check to see if sizes are equal, if not, add some leading zeros
	{
		int asize = m_values.size();
		int bsize = a.m_values.size();
		int diff = abs(asize - bsize);

		if(m_values.size() > a.m_values.size())
		{
			for(int i = 0; i < diff; i++) 
			{ 
				auto it = a.m_values.begin();
				it = a.m_values.insert(it, 0);
			}
		}
		else
		{
			for(int i = 0; i < diff; i++) 
			{ 
				auto it = m_values.begin();
				it = m_values.insert(it, 0);
			}

		}

	}


	if(m_values.size() ==  a.m_values.size())
	{
		std::string c;
		for(int i = m_values.size() - 1; i >= 0; i--)
		{
			sum = 0;
			int sum = m_values[i] + a.m_values[i]; // Adding last elements together
			if(carry == 1) {sum +=  carry; carry = 0;}
			carry =  sum/10; // Find out carry value
			// append to back of the vector
			c = std::to_string(sum);
			if(i != 0)
			{
				if(carry > 0) {m_resultValue = c[1] + m_resultValue;}
				else {m_resultValue = c + m_resultValue;}
			}
			else 
			{
				m_resultValue = c + m_resultValue;
			}
		}

	}

	return m_resultValue;
};

std::string BigInteger::operator-(BigInteger a)
{
	
	int sum = 0;
	int carry = 0; // Creates Carry Variable
	std::string m_resultValue;

	if(m_values.size() != a.m_values.size())
	{
		int asize = m_values.size();
		int bsize = a.m_values.size();
		int diff = abs(asize - bsize);

		if(m_values.size() > a.m_values.size())
		{
			for(int i = 0; i < diff; i++) 
			{ 
				auto it = a.m_values.begin();
				it = a.m_values.insert(it, 0);
			}
		}
		else
		{
			for(int i = 0; i < diff; i++) 
			{ 
				auto it = m_values.begin();
				it = m_values.insert(it, 0);
			}

		}
	}
		
	if(m_values.size() == a.m_values.size())
	{
	       std::string c;

	       for(int i = m_values.size() - 1; i >= 0; i--)
	       {
		       if(m_values[0] > a.m_values[0])
		       {
			       if(m_values[i] < a.m_values[i])
			       {
					m_values[i-1] -= 1;
					m_values[i] += 10;
					sum = m_values[i] - a.m_values[i];
					c = std::to_string(sum);
					m_resultValue = c + m_resultValue;
			       }
			       else
			       {
				       sum = m_values[i] - a.m_values[i];
				       c = std::to_string(sum);
				       m_resultValue = c + m_resultValue;
			       }
			}
			else if(m_values[0] < a.m_values[0])
			{
				if(a.m_values[i] < m_values[i])
				{
					a.m_values[i-1] -= 1;
					a.m_values[i] += 10;
					sum = abs(a.m_values[i] - m_values[i]);
					c = std::to_string(sum);
					m_resultValue = c + m_resultValue;
				}
			        else
			        {
				       sum = abs(m_values[i] - a.m_values[i]);
				       c = std::to_string(sum);
				       m_resultValue = c + m_resultValue;
			        }
			}

	       }

       }	

	return m_resultValue;
}

std::string BigInteger::operator*(BigInteger a)
{
	int minSize = 0;
	int maxSize = 0;
	int carry = 0;
	int sum = 0;
	int num1_index = 0;
	int num2_index = 0;
	// check to see if Lengths are equal
	if(m_values.size() > 0 || a.m_values.size() > 0)
	{
		if(m_values.size() > a.m_values.size()) {minSize = a.m_values.size(); maxSize = m_values.size();}
		else { minSize = m_values.size(); maxSize = a.m_values.size();}

	} else{return "0";}

	std::vector<int> results(m_values.size() + a.m_values.size(), 0);
	for(int i = maxSize; i >= 0; i--) // Loop Through the Larger number
	{
		for(int j = minSize; j >= 0; j--) // Check the smaller number to each index of larger
		{
			sum = m_values[i] * a.m_values[j] + carry;
			carry = sum/10; // Get Carry value for the iteration coming up
			results[num1_index + num2_index] = sum;
			num2_index++;
		}

		if(carry > 0){results[num1_index + num2_index] += carry;}
		num1_index++;

	}
	for(int i = results.size() - 1; i >= 0; i--)
	{
		m_resultString += std::to_string(results[i]);
	}
	return m_resultString;
}
