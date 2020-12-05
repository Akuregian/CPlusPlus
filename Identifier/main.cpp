/*File: main.cpp
 * Description: This file reads in a txt file that contains numbers, characters and underscores. The program will read each char
 *  and then count how many times It has found that identifier in the text, and store it using a map
 *  Author: AnthonyKuregian@yahoo.com || Anthonk3371@student.vvc.edu
 */

#include<iostream>
#include<fstream>
#include<vector>
#include<map>


int main()
{
    std::map<char, int> mapIdentifiers;
    std::vector<char> identifiers = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5',  '6', '7', '8', '9', '0', '_'} ;
    std::ifstream inputFile("identifiers.txt", std::ios::in);
    if(!inputFile.is_open()) {std::cout << "Failed to open file" << std::endl;}
    char character;
    int numoflines = 0;
    for(int i = 0; i <= identifiers.size(); ++i)
    {
	    mapIdentifiers.insert(std::pair<char, int>(identifiers[i], 0));
    }
    std::map<char, int>::iterator it;
    while(!inputFile.eof())
    {
    	inputFile.get(character);
	for(auto i : identifiers)
	{
	    if(i == character)
	    {
		it = mapIdentifiers.find(character);
		it->second++;
	    }
	}
	if(character == '\n')
	{
	    numoflines++;
	}
    }
    for(std::map<char, int>::iterator it = mapIdentifiers.begin(); it != mapIdentifiers.end(); ++it)
    {
        std::cout << "TheValue: [" << it->first << "] has been found " << it->second << " times."<<  std::endl;
    }
    std::cout << "Number of lines: " << numoflines << std::endl;


    return 0;
}
