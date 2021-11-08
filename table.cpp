/* Matthew Lidell
 * CS 260
 * Project 3
 * 11/7/21
 * File: table.cpp
 * Purpose: Defines the table class member and friend functions
 */
#include "table.h"

Table::Table()
/*
 */
{
	arraySize = new int(101);
	table = new LinkedList*[*arraySize];
	for (int i = 0; i < *arraySize; i++)
		table[i] = nullptr;
	currSize = new int(0);
}



Table::~Table()
/*
 */
{
	delete currSize;
	for (int i = 0; i < *arraySize; i++)
	{
		delete table[i];
		table[i] = nullptr;
	}
	delete [] table;
	delete arraySize;
	arraySize = nullptr;
	currSize = nullptr;
	table = nullptr;
}



int Table::hash(const char topic[])
/*
 */
{
	int seed = 3;
	int hash = 0;
	int i = 0;
	while (topic[i] != '\0')
		hash = (hash * seed) % *arraySize + topic[i++];
	return hash % *arraySize;
}



void Table::insert(Website & newWebsite)
{
	int h = hash(newWebsite.topic);
	if (!(table[h]))
		table[h] = new LinkedList();
	table[h]->add(newWebsite);
}



bool Table::retrieve(const char query[], Website matches[], int & num_found)
/*
 */
{
	int h = hash(query);
	if (table[h])
		return table[h]->retrieve(query, matches, num_found);
	else
		return false;
}



bool Table::edit(const char queryTopic[], const char queryWebsite[], const char newReview[], const int newRating)
/*
 */
{
	int h = hash(queryTopic);
	if (table[h])
		return table[h]->edit(queryWebsite, newReview, newRating);
	else
		return false;
}



int Table::remove()
/*
 */
{
	int numRemoved = 0;
	for (int i = 0; i < *arraySize; i++)
		if (table[i])
			numRemoved += table[i]->removeByRating(1);
	return numRemoved;
}



bool Table::displayByTopic(const char query[])
/*
 */
{
	int h = hash(query);
	if (table[h])
		return table[h]->displayAllByTopic(query);
	else
		return false;
}



bool Table::display()
/*
 */
{
	bool found = false;
	for (int i = 0; i < *arraySize; i++)
	{
		if (table[i])
			found = (table[i]->displayAll() || found);
	}
	return found;
}



void Table::chainLengths()
/*
 */
{
	for (int i = 0; i < *arraySize; i++)
		if (table[i])
			std::cout << "Chain " << i << ": " << table[i]->getSize() << std::endl;
}
