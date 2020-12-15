#pragma once
#include"List.h"

template<class T>

class Queue : public List<T>
{
public:
	Queue();
	~Queue();

	void pushBack(const T&);
	T pop();
	void print() const;

private:
	Node<T>* head;
	Node<T>* prevHeadSearch();
	void print(Node<T>*) const;
};

template<class T>
Node<T>* Queue<T>::prevHeadSearch()
{
	Node<T>* temp;
	for (temp = List<T>::getTail(); temp->prev != head; temp = temp->prev);

	return temp;
}

template<class T>
void Queue<T>::print(Node<T>* node) const
{
	if (node->prev != nullptr)
	{
		print(node->prev);
		std::cout << node->data << " ";
	}
	else
	{
		std::cout << node->data << " ";
		return;
	}
}

template<class T>
Queue<T>::Queue() : List<T>(), head(nullptr) {}

template<class T>
Queue<T>::~Queue() 
{
	pop();
}

template<class T>
void Queue<T>::pushBack(const T& element)
{
	Node<T>* newNode = new Node<T>(element, List<T>::getTail());

	if (List<T>::getSize() == 0)
	{
		List<T>::setTail(newNode);
		head = List<T>::getTail();
	}
	else
		List<T>::setTail(newNode);

	List<T>::setSize(List<T>::getSize() + 1);
}

template<class T>
T Queue<T>::pop()
{
	T key;
	if (List<T>::getSize() == 0)
	{
		std::cout << "Queue is empty.\n";
		return T();
	}
	else if (List<T>::getSize() == 1)
	{
		Node<T>* temp = head;
		key = temp->data;
		List<T>::setTail(nullptr);
		List<T>::setSize(List<T>::getSize() - 1);
		head = List<T>::getTail();

		delete temp;

		return key;
	}
	else
	{
		Node<T>* temp = head;
		key = temp->data;
		head = prevHeadSearch();
		head->prev = nullptr;
		List<T>::setSize(List<T>::getSize() - 1);

		delete temp;

		return key;
	}
}

template<class T>
void Queue<T>::print() const
{
	if (List<T>::getTail())
		print(List<T>::getTail());
}