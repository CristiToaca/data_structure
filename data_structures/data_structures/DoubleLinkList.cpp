#include "DoubleLinkList.h"
#include <iostream>
#include <assert.h> 

using namespace ct::data_structure;

DoubleLinkList::DoubleLinkList()
{
	head = nullptr;
	tail = nullptr;
}


DoubleLinkList::~DoubleLinkList()
{
}

DoubleLinkList::Node* DoubleLinkList::CreateNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->next = nullptr;
	node->prev = nullptr;

	return node;
}

void DoubleLinkList::PushFront(int data)
{
	Node* node = CreateNode(data);

	if (!head)
	{
		head = node;
		tail = node;

		return;
	}

	node->next = head;
	head->prev = node;
	head = node;
}

int DoubleLinkList::TopFront()
{
	assert(head != nullptr);

	return head->data;
}

void DoubleLinkList::PopFront()
{
	if (!head) //0 elements
		return;

	if (head == tail) //1 element
	{
		delete head;
		head = nullptr;
		tail = nullptr;

		return;
	}

	//2 or more elements
	head->next->prev = nullptr;
	Node* temp = head;
	head = head->next;
	delete temp;
}

void DoubleLinkList::PushBack(int data)
{
	Node* node = CreateNode(data);

	if (!head)
	{
		head = node;
		tail = node;
		return;
	}

	tail->next = node;
	node->prev = tail;
	tail = node;
}

int DoubleLinkList::TopBack()
{
	assert(tail != nullptr);

	return tail->data;
}

void DoubleLinkList::PopBack()
{
	if (!tail) //0 elements
		return;

	if (head == tail) //1 element
	{
		delete tail;
		head = nullptr;
		tail = nullptr;

		return;
	}

	//2 or more elemnents
	Node* tempNode = tail;
	tail = tail->prev;
	tail->next = nullptr;

	delete tempNode;

}

bool DoubleLinkList::Find(const int& data)
{
	if (!head)
		return false;

	Node* node = head;
	while (node)
	{
		if (node->data == data)
			return true;
		node = node->next;
	}

	return false;
}

void DoubleLinkList::Erase(const int& data)
{
	if (!head)
		return;

	if (head == tail && head->data == data)
	{
		delete head;
		head = nullptr;
		tail = nullptr;

		return;
	}

	if (head->data == data)
	{
		Node* node = head;
		head->next->prev = nullptr;
		head = head->next;
		delete node;

		return;
	}

	if (tail->data == data)
	{
		Node* node = tail;
		tail->prev->next = nullptr;
		tail = tail->prev;
		delete node;

		return;
	}

	Node* node = head;
	while (node)
	{
		if (node->data == data)
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
			delete node;

			return;
		}
		node = node->next;
	}
}

bool DoubleLinkList::Empty()
{
	if (head)
		return true;
	else
		return false;
}

void DoubleLinkList::AddBefore(int toBeAdded, int toCompare)
{
	if (!head)
		return;	

	if (head->data == toCompare)
	{
		PushFront(toBeAdded);
		return;
	}

	Node* node = head;

	while (node)
	{
		if (node->data == toCompare)
		{
			Node* newNode = CreateNode(toBeAdded);

			newNode->next = node;
			newNode->prev = node->prev;
			node->prev->next = newNode;
			node->prev = newNode;

			return;
		}

		node = node->next;
	}
}

void DoubleLinkList::AddAfter(int toBeAdded, int toCompare)
{
	if (!head)
		return;

	if (tail->data == toCompare)
	{
		PushBack(toBeAdded);
		return;
	}

	Node* node = head;

	while (node)
	{
		if (node->data == toCompare)
		{
			Node* newNode = CreateNode(toBeAdded);

			newNode->next = node->next;
			newNode->prev = node;
			node->next->prev = newNode;
			node->next = newNode;

			return;
		}
		node = node->next;
	}

}

void DoubleLinkList::PrintList()
{
	if (!head)
	{
		std::cout << "List is empty!";
		return;
	}

	Node* node = head;
	while (node)
	{
		std::cout << node->data;
		if (node->next)
			std::cout << " <-> ";

		node = node->next;
	}

	std::cout << std::endl;
}