/*
 *
 * File: main.cpp
 * Description: Project reads in a csv file, related to covid-19 and creates a json_file using that csvfile
 * Author: AnthonyKuregian@yahoo.com  ||  anthonyk3371@student.vvc.edu
 *
 * */

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<map>
#include<sstream>


std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token; 
   std::istringstream tokenStream(s);
   while(std::getline(tokenStream, token, ','))
   {
	tokens.push_back(token);
   }
   return tokens;
}


std::vector<std::map<std::string, std::string>> read_csv(std::string file)
{
    std::vector<std::map<std::string,std::string>> mappedValues;
    std::ifstream csvFile(file);
    if(!csvFile.is_open()) {std::cout << "Error has occured loading in the file" << std::endl; }
    
    std::map<std::string, std::string> keyValues;
    std::string vals;
    getline(csvFile, vals);
    std::vector<std::string> splitvalues = split(vals, ',');

    while(!csvFile.eof())
    {
	std::string token = "";
	std::string line; 
	std::getline(csvFile, line);
	std::istringstream tokenStream(line);
	int i = 0;
        while(std::getline(tokenStream, token, ',' ))
	{
	     //std::cout << "Value: " << splitvalues[i] << ", " << "Token: " << token << std::endl; 
	     keyValues.insert(std::pair<std::string, std::string>(splitvalues[i], token));
	     i++;
	}
	mappedValues.push_back(keyValues);
	keyValues.clear();
    }

    csvFile.close();
    return mappedValues;
} 

void print_json(std::vector<std::map<std::string, std::string>>& mappedvals)
{
    for(auto i : mappedvals)
    {

        std::map<std::string,std::string>::iterator it;
        it = i.begin();
        for(it; it != i.end(); ++it)
        {
	    it = i.find("iso_code");
	    std::cout << std::setw(0) << "\"" << it->second << "\" :  {\n";
	    it = i.find("date");
	    std::cout << std::setw(5) << "\"" << it->second << "\" :  {\n";
	    it = i.find("iso_code");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("location");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("date");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("total_cases");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("new_cases");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("total_deaths");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("total_cases_per_million");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("new_cases_per_million");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("total_deaths_per_million");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("new_deaths_per_million");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("total_tests");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("new_tests");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("total_tests_per_thousand");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("new_tests_per_thousand");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("new_tests_smoothed");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("new_tests_smoothed_per_thousand");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("tests_units");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("stringency_index");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("population");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("population_density");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("median_age");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("aged_65_older");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("aged_70_older");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("gdp_per_capita");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("extreme_poverty");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("cvd_death_rate");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("diabetes_prevalence");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("female_smokers");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("male_smokers");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    it = i.find("handwashing_facilities");
	    std::cout << std::setw(10) << "\"" << it->first << "\" :  \"" << it->second << "\",\n";
	    std::cout << std::setw(8) << "}, \n" << std::setw(8) << ".\n" << std::setw(8) << ".\n" << std::setw(8) << ".\n";
	    std::cout << std::setw(4) << "}, \n" << std::setw(4) << ".\n" << std::setw(4) << ".\n" << std::setw(4) << ".\n";
	    std::cout << "\n\n\n" << std::endl;

	    break;
        }
    }
}

int main()
{
    std::vector<std::map<std::string, std::string>> mapVals = read_csv("owid-covid-data.csv"); // read_csv
    print_json(mapVals); // print_json
    return 0;
}

