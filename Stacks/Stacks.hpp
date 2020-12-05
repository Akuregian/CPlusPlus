#ifndef STACKS_H
#define STACKS_H
#include<vector>

template<class T>
class Stacks // Create the Stack Class thats dervided by the Vectors Class.
{
	public:
		Stacks<T>();
		~Stacks<T>();
		T top();
		T reversePrint();
		void pop();
		void pop_front();
		void push(T element);
		int size();
	private:
		std::vector<T> m_stack_data;
};

template<class T>
Stacks<T>::Stacks()
{

}


template<class T>
Stacks<T>::~Stacks()
{

}

template<class T>
T Stacks<T>::top()
{
	if(m_stack_data.size() <= 0){throw "Stack is empty";}
	
	return m_stack_data.back();
}

template<class T>
T Stacks<T>::reversePrint()
{
	if(m_stack_data.size() <= 0){throw "Stack is empty";}

	return m_stack_data.front();
	
}

template<class T>
void Stacks<T>::pop()
{
	m_stack_data.pop_back();	
}

template<class T>
void Stacks<T>::pop_front()
{
	m_stack_data.erase(m_stack_data.begin());
}

template<class T>
void Stacks<T>::push(T element)
{
	m_stack_data.push_back(element);
}

template<class T>
int Stacks<T>::size()
{
	return m_stack_data.size();
}


#endif
