/* Matthew Lidell
 * CS 260
 * Project 3
 * 11/7/21
 * File: table.h
 * Purpose: Definition for linked list class
 */
#pragma once
#include "linkedlist.h"

class Table
{
	public:
		Table();
		~Table();
		void insert(Website & newWebsite);
		bool retrieve(const char query[], Website matches[], int & num_found);
		bool edit(const char queryTopic[], const char queryWebsite[], const char newReview[], const int newRating);
		int remove();
		bool displayByTopic(const char query[]);
		bool display();
		void chainLengths();
	
	private:
		LinkedList * * table;
		int * arraySize;
		int *currSize;
		int hash(const char topic[]);
};
