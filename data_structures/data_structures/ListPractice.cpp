#include "ListPractice.h"
#include <iostream>

using namespace ct::data_structure;

void ListPractice::Test()
{
	////Input: 17->15->8->12->10->5->4->1->7->6->NULL
	////Output: 8->12->10->4->6->17->15->5->1->7->NULL
	//LinkList::Node* list = nullptr;
	//LinkList::PushBack(&list, 17);
	//LinkList::PushBack(&list, 15);
	//LinkList::PushBack(&list, 8);
	//LinkList::PushBack(&list, 12);
	//LinkList::PushBack(&list, 10);
	//LinkList::PushBack(&list, 5);
	//LinkList::PushBack(&list, 4);
	//LinkList::PushBack(&list, 1);
	//LinkList::PushBack(&list, 7);
	//LinkList::PushBack(&list, 6);
	//LinkList::PrintList(list);

	////SegregateEvenAndOddNodesInALinkedList(&list);
	//SegregateEvenAndOddNodesInALinkedList2(&list);
	//LinkList::PrintList(list);
//////////////////////////////////////////////////////////


	//LinkList::Node* first = nullptr;
	//LinkList::PushBack(&first, 7);
	//LinkList::PushBack(&first, 5);
	//LinkList::PushBack(&first, 9);
	//LinkList::PushBack(&first, 4);
	//LinkList::PushBack(&first, 6);
	//
	//LinkList::Node* second = nullptr;
	//LinkList::PushBack(&second, 8);
	//LinkList::PushBack(&second, 4);
	////LinkList::PushBack(&second, 2);
	//
	//LinkList::Node* result = AddTwoNumbersRepresentedByLists(&second, &first);
	//LinkList::PrintList(first);
	//LinkList::PrintList(second);
	//LinkList::PrintList(result);


	LinkList::Node* list = nullptr;
	LinkList::PushBack(&list, 1);
	LinkList::PushBack(&list, 2);
	LinkList::PushBack(&list, 3);
	LinkList::PushBack(&list, 4);
	LinkList::PushBack(&list, 5);
	auto endOfList = LinkList::TopNodeBack(list);
	endOfList->next = list;
	bool isLoop = DetectLoopInALinkedList(list);
	std::cout << "isLoop ? "<< (isLoop ? "yes" : "no") << std::endl;

	RemoveLoopInALinkedList(list);

	isLoop = DetectLoopInALinkedList(list);
	std::cout << "isLoop ? " << (isLoop ? "yes" : "no") << std::endl;
}

void ListPractice::SegregateEvenAndOddNodesInALinkedList(LinkList::Node** root)
{
	if (!(*root) && !(*root)->next) //0 or 1 element
		return;

	
	LinkList::Node* evens = nullptr;
	LinkList::Node* odds = nullptr;
	LinkList::Node* current = (*root);

	while (current)
	{
		if (current->data % 2 == 0) //even
		{
			LinkList::PushBack(&evens, current->data);
		}
		else //odd
		{
			LinkList::PushBack(&odds, current->data);
		}

		current = current->next;
	}
	
	if (evens)
	{
		(*root) = evens;
		while (evens->next)
			evens = evens->next;

		evens->next = odds;
	}
	else
	{
		(*root) = odds;
	}	
}

void ListPractice::SegregateEvenAndOddNodesInALinkedList2(LinkList::Node** root)
{
	if (!(*root) && !(*root)->next) //0 or 1 element
		return;


	LinkList::Node* last = (*root);
	LinkList::Node* current = (*root);
	LinkList::Node* prev = nullptr;

	while (last->next)
		last = last->next;

	//set last to point to the last element
	LinkList::Node* newLast = last;

	current = (*root);
	
	while (current != last)
	{
		if (current->data % 2 == 1)
		{
			if (prev)
				prev->next = current->next;
			else
				(*root) = current->next;

			newLast->next = current;
			newLast = current;
			current = current->next;

			newLast->next = nullptr;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}

}

LinkList::Node* ListPractice::AddTwoNumbersRepresentedByLists(LinkList::Node** first, LinkList::Node** second)
{
	if (!(*first))
		return (*second);
	if (!(*second))
		return (*first);

	LinkList::Node* firstCurrent = (*first);
	LinkList::Node* secondCurrent = (*second);
	LinkList::Node* result = nullptr;
	int carry = 0;

	while (firstCurrent && secondCurrent)
	{
		int sum = firstCurrent->data + secondCurrent->data + carry;
		carry = 0;
		if (sum > 9)
		{
			carry = 1;
			sum -= 10; 
		}
		LinkList::PushBack(&result, sum);

		firstCurrent = firstCurrent->next;
		secondCurrent = secondCurrent->next;
	}


	while (firstCurrent)
	{
		int sum = firstCurrent->data + carry;
		carry = 0;
		if (sum > 9)
		{
			carry = 1;
			sum -= 10;
		}
		LinkList::PushBack(&result, sum);
		firstCurrent = firstCurrent->next;
	}

	while (secondCurrent)
	{
		int sum = secondCurrent->data + carry;
		carry = 0;
		if (sum > 9)
		{
			carry = 1;
			sum -= 10;
		}
		LinkList::PushBack(&result, sum);
		secondCurrent = secondCurrent->next;
	}

	if (carry > 0)
		LinkList::PushBack(&result, 1);

	return result;
}

bool ListPractice::DetectLoopInALinkedList(LinkList::Node* root)
{
	if (!root || !root->next || !root->next->next) //0, 1 or 2 elements
		return false;

	LinkList::Node* current = root->next;
	LinkList::Node* fastCurrent = root->next->next;
	while (current && fastCurrent && fastCurrent->next)
	{
		if (current->data == fastCurrent->data)
		{
			return true;
		}

		current = current->next;
		fastCurrent = fastCurrent->next->next;
	}
	return false;
}

void ListPractice::RemoveLoopInALinkedList(LinkList::Node* root)
{
	if (!root || !root->next || !root->next->next) //0, 1 or 2 elements
		return;

	LinkList::Node* current = root->next;
	LinkList::Node* fastCurrent = root->next->next;
	while (current && fastCurrent && fastCurrent->next && fastCurrent->next->next)
	{
		if (current->next->data == fastCurrent->next->next->data)
		{
			LinkList::Node* fromTheStart = root;
			
			while (current->next->data != fromTheStart->data)
			{
				current = current->next;
				fromTheStart = fromTheStart->next;
			}

			current->next = nullptr;

			return;
		}

		current = current->next;
		fastCurrent = fastCurrent->next->next;
	}
}
