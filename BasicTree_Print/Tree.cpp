/*
File : Tree.cpp -> This is the implementations for the tree.h file
*/

#include "tree.h"

Tree::Tree()
{
   root = nullptr;
}

Tree::Tree(std::string root_data)
{
   root = new Node;
   root->data = root_data;
}


void Tree::add_subtree(const Tree& subtree)
{
   root->children.push_back(subtree.root);
}

int Tree::print() const
{

    for(Node* np : root->children)
    {
        np->print();
    }
}

int Tree::size() const
{
   if (root == nullptr) { return 0; }
   else { return root->size(); }
   if(root != nullptr){ root->print(); }
}

int Node::size() const
{
   int sum = 0;
   for (Node* child : children)
   {
      sum = sum + child->size();
   }
   return 1 + sum;
}
