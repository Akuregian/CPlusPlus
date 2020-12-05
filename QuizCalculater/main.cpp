/*
   File: main.cpp
   Description: Implements a class that holds a students name and total quiz score.
   Author: Anthony Kuregian
   Email: anthonk3371@student.vvc.edu
   	  anthonyKuregian@yahoo.com
*/
#include<iostream>
#include "student.h"
#include "grade.h"

int main()
{
   Student student;

   student.add_quiz(76);
   student.add_quiz(99);
   student.add_quiz(79);
   student.add_quiz(89);

   for(unsigned i = 0; i < student.vectorScores.size(); i++)
   {
	std::cout << "Quiz #" << i << " : " << student.vectorScores[i] << std::endl;
   }

   std::cout << "------------------------------------------------------------------------------------" <<std::endl;

   std::cout << "Student, " << student.Studentsname << ", has " << student.vectorScores.size()  << " quizes for a Total Score: " << student.get_TotalScore(student.vectorScores) << " points." << std::endl;
   std::cout << "Students Average Score: " << student.get_averageScore(student.vectorScores) << std::endl;


   Grade grades(student.get_averageScore(student.vectorScores));

   std::cout << "------------------------------------------------------------------------------------" <<std::endl;

   return 0;
}
