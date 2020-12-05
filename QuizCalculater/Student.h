  
#ifndef STUDENT_H
#define STUDENT_H
#include <vector>
#include <string>

class Student
{
  public:
	Student();
  	void print_grades(); // print the students grades
 	void get_name(std::string); //Will be placed into the constructor. retrieves the name
  	void add_quiz(int); // adds quizes to a vector called vectorScores
  	double get_TotalScore(std::vector<double>); //retrieves the total quiz scores added together
  	double get_averageScore(std::vector<double>); // adds all quizes, then  devide by number of quizes

  	std::vector<double> vectorScores;
 	std::string Studentsname;
};

#endif
