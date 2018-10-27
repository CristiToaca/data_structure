#pragma once
#include <assert.h> 

namespace ct
{
namespace data_structure
{
	template <typename T>
	class Queue
	{
	public:
		Queue() { 
			head = nullptr; 
			tail = nullptr;
		};
		~Queue() {};

		//add at the end
		void Enqueue(T key){
			Node* node = CreateNode(key);
			if (!head){
				head = node;
				tail = node;
				return;
			}
			tail->next = node;
			tail = node;
		}

		//pop from start
		T Dequeue(){
			assert(head != nullptr);
			Node* node = head;
			head = head->next;
			T data = node->data;
			delete node;
			return data;
		}

		bool Empty() { return (head ? false : true); }

	private:
		struct Node;

		Node* head;
		Node* tail;

		struct Node{
			T data;
			Node* next;
		};

		Node* CreateNode(T data)
		{
			Node* node = new Node();
			node->data = data;
			node->next = nullptr;

			return node;
		}
	};
} // namespace data_structure
} // namespace ct