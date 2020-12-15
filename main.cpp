#include"List.h"
#include"Stack.h"
#include"Queue.h"

int main()
{
	List<int>* list = new Queue<int>;

	list->pushBack(1);
	list->pushBack(2);
	list->pushBack(3);
	list->pushBack(4);
	list->pop();
	list->pop();
	list->pop();
	list->pop();

	list->print();


	return 0;
}