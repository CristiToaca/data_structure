#include <iostream>
#include <conio.h>
#include "DynamicArray.h"
#include "LinkList.h"
#include "DoubleLinkList.h"
#include "Stack.h"
#include "Queue.h"
#include "ListPractice.h"
#include "StringPractice.h"



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
	//TestStack();
	//TestQueue();

	//ListPractice::Test();

	//bool test = StringPractice::CheckPermutation("String Builder", "BuilderString "); 
	//std::cout << (test ? "True" : "False") << std::endl;

	//std::string test = "Mr John Smith    ";
	//StringPractice::URLify(test, 13);

	//bool test = StringPractice::PalindromePermutation("aaaaaaabbbbbbbcbbbaaaaaaaaabaaaaaaaaaa");
	//std::cout << (test ? "True" : "False") << std::endl;

	//bool test = StringPractice::OneAway("pale", "ple");
	//std::cout << (test ? "True" : "False") << std::endl;
	//test = StringPractice::OneAway("pales", "pale");
	//std::cout << (test ? "True" : "False") << std::endl;
	//test = StringPractice::OneAway("pale", "bale");
	//std::cout << (test ? "True" : "False") << std::endl;
	//test = StringPractice::OneAway("pale", "bake");
	//std::cout << (test ? "True" : "False") << std::endl;

	//std::string test = StringPractice::StringCompression("aabcccccaaa");
	//std::cout << "aabcccccaaa -> " << test << std::endl;



	//std::vector<std::vector<bool>> matrix;
	//matrix.push_back({ 1, 1, 1, 1, 1 });
	//matrix.push_back({ 0, 0, 0, 0, 0 });
	//matrix.push_back({ 1, 1, 1, 1, 1 });
	//matrix.push_back({ 0, 0, 0, 0, 0 });
	//matrix.push_back({ 1, 1, 1, 1, 1 });

	//StringPractice::PrintMatrix(matrix);
	//StringPractice::RotateMatrix(matrix);
	//StringPractice::PrintMatrix(matrix);


	auto gameMap = StringPractice::StartGame1024();
	StringPractice::Print1024Matrix(gameMap);

	//gameMap = { {4, 2, 16, 2}, \
	//			{16, 64, 8, 4}, \
	//			{4, 2, 32, 16}, \
	//			{0, 32, 4, 2} };

	//StringPractice::MoveLeftGame1024(gameMap);
	//StringPractice::Print1024Matrix(gameMap);

	bool notGameOver = true;
	int k = 0;
	while (k != 48 && notGameOver)
	{
		k = getch();
		k = getch();

		switch (k)
		{
		case 72:
			notGameOver = StringPractice::MoveUpGame1024(gameMap);
			StringPractice::Print1024Matrix(gameMap);
			break;
		case 75:
			notGameOver = StringPractice::MoveLeftGame1024(gameMap);
			StringPractice::Print1024Matrix(gameMap);
			break;
		case 77:
			notGameOver = StringPractice::MoveRightGame1024(gameMap);
			StringPractice::Print1024Matrix(gameMap);
			break;
		case 80:		
			notGameOver = StringPractice::MoveDownGame1024(gameMap);
			StringPractice::Print1024Matrix(gameMap);
			break;		
		}
	}

	std::cout << "Game Over" << std::endl;
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

	std::cout << "Reverse List" << std::endl;
	LinkList::ReverseList(&list);
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