#include "grade.h"
#include <iostream>

Grade::Grade(double aveScore)
{
	std::cout << "Final Grade Is: "; 
	get_Grade(aveScore);
}

void Grade::get_Grade(double averageScore)
{

	if(averageScore >= 98 && averageScore <= 100) // A+
	{
		std::cout << "A+ and GPA: 4.0" << std::endl;
	}
	else if(averageScore >= 93 && averageScore <= 97) // A
	{
		
		std::cout << "A and GPA: 3.7" << std::endl;
	}
	else if(averageScore >= 90 && averageScore <= 92) // A-
	{

		std::cout << "A- and GPA: 3.7" << std::endl;
	}
	else if(averageScore >= 87 && averageScore <= 89) // B+
	{

		std::cout << "B+ and GPA: 3.3" << std::endl;
	}
	else if(averageScore >= 83 && averageScore <= 86) // B
	{

		std::cout << "B and GPA: 3.0" << std::endl;
	}
	else if(averageScore >= 80 && averageScore <= 82) // B-
	{

		std::cout << "B- and GPA: 2.7" << std::endl;
	}
	else if(averageScore >= 77 && averageScore <= 79) // C+
	{

		std::cout << "C+ and GPA: 2.3" << std::endl;
	}
	else if(averageScore >= 73 && averageScore <= 76) // C
	{

		std::cout << "C and GPA: 2.0" << std::endl;
	}
	else if(averageScore >= 70 && averageScore <= 72) // C-
	{

		std::cout << "C- and GPA: 1.7" << std::endl;
	}
	else if(averageScore >= 67 && averageScore <= 69) // D+
	{

		std::cout << "D+ and GPA: 1.3" << std::endl;
	}
	else if(averageScore >= 63 && averageScore <= 66) // D
	{

		std::cout << "D and GPA: 1.3" << std::endl;
	}
	else if(averageScore >= 60 && averageScore <= 62) // D-
	{

		std::cout << "D- and GPA: 1.0" << std::endl;
	}
	else if(averageScore <= 59 ) // F
	{

		std::cout << "F and GPA 0.0" << std::endl;
	}
}

//void Grade::print_grade(std::vector<Student> scores)
//{

//}
