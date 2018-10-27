#pragma once
#include <assert.h> 

namespace ct
{
namespace data_structure
{
	template <typename T>
	class Stack
	{
	public:
		Stack() { head = nullptr; };
		~Stack() {};

		//add at the start
		void Push(T key){
			Node* node = CreateNode(key);
			if (!head){
				head = node;
				return;
			}
			node->next = head;
			head = node;
		}

		T& Top(){
			assert(head != nullptr);
			return head->data;
		}

		//pop from start
		T Pop(){
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