#include<iostream>
#include"Stacks.hpp"
#include<string>

int main()
{
	Stacks<int> firstStack;
	firstStack.push(10);
	firstStack.push(20);
	firstStack.push(30);
	firstStack.push(40);
	try
	{
		while(firstStack.size() > 0)
		{
			std::cout << firstStack.reversePrint() << std::endl;
			firstStack.pop_front();
		}
	}
	catch(const char* e)
	{
		std::cout << e << std::endl;
	}

	Stacks<std::string> stringStack;
	stringStack.push("Anthony");
	stringStack.push("Wrote");
	stringStack.push("This");
	stringStack.push("Program");
	try
	{
		while(stringStack.size() > 0)
		{
			std::cout << stringStack.reversePrint() << std::endl;
			stringStack.pop_front();
		}
	}
	catch(const char* e)
	{
		std::cout << e << std::endl;
	}

	return 0;
}
