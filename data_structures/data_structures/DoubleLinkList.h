#pragma once

namespace ct
{
namespace data_structure
{
	class DoubleLinkList
	{

	public:
		DoubleLinkList();
		~DoubleLinkList();

		void PushFront(int data);
		int TopFront();
		void PopFront();
		void PushBack(int data);
		int TopBack();
		void PopBack();
		bool Find(const int& data);
		void Erase(const int& data);
		bool Empty();
		void AddBefore(int toBeAdded, int toCompare);
		void AddAfter(int toBeAdded, int toCompare);

		void PrintList();

	private:
		struct Node;

		Node* head;
		Node* tail;

		struct Node{
			int data;
			Node* next;
			Node* prev;
		};

		Node* CreateNode(int);
	};
}//namespace data_structure
} //namespace ct
