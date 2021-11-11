/* Matthew Lidell
 * CS 260
 * Project 3
 * 11/3/21
 * File: linkedlist.h
 * Purpose: Defintion for linked list class
 */
#pragma once
#include "utils.h"
#include "website.h"
#include <iostream>

class LinkedList
/* Class representing a linked list of Website objects
 * This class has a privately defined Node struct representing an item/node in the linked list
 * This class has 2 private data members:
 * 	-Node * head - pointer to the first node in the LinkedList
 * 	-int * size - pointer to an int containing the size of the LinkedList
 * This class has 2 private member functions:
 * 	-displayAllRecursive() - recursive helper function for displaying all items in the linkedlist
 * 	-displayAllByTopicRecursive() - recursive helper function for displaying all items of a specific topic in the linked list
 * This class has a friend class Table
 * This class has 9 public member functions:
 * 	-Default constructor
 * 	-Default destructor
 * 	-add() - adds a new website object to the linked list
 * 	-getSize() - gets the current size of the linked list
 * 	-displayAll() - displays all items in the linked list
 * 	-displayAllByTopic() - displays all websites in the linked list whose topic matches the specified topic
 * 	-edit() - edits the review and rating for a website in the linked list that matches the specified topic and address
 */
{
	public:
		LinkedList();
		~LinkedList();
		void add(Website & newWebsite);
		int removeByRating(const int & rating);
		int getSize();
		bool displayAll();
		bool retrieve(const char query[], Website matches[], int & num_found);
		bool displayAllByTopic(const char query[]);
		bool edit(const char query[], const char newReivew[], const int & newRating);

	private:
		struct Node
		/* Struct representing a node in the LinkedList
		 * Node has 2 data attributes:
		 * 	- Website * data - pointer to Website object stored at this node
		 * 	- Node * next - pointer to the next node in the LinkedList
		 * Node has 3 member and friend functions:
		 * 	-Overloaded constructor
		 * 	-Default destructor
		 * 	-Overloaded insertion operator
		 */
		{
			Node(const Website& website)
			/* Purpose: overloaded constructor for Node object
			 * Parameters: const Website& website - website to store at this node
			 * Return: None
			 */
			{
				this->data = new Website(website);
				this->next = nullptr;
			}
			~Node()
			/* Purpose: default destructor for Node object
			 * Parameters: None
			 * Return: None
			 */
			{
				delete data;
				data = nullptr;
				next = nullptr;
			}
			friend std::ostream& operator<<(std::ostream& out, const Node& node)
			/* Purpose: Overloaded insertion operator for printing Website data
			 * Parameters:
			 * 	-std::ostream& out - ostream object
			 * 	-const Node& node - node to be printed
			 * Return: std::ostream& out - ostream object with data inserted
			 */
			{
				out << *(node.data);
				return out;
			}
			Website * data; // Stores reference to the website object at this node
			Node * next; // Stores reference to the next node in the list
		};
		Node * head; // Stores reference to the front of the LinkedList
		int * size; // Stores reference to the size of the LinkedList
		void displayAllRecursive(Node *& curr);
		void displayAllByTopicRecursive(Node *& curr, const char query[]);
		friend class Table;
};
