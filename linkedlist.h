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
		{
			Node(const Website& website)
			{
				this->data = new Website(website);
				this->next = nullptr;
			}
			~Node()
			{
				delete data;
				data = nullptr;
				next = nullptr;
			}
			friend std::ostream& operator<<(std::ostream& out, const Node& node)
			{
				out << *(node.data);
				return out;
			}
			Website * data;
			Node * next;
		};
		Node * head;
		int * size;
		void displayAllRecursive(Node *& curr);
		void displayAllByTopicRecursive(Node *& curr, const char query[]);
};
