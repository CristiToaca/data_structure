#pragma once
#include "LinkList.h"
namespace ct
{
namespace data_structure
{
namespace ListPractice
{
	void Test();
	
	/*
	* Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. 
	* Also, keep the order of even and odd numbers same
	* Examples:
	* Input: 17->15->8->12->10->5->4->1->7->6->NULL
	* Output: 8->12->10->4->6->17->15->5->1->7->NULL
	*
	* Input : 8->12->10->5->4->1->6->NULL
	* Output : 8->12->10->4->6->5->1->NULL*/
	void SegregateEvenAndOddNodesInALinkedList(LinkList::Node** root);
	void SegregateEvenAndOddNodesInALinkedList2(LinkList::Node** root);

	//Input:
	//First List : 5->6->3  // represents number 365
	//Second List : 8->4->2 //  represents number 248
	//Output
	//Resultant list : 3->1->6  // represents number 613
	LinkList::Node* AddTwoNumbersRepresentedByLists(LinkList::Node** first, LinkList::Node** second);

	void SortListOfZeroesOnesAndTwos(LinkList::Node** root);

}//namespace ListPractice
}//namespace data_structure
}//namespace ct

