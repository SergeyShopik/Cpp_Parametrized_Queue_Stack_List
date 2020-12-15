#pragma once
#include"List.h"

template<class T>
class Stack : public List<T>
{
public:
	Stack();
	~Stack();

	void pushBack(const T&);
	T pop();
	void print() const;
};

template<class T>
Stack<T>::Stack() : List<T>() {}

template<class T>
Stack<T>::~Stack()
{
	while (List<T>::getSize() != 0)
		pop();
}

template<class T>
void Stack<T>::pushBack(const T& element)
{
	Node<T>* newNode = new Node<T>(element, List<T>::getTail());
	List<T>::setTail(newNode);
	List<T>::setSize(List<T>::getSize() + 1);
}

template<class T>
T Stack<T>::pop()
{
	T key;
	if (List<T>::getSize() == 0)
	{
		std::cout << "Stack is empty.\n";
		return T();
	}
	else
	{
		Node<T>* temp = List<T>::getTail();
		key = temp->data;
		List<T>::setTail(temp->prev);
		List<T>::setSize(List<T>::getSize() - 1);

		delete temp;

		return key;
	}
}

template<class T>
void Stack<T>::print() const
{
	for (Node<T>* i = List<T>::getTail(); i; i = i->prev)
	{
		std::cout << i->data << " ";
	}
	std::cout << std::endl;
}