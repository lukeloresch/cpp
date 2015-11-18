#include "LinkedList.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <stdio.h>
#include <stdlib.h>

LinkedList::LinkedList()
{
	head = NULL;
}
LinkedList::~LinkedList()
{
	Node *temp, *nextNode;
	temp = head;
	while (temp != NULL)
	{
		nextNode = temp->next;
		delete temp;
		temp = nextNode;
	}
}
void LinkedList::appendNode(int value)
{
	Node *newNode, *temp;

	newNode = new Node;
	newNode->data = value;
	newNode->next = NULL;

	if (!head)
		head = newNode;
	else
	{
		temp = head;
		while (temp->next)
			temp = temp->next;
		temp->next = newNode;
	}
}
void LinkedList::display()
{
	Node *temp;
	temp = head;
	while (temp)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}
void LinkedList::insertNode(int value)
{
	Node *newNode, *temp, *prev;

	newNode = new Node;
	newNode->data = value;

	if (head == NULL)
	{
		head = newNode;
		head->next = NULL;
	}
	else
	{
		temp = head;
		while (temp != NULL && temp->data <= value)
		{
			prev = temp;
			temp = temp->next;
		}
		if (prev == NULL)
		{
			head = newNode;
			newNode->next = temp;
		}
		else
		{
			prev->next = newNode;
			newNode->next = temp;
		}
	}
}
void LinkedList::deleteNode(int value)
{
	Node *temp, *prev;

	if (head == NULL)
	{
		std::cout << "Cannot delete from empty list\n";
		return;
	}
	else if (head->data == value)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		temp = head;
		while (temp != NULL && temp->data != value)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		delete temp;
	}
}
void LinkedList::reverse()
{
	Node *curr, *prev, *nextPtr; //, *tempHead
	prev = NULL;
	curr = head;
	while (curr != NULL)
	{
		nextPtr = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextPtr;
	}
	head = prev;
}
int LinkedList::listSize()
{
	int count = 0;
	Node *nodePtr;
	nodePtr = head;
	if (head == NULL)
	{
		++count;
		return count;
	}
	else 
	{
		while (nodePtr != NULL)
		{
			++count;
			nodePtr = nodePtr->next;
		}
		return count;
	}
	return 0;
}
void LinkedList::findDupsSorted()
{
	int count = 1;
	Node *nodePtr, *nextPtr;
	nodePtr = head;
	nextPtr = head->next;
	while (nodePtr != NULL) // && nodePtr->data != nextPtr->data)
	{
		if (nodePtr->data == nextPtr->data)
		{
			int temp = nodePtr->data;
			std::cout << "Found duplicates starting at index " << count << std::endl;
			std::cout << "Do you want to delete? y/n ";
			char in;
			std::cin >> in;
			if (in == 'n')
				return;
			else if (in == 'y')
			{
				deleteNode(temp);
				return;
			}
		}
		else
		{
			nodePtr = nextPtr;
			nextPtr = nextPtr->next;
			count++;
		}
	}
}

std::vector<int> LinkedList::getSum()
{
	Node *nodePtr, *temp;
	nodePtr = head;
	int size = listSize();
	std::vector<int> res;
	int multiplier = 1;
	int runningSum = 0;
	for (; size != 0; size--)
	{
		while (nodePtr != NULL)
		{
			temp = nodePtr;
			runningSum += temp->data * multiplier;
			multiplier = multiplier * 10;
			//runningSum = temp->data;
			//res.push_back(runningSum);
			nodePtr = nodePtr->next;
		}
	}
	res.push_back(runningSum);
	return res;
}

void LinkedList::addCombined(int value)
{
	std::string tot = std::to_string(value);

	for (int i = 0; i < tot.length(); i++)
	{
		int temp = (int)tot[i] -48;
		appendNode(temp);
	}
}




