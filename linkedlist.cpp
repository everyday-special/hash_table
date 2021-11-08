/* Matthew Lidell
 * Cs 260
 * Project 3
 * 11/3/21
 * File: linkedlist.cpp
 * Purpose: Defintion of the linedlist class member functions
 */
#include "linkedlist.h"

LinkedList::LinkedList()
{
	head = nullptr;
	size = new int(0);
}



LinkedList::~LinkedList()
{
	Node * temp;

	while (head)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	delete size;
	size = nullptr;
	temp = nullptr;
	head = nullptr;
}



void LinkedList::add(Website & newWebsite)
{
	Node * newNode = new Node(newWebsite);
	if (head)
	{
		newNode->next = head;
		head = newNode;
	}
	else
		head = newNode;
	(*size)++;
}



int LinkedList::getSize()
{
	return *(this->size);
}



bool LinkedList::displayAll()
{
	if ((*size) > 0)
	{
		displayAllRecursive(head);
		return true;
	}
	else
		return false;
}



void LinkedList::displayAllRecursive(Node *& curr)
{
	if (curr)
	{
		std::cout << *curr << std::endl;
		displayAllRecursive(curr->next);
	}
}



int LinkedList::removeByRating(const int& rating)
{
	int original = *size;
	Node * curr = head;
	Node * prev = nullptr;

	while (curr)
	{
		if ((*(curr->data)->rating) <= rating)
		{
			if (prev)
			{
				prev->next = curr->next;
				delete curr;
				curr = prev->next;
				(*size)--;
			}
			else
			{
				head = curr->next;
				delete curr;
				curr = head;
				(*size)--;
			}
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
	return original - (*size);
}



bool LinkedList::displayAllByTopic(const char query[])
{
	if ((*size) > 0)
       	{
       	        displayAllByTopicRecursive(head, query);
       	        return true;
       	}
        else
                return false;
}



void LinkedList::displayAllByTopicRecursive(Node *& curr, const char query[])
{
	if (curr)
	{
		if (strcmp((*(curr->data)).topic, query) == 0)
			std::cout << *curr << std::endl;
		displayAllByTopicRecursive(curr->next, query);
	}
}



bool LinkedList::retrieve(const char query[], Website matches[], int & num_found)
{
	Node * curr = head;
	bool found = false;

	while (curr)
	{
		if (strcmp((*(curr->data)).topic, query) == 0)
		{
			found = true;
			matches[num_found++] = (*(curr->data));
		}
		curr = curr->next;
	}
	return found;
}



bool LinkedList::edit(const char query[], const char newReview[], const int& newRating)
{
	Node * curr = head;

	while (curr)
	{
		if (strcmp(query, (*(curr->data)).address) == 0)
		{
			(*(curr->data)).setReview(newReview);
			(*(curr->data)).setRating(newRating);
			return true;
		}
		curr = curr->next;
	}
	return false;
}
