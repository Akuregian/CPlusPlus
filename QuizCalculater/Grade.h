#ifndef GRADE_H
#define GRADE_H

#include <iostream>
#include <vector>
#include "student.h"

class Grade
{
public:
	Grade(double);
	void print_grade(std::vector<Student>);
	void get_Grade(double);
	void get_current_GPA(double);
};

#endif
