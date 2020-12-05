#include "student.h"
#include <iostream>

Student::Student()
{	
	std::string stuName;
	std::cout << "Enter Student Name: ";
	std::cin >> stuName;
	get_name(stuName);
}

void Student::add_quiz(int score)
{
	vectorScores.push_back(score);
}

void Student::print_grades()
{
	for(int i = 0; i < vectorScores.size(); i++)
	{
		std::cout << "Quiz Score #" << i << ": " << vectorScores[i] << std::endl;
	}
}

void Student::get_name(std::string Stuname)
{
	Studentsname = Stuname;
}

double Student::get_TotalScore(std::vector<double> vectorScore)
{
	double totalScore = 0.0;
	for(int i = 0; i < vectorScore.size(); i++)
	{
		totalScore += vectorScore[i];
	}
	return totalScore;
}

double Student::get_averageScore(std::vector<double> vecscores)
{
	
	double totalScore = 0.0;
	for(int i = 0; i < vecscores.size(); i++)
	{
		totalScore += vecscores[i];
	}
	double Average = totalScore / vecscores.size();

	return Average;
}
