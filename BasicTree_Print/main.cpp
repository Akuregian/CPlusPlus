/*
File: Main.cpp -> This File will create a Tree structure with its 
'Leaves' being a Node of struct type. We will add various strings to this tree while create sub trees with other string
Author: Anthony Kuregian
Email: AnthonyKuregian@cis.vvc.edu || Anthonykuregian.yahoo.com || Anthonk3371@student.vvc.edu
*/

#include <iostream>
#include <string>
#include "tree.h"


int main()
{
   Tree t1("Anne");
   Tree t2("Peter");
   t1.add_subtree(t2);
   Tree t3("Zara");
   t1.add_subtree(t3);
   Tree t4("Savannah");
   t2.add_subtree(t4);
   std::cout << "Size: " << t1.size() << std::endl;
   return 0;
}
