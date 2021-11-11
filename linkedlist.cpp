/* Matthew Lidell
 * Cs 260
 * Project 3
 * 11/3/21
 * File: linkedlist.cpp
 * Purpose: Defintion of the linedlist class member functions
 */
#include "linkedlist.h"

LinkedList::LinkedList()
/* Purpose: Default Constructor for LinkedList object
 * Parameters: None
 * Return: None
 */
{
	head = nullptr;
	size = new int(0);
}



LinkedList::~LinkedList()
/* Purpose: Default destructor for LinkedList Object
 * Parameters: None
 * Return: None
 */
{
	Node * temp; // Stores temporary reference to head node before deletion

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
/* Purpose: adds a new website to the front LinkedList
 * Parameters: Website & newWebsite - website object to add to the linked list
 * Return: None
 */
{
	Node * newNode = new Node(newWebsite); // new Node being added to the list
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
/* Purpose: Gets the current size of the linkedlist
 * Parameters: None
 * Return: int - current size of the linkedlist
 */
{
	return *(this->size);
}



bool LinkedList::displayAll()
/* Purpose: Displays all the data in the linked list
 * Parameters: None
 * Return: bool - true if list is non-empty, false if it is empty
 */
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
/* Purpose: recursive helper function for displaying all nodes
 * Parameters: Node *& curr - reference to the current node in the list
 * Return: None
 */
{
	if (curr)
	{
		std::cout << '\n' << *curr << std::endl;
		displayAllRecursive(curr->next);
	}
}



int LinkedList::removeByRating(const int& rating)
/* Purpose: removes all Websites in the list with a specified rating or lower
 * Parameters: const int& rating - cutoff rating for removal
 * Return: int - number of websites removed from the list
 */
{
	int original = *size; // Stores original size of list before removal
	Node * curr = head; // reference to current node being checked
	Node * prev = nullptr; // reference to previous node checked

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
/* Purpose: Displays all websites in the list that match a specified topic
 * Parameters: const char query[] - topic to search the list by
 * Return: bool - true if list is non-empty and website matches were found, false if not
 */
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
/* Purpose: recursive helper function for displaying all nodes by topic
 * Parameters:
 * 	-Node *& curr - reference to the current node
 * 	-const char query[] - topic to search the list by
 * Return: None
 */
{
	if (curr)
	{
		if (strcmp((*(curr->data)).topic, query) == 0)
			std::cout << '\n' << *curr << std::endl;
		displayAllByTopicRecursive(curr->next, query);
	}
}



bool LinkedList::retrieve(const char query[], Website matches[], int & num_found)
/* Purpose: retrieves all websites matching the topic and stores them in an array which is passed in by reference
 * Parameters:
 * 	-const char query[] - topic to search the table by
 * 	-Website matches[] - array of websites to store the matches in. Passed in by reference
 * 	-int & num_found - number matches found. Passed in by reference.
 * Return: bool - true if matches were found, false if not
 */
{
	Node * curr = head; // reference to current node being checked
	bool found = false; // stores whether or not a match has been found

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
/* Purpose: edits the reivew and rating for a website that matches the given address
 * Parameters:
 * 	-const char query[] - address to search the linkedlist by
 *	-const char newReview[] - new review for the website
 *	-const int& newRating - new rating for the website (1 to 5)
 * Return: bool - true if a match was found and modified, false if not
 */
{
	Node * curr = head; // reference to current node being checked

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
