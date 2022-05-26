/* Matthew Lidell
 * 11/7/21
 * File: table.h
 * Purpose: Definition for linked list class
 */
#pragma once
#include "linkedlist.h"
#include <fstream>

class Table
/* Class representing a hash table containing saved website data and reviews
 * This class has 3 private data attributes:
 * 	-table - array of pointers to LinkedList objects
 * 	-arraySize - pointer to int representing the maximum size of the array table
 *	-currSize - pointer to int containing the current number of websites in the table
 * This class has 1 private member function:
 * 	-hash() - hashing function. Turns a cstring into an integer from 0 to 100 (inclusive)
 * This class has 11 public member functions:
 * 	-Default constructor
 * 	-Default destructor
 * 	-insert() - adds a new website to the table
 * 	-retrieve() - retrieves all websites with a given topic from the table
 * 	-edit() - edits the review and rating for a website that matches a given topic and address
 * 	-remove() - removes all websites with a rating of 1 from the table
 * 	-displayByTopic() - displays all websites that have a specific topic
 * 	-display() - displays all websites in the table
 * 	-chainLengths() - displays the length of all the chains in the table. If a chain is empty, nothing is displayed
 * 	-saveToFile() - saves all data in the table to a file
 * 	-loadFromFile() - loads all data from a file into the table
 */
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
		bool saveToFile(const char filename[]);
                bool loadFromFile(const char filename[]);
	
	private:
		LinkedList * * table;
		int * arraySize;
		int *currSize;
		int hash(const char topic[]);
};
