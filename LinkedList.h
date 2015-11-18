#ifndef GUARD_LINKED_LIST_H
#define GUARD_LINKED_LIST_H
#include <iostream>
#include <vector>
#include <iterator>
#include <string>

class LinkedList
{
	public:
		LinkedList();
		virtual
		~LinkedList();
		void appendNode(int value);
		void insertNode(int value);
		void deleteNode(int value);
		void display();
		void reverse();
		void findDupsSorted();
		int listSize();
		void addCombined(int value);
		std::vector<int> getSum();

	protected:
		struct Node
		{
			int data;
			std::string key;
			char c;
			Node* next;
		};
		Node* head;
		Node* tail;
};

#endif
