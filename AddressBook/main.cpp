/*
   File: main.cpp
   Description: This Program will have a AndressBook Class and a Person Class. The Address Class will contain a vector of <*Person> that stores each person
   		living at that address. I will have an array of AddressBooks, storing there own residents and addresses. Option will be giving to print out all the addresses to a text file.
   Author: Anthony Kuregian
   Email: AnthonyKureian || Anthonk3371@student.vvc.edu
*/
#include<iostream>
#include<fstream>
#include"AddressBook.h"
#include"Person.h"


//Helper Func, doesnt do much but gets rid of the 'new' keyword in mains
Person* createPerson(std::string first, std::string last)
{
	Person *nPerson = new Person(first, last);
	return nPerson;
}

int main()
{
	//---------------------------------------------------------------- // Creates the First home with Residents with its own tenants
	std::ofstream outFile;
	AddressBook *ptrAddyArray = new AddressBook[3];
	Person* helperFunc = createPerson("Johny","Sicario");
	Person* ptrPerson1 = createPerson("Anthony", "Kuregian");
	Person* ptrPerson2 = createPerson("Jennifer", "Aniston");
	ptrAddyArray[0].addAddress("13241 Juniper Rd.", "Beverlly Hills", "CA", "92395", "US");
	ptrAddyArray[0].add_Resident(ptrPerson1);
	ptrAddyArray[0].add_Resident(ptrPerson2);
	ptrAddyArray[0].add_Resident(helperFunc);

	//---------------------------------------------------------------- // Creates the Second Home with Residents with its own tenants
	Person *ptrPerson3 = createPerson("Mark", "Bunch");
	Person *ptrPerson4 = createPerson("Molly", "Bunch");
	Person *ptrPerson5 = createPerson("Carol", "Bunch");
	Person *ptrPerson6 = createPerson("Phillip", "Bunch");
	ptrAddyArray[1].addAddress("11132 BradyBunch Dr.", "Bradysville", "MN", "92112", "US");
	ptrAddyArray[1].add_Resident(ptrPerson3);
	ptrAddyArray[1].add_Resident(ptrPerson4);
	ptrAddyArray[1].add_Resident(ptrPerson5);
	ptrAddyArray[1].add_Resident(ptrPerson6);

	//---------------------------------------------------------------- // Creates the Third Home with Residents with its own tenants
	Person *ptrPerson7 = createPerson("Ozzy", "Ozborne");
	Person *ptrPerson8 = createPerson("Skecthy", "Ozborne");
	Person *ptrPerson9 = createPerson("Deceptive", "Ozborne");
	Person *ptrPerson10 = createPerson("Slick", "Ozborne");
	ptrAddyArray[2].addAddress("1266621 BorneOz way", "Los Ozborne", "NJ", "92666", "NE");
	ptrAddyArray[2].add_Resident(ptrPerson7);
	ptrAddyArray[2].add_Resident(ptrPerson8);
	ptrAddyArray[2].add_Resident(ptrPerson9);
	ptrAddyArray[2].add_Resident(ptrPerson10);

	//----------------------------------------------------------------
	bool looping = false; // Keeps Looping order to manipulate the container
	while(!looping)
	{
		
		for(int i = 0; i <3; i ++)
		{
			ptrAddyArray[i].print_residents(); // Prints the current residents
		}

		std::string response;
		std::cout << "[Press 1 to Change Address or Residents name] [Press 2 to Print to TextFile] [Press 'q' to quit]" << std::endl;
		std::cin >> response;
		if(response == "1") // Here we Change a persons name
		{
			unsigned int decider;
			std::cout << "Press 1 to CHANGE {Person} OR Press 2 to CHANGE {Address}" << std::endl;
			std::cin >> decider;
			bool foundPerson = false;
			int reachedEnd = 0;
			if(decider == 1) //person
			{
				while(!foundPerson)
				{
					if(reachedEnd)
					{
						std::cout << "Sorry, Please Retry Entering in the Name" << std::endl;
						reachedEnd = 0;
					}

					std::cout << "Enter the First name to search for: ";
					std::string fname;
					std::cin >> fname;
					std::cout << std::endl << "Enter the Last name to search for: ";
					std::string lname;
					std::cin >> lname;


					for(int i = 0; i < 3;i++)
					{
						if(ptrAddyArray[i].searchResident(fname, lname))
						{
							std::cout << "Enter the New First Name: ";
							std::string nFirst;
							std::cin >> nFirst;
							std::cout << std::endl << "Enter the new Last Name: ";
							std::string nLast;
							std::cin >> nLast;
							ptrAddyArray[i].changeResidentName(fname, lname, nFirst, nLast);
							std::cout << std::endl << "\n**New Resident Added**\n" << std::endl;
							foundPerson = true;
						}
					}
					reachedEnd = 1;
				}

			}
			
			else if(decider == 2) //addresses are cahanged here
			{ 
				std::cin.ignore(); // Needed to Clear the cin biffer, since I want to use getline.
				std::cout << "Enter Street Address to search for: ";
				std::string tmpStreet;
				std::getline(std::cin, tmpStreet);

				std::cout << "Enter the City to search for: ";
				std::string tmpCity;
				std::getline(std::cin,tmpCity);

				std::cout << "Lastly, Enter the State: ";
				std::string tmpState; 
				std::getline(std::cin,tmpState);

				for(int i = 0; i < 3; i++)
				{
					if(ptrAddyArray[i].searchAddress(tmpStreet, tmpCity, tmpState))
					{
						std::cout << "Enter the New Street: ";
						std::string newStreet;
						std::getline(std::cin, newStreet);

						std::cout << "Enter the New City: ";
						std::string newCity;
						std::getline(std::cin, newCity);

						
						std::cout << "Enter the New State: ";
						std::string newState;
						std::getline(std::cin, newState); 
						
						std::cout << "Enter the New Zipcode: ";
						std::string newZip;
						std::getline(std::cin, newZip);

						std::cout << "Enter the New Country: ";
						std::string newCountry;
						std::getline(std::cin, newCountry);


						ptrAddyArray[i].changeAddress(newStreet, newCity, newState, newZip, newCountry);
					}
				}

			}
			else 
			{
				// Exception Handling
				try
				{
					throw "Must Press Either a: 1 or 'q'";

				}
				catch(const char* e)
				{
					std::cout << "Exeption was thrown: " << e <<std::endl;
					return -1;
				}
			}
		}

		else if(response == "2") // This is where the information regarding each home is printed to a text file.
		{
			std::ofstream outfile;
			outfile.open("Addresses.txt");

			std::cout << "printing....." << std::endl;  
			for(int i = 0; i < 3; i++)
			{
				outfile << "--> " << ptrAddyArray[i].to_string() << std::endl;
				ptrAddyArray[i].Residents_to_string(outfile);

			}
			outfile << std::endl;
			std::cout << "File Printed Successfully." << std::endl;
			outfile.close();
			return 1; // Terminates program returning a 1 when the file is closed
		}

		else if(response == "q" || response == "Q") // Allows to leave the program
		{
			looping = true;
		}
	}


		for(int i = 0; i < 3;i++)
		{
			ptrAddyArray[i].print_residents(); // print the residents, which also prints the house address, to see changes.
		}


	return 0;
}
