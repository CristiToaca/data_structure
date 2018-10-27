#include "LinkList.h"
#include <iostream>
#include <assert.h> 

using namespace ct::data_structure;

void LinkList::PushFront(Node** root, int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = *root;
	*root = newNode;
}

int& LinkList::TopFront(Node* root)
{
	return root->data;
}

void LinkList::PopFront(Node** root)
{
	Node* temp = *root;
	(*root) = (*root)->next;
	delete temp;
}

void LinkList::PushBack(Node** root, int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = nullptr;

	if (!(*root))
	{
		(*root) = newNode;
		return;
	}

	Node* node = (*root);
	while (node->next)
		node = node->next;

	node->next = newNode;
}

int& LinkList::TopBack(Node* root)
{
	assert(root != nullptr);

	Node* node = root;
	while (node->next)
		node = node->next;

	return node->data;
}

void LinkList::PopBack(Node* root)
{
	assert(root != nullptr);

	if (!root->next)
	{
		delete root;
		return;
	}

	Node* node = root;
	while (node->next->next)
		node = node->next;

	delete node->next;
	node->next = nullptr;
}

bool LinkList::Find(Node* root, const int& data)
{
	Node* node = root;
	while (node)
	{
		if (node->data == data)
			return true;
		node = node->next;
	}
	return false;
}

void LinkList::Erase(Node** root, const int& data)
{
	if (!root)
		return;

	Node* node = (*root);

	if (node->data == data)
	{
		(*root) = node->next;
		return;
	}

	while (node->next)
	{
		if (node->next->data == data)
		{
			Node* temp = node->next;
			node->next = node->next->next;
			delete temp;

			return;
		}
		node = node->next;
	}
}

bool LinkList::Empty(Node* root)
{
	if (root)
		return true;
	else
		return false;
}

void LinkList::AddBefore(Node** root, int toBeAdded, int toCompare)
{
	if (!root)
		return;

	if ((*root)->data == toCompare)
	{
		Node* node = new Node();
		node->data = toBeAdded;
		node->next = (*root);
		(*root) = node;

		return;
	}

	Node* tempNode = (*root);

	while (tempNode->next)
	{
		if (tempNode->next->data == toCompare)
		{
			//insert
			Node* node = new Node();
			node->data = toBeAdded;
			node->next = tempNode->next;
			tempNode->next = node;

			return;
		}
		tempNode = tempNode->next;
	}
}

void LinkList::AddAfter(Node** root, int toBeAdded, int toCompare)
{
	if (!root)
		return;

	Node* tempNode = (*root);
	while (tempNode)
	{
		if (tempNode->data == toCompare)
		{
			Node* node = new Node();
			node->data = toBeAdded;
			node->next = tempNode->next;
			tempNode->next = node;

			return;
		}

		tempNode = tempNode->next;
	}
}

void LinkList::PrintList(Node* root)
{
	if (!root)
	{
		std::cout << "List is empty!" << std::endl;
		return;
	}

	Node* node = root;

	while (node)
	{
		std::cout << node->data;
		if (node->next)
			std::cout << "->";

		node = node->next;
	}
	std::cout << std::endl;
}

