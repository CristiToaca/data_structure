#pragma once

namespace ct
{
namespace data_structure
{
	namespace LinkList
	{
		struct Node{
			int data;
			Node* next;
		};

		void PushFront(Node** root, int data);
		int& TopFront(Node* root);
		void PopFront(Node** root);
		void PushBack(Node** root, int data);
		int& TopBack(Node* root);
		Node* TopNodeBack(Node* root);
		void PopBack(Node* root);
		bool Find(Node* root, const int& data);
		void Erase(Node** root, const int& data);
		bool Empty(Node* root);
		void AddBefore(Node** root, int toBeAdded, int toCompare);
		void AddAfter(Node** root, int toBeAdded, int toCompare);

		void ReverseList(Node** root);

		void PrintList(Node* root);
	}
}
}