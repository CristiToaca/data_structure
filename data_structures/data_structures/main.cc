#include <iostream>
#include "DynamicArray.h"
#include "LinkList.h"
#include "DoubleLinkList.h"
#include "Stack.h"
#include "Queue.h"



using namespace ct::data_structure;

void TestArray();
void TestLinkList();
void TestDoubleLinkList();
void TestStack();
void TestQueue();

void main()
{
	//TestArray();
	//TestLinkList();
	//TestDoubleLinkList();
	TestStack();
	TestQueue();
}


void TestArray()
{
	DynamicArray<int> array;

	for (int i = 0; i < 5400; ++i)
	{
		array.PushBack(i);
		std::cout << "i: " << array.Get(i) << " " << "size: " << array.size() << " " << "capacity: " << array.capacity();
		if (i % 4 == 0)
		{
			std::cout << std::endl;
		}
		else
		{
			std::cout << "  |  ";
		}
	}
	std::cout << std::endl;
}

void TestLinkList()
{
	LinkList::Node* list = nullptr;

	LinkList::PushFront(&list, 1);
	LinkList::PopFront(&list);

	LinkList::PushBack(&list, 2);

	LinkList::PushBack(&list, 3);
	LinkList::PushBack(&list, 4);
	LinkList::PushBack(&list, 5);
	LinkList::PushBack(&list, 6);
	LinkList::PushBack(&list, 7);
	LinkList::PushBack(&list, 8);

	LinkList::PopBack(list);

	LinkList::PrintList(list);
	std::cout << "First node: " << LinkList::TopFront(list);
	std::cout << std::endl;
	std::cout << "Last node: " << LinkList::TopBack(list);
	std::cout << std::endl;
	std::cout << "Node 5 is in list ? " << (LinkList::Find(list, 5) == true ? "Yes" : "No");
	std::cout << std::endl;
	std::cout << "Node 10 is in list ? " << (LinkList::Find(list, 10) == true ? "Yes" : "No");
	std::cout << std::endl;

	std::cout << "Deleted node 5";
	LinkList::Erase(&list, 5);
	std::cout << std::endl;
	LinkList::PrintList(list);

	std::cout << "Deleted node 10";
	LinkList::Erase(&list, 10);
	std::cout << std::endl;
	LinkList::PrintList(list);


	LinkList::AddBefore(&list, 10, 2);
	LinkList::PrintList(list);

	LinkList::AddAfter(&list, 11, 10);
	LinkList::PrintList(list);
}

void TestDoubleLinkList()
{
	DoubleLinkList list;

	list.PushBack(1);
	list.PrintList();
	list.PopFront();
	list.PushFront(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.PushFront(1);
	list.PushBack(6);
	list.PushBack(7);
	list.PushBack(8);
	list.PrintList();
	list.PopFront();
	list.PopBack();
	list.PrintList();
	std::cout << "First element is : " << list.TopFront() << std::endl;

	list.Erase(2);
	list.PrintList();
	list.Erase(7);
	list.PrintList();
	list.Erase(4);
	list.PrintList();

	std::cout << "Added 4 after 3" << std::endl;
	list.AddAfter(4, 3);
	list.PrintList();

	std::cout << "Added 7 after 6" << std::endl;
	list.AddAfter(7, 6);
	list.PrintList();

	std::cout << "Added 10 after 5" << std::endl;
	list.AddAfter(10, 5);
	list.PrintList();

	std::cout << "Added 2 before 3" << std::endl;
	list.AddBefore(2, 3);
	list.PrintList();

	std::cout << "Added 11 before 7" << std::endl;
	list.AddBefore(11, 7);
	list.PrintList();

	std::cout << "Added 12 before 5" << std::endl;
	list.AddBefore(12, 5);
	list.PrintList();

}

void TestStack()
{
	std::cout << "Test Stack!" << std::endl;

	Stack<int> stack;
	std::cout << "Empty ? " << (stack.Empty() ? "Yes" : "No") << std::endl;

	std::cout << "Top Stack: ";
	for (int i = 0; i < 10; ++i)
	{
		stack.Push(i);
		std::cout << stack.Top() << " ";
	}
	std::cout << std::endl;
	std::cout << "Empty ? " << (stack.Empty() ? "Yes" : "No") << std::endl;

	std::cout << "Pop Stack: ";
	while (!stack.Empty())
	{
		std::cout << stack.Pop() << " ";
	}
	std::cout << std::endl;
}

void TestQueue()
{
	std::cout << "Test Queue!" << std::endl;
	Queue<int> queue;
	std::cout << "Empty ? " << (queue.Empty() ? "Yes" : "No") << std::endl;

	std::cout << "Enqueue: ";
	for (int i = 0; i < 10; ++i)
	{
		queue.Enqueue(i);
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << "Empty ? " << (queue.Empty() ? "Yes" : "No") << std::endl;

	std::cout << "Dequeue: ";
	while (!queue.Empty())
	{
		std::cout << queue.Dequeue() << " ";
	}
	std::cout << std::endl;
}