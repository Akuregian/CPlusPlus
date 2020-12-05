/*
   File: main.cpp
   Description: This Program will Define a Struct Student and a vector<Course*> that will print all student in course and what course each student is enrolled in.
   Author: Anthony Kuregian
   Email: Anthonk3371@student.vvc.edu
   	  AnnthonyKuregian@yahoo.com
*/
#include<iostream>
#include <vector>

struct Course;

struct Student
{
	std::string name;
	std::vector<Course*> courses;
};

struct Course
{
	std::string courseName;
	std::vector<Student*> students;
};

void print_student(Student* s) // will print a student, and courses he is enrolled into
{
	std::cout << "The Student " << s->name << " is enrolled in: " << std::endl;

	for(int i = 0; i < s->courses.size(); i++)
	{
		std::cout << "Course " << i << ": " << s->courses[i]->courseName << std::endl;
	}
	std::cout<<std::endl;


}
void print_courses(Course* c) // Will Print the Name of a course, and all Students enrolled in that class
{
	std::cout << std::endl << "Students Enrolled in " << c->courseName << ": " <<std::endl;

	for(int i = 0 ; i < c->students.size(); i++)
	{
		std::cout << "Student " << i << ": "  << c->students[i]->name << std::endl;
	}
	std::cout<<std::endl;
}

void enroll(Student* s, Course* c) // Enrolls the given student in the given course, updating borth vectors
{
	s->courses.push_back(c);
	c->students.push_back(s);
}

int main()
{
	Student* s1 = new Student[3];
	Course* c1 = new Course[3];
	s1[0].name = "Anthony Kuregian";
	s1[1].name = "John Doe";
	s1[2].name = "Mike Wizowski";

	c1[0].courseName = "Calculus";
	c1[1].courseName = "CIS";
	c1[2].courseName = "Physics";
	
	// Anthony's Enrollment
	enroll(&s1[0], &c1[1]);
	enroll(&s1[0], &c1[2]);
	// Johns Enrollment
	enroll(&s1[1], &c1[0]);
	enroll(&s1[1], &c1[1]);
	// Mikes Enrollment
	enroll(&s1[2], &c1[0]);
	enroll(&s1[2], &c1[2]);

	
	std::cout << "---------------------------------------------------------------" <<std::endl;
	for(int i = 0; i < 3; i++)
	{
		print_courses(&c1[i]);
	}
	std::cout << "---------------------------------------------------------------\n" <<std::endl;

	for(int i = 0; i < 3; i++)
	{
		print_student(&s1[i]);
	}

	std::cout << "---------------------------------------------------------------\n" <<std::endl;
	delete []s1;
	delete []c1;

	return 0;
}
