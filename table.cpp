/* Matthew Lidell
 * 11/7/21
 * File: table.cpp
 * Purpose: Defines the table class member and friend functions
 */
#include "table.h"

Table::Table()
/* Purpose: Default constructor for table object
 * Parameters: None
 * Return: None
 */
{
	arraySize = new int(101); // Instantiates arraySize to 101 (prime number!)
	table = new LinkedList*[*arraySize]; // Instantiates array of pointers to LinkedList objects
	for (int i = 0; i < *arraySize; i++)
		table[i] = nullptr; // Sets all indices to nullptr (no data)
	currSize = new int(0); // Instantiates currSize to 0 (no data)
}



Table::~Table()
/* Purpose: Default destructor for table object
 * Parameters: None
 * Return: None
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
/* Purpose: Hashing function. Converts a cstring to a int from 0 to 100
 * Parameters: None
 * Return: None
 */
{
	int seed = 3; // Prime number to multiply by to prevent 'abc' and 'cba' from having the same hash
	int hash = 0; // Stores hash for given cstring
	int i = 0; // index of character in cstring
	while (topic[i] != '\0')
		hash = (hash * seed) % *arraySize + topic[i++];
	return hash % *arraySize;
}



void Table::insert(Website & newWebsite)
/* Purpose: inserts a website into the table
 * Parameters: Website & newWebsite - website being added to table
 * Returns: None
 */
{
	int h = hash(newWebsite.topic); // hash value for given topic
	if (!(table[h]))
		table[h] = new LinkedList();
	table[h]->add(newWebsite);
	(*currSize)++;
}



bool Table::retrieve(const char query[], Website matches[], int & num_found)
/* Purpose: Fills an array with all websites in the table that match a specified topic
 * Parameters:
 * 	-const char query[] - topic to search the table by
 * 	-Website matches[] - array to fill with website matches
 * 	-int & num_found - number of websites added to the array. Passed by reference
 * Return: bool - true if one or more websites were retrieved, false if no websites were retrieved.
 */
{
	int h = hash(query); // hash value for given topic
	if (table[h])
		return table[h]->retrieve(query, matches, num_found);
	else
		return false;
}



bool Table::edit(const char queryTopic[], const char queryWebsite[], const char newReview[], const int newRating)
/* Purpose: edits the review and rating for a Website that matches a given topic and address
 * Parameters:
 * 	-const char queryTopic[] - topic to search the table by
 * 	-const char queryWebsite[] - address to search the table by
 * 	-const char newReview[] - new review for the website
 * 	-const int newRating - new rating for the website (int from 1 to 5)
 * Return: bool - true if website is in table and was modified, false if not
 */
{
	int h = hash(queryTopic); // hash value for given topic
	if (table[h])
		return table[h]->edit(queryWebsite, newReview, newRating);
	else
		return false;
}



int Table::remove()
/* Purpose: removes all websites with rating of 1 or less from table
 * Parameters: None
 * Return: int - number of websites removed from the table
 */
{
	int numRemoved = 0; // number of items removed from list
	for (int i = 0; i < *arraySize; i++)
		if (table[i])
			numRemoved += table[i]->removeByRating(1);
	*currSize -= numRemoved;
	return numRemoved;
}



bool Table::displayByTopic(const char query[])
/* Purpose: Displays all data with a specific topic in the table
 * Parameters: const char query[] - topic to search table by
 * Return: bool - true if websites with topic were in the table and printed, false if not
 */
{
	int h = hash(query); // hash value for topic
	if (table[h])
		return table[h]->displayAllByTopic(query);
	else
		return false;
}



bool Table::display()
/* Purpose: Displays all data in the table
 * Parameters: None
 * Return: bool - true if table is non-empty, false if table is empty
 */
{
	bool found = false; // whether or not websites have been printed
	for (int i = 0; i < *arraySize; i++)
	{
		if (table[i])
			found = (table[i]->displayAll() || found);
	}
	return found;
}



void Table::chainLengths()
/* Purpose: Displays length of all non-zero chains in the table
 * Parameters: None
 * Return: None
 */
{
	for (int i = 0; i < *arraySize; i++)
		if (table[i])
			std::cout << "Chain " << i << ": " << table[i]->getSize() << std::endl;
}



bool Table::loadFromFile(const char filename[])
/* Purpose: Loads data from correctly formatted file
 * Parameters: const char filename[] - name of file to load data from
 * Return: bool - true if data was successfully loaded, false if not
 */
{
	char tempTopic[MAX_SIZE]; // Stores topic data from file
	char tempAddress[MAX_SIZE]; // stores address data from file
	char tempSummary[MAX_SIZE]; // stores summary data from file
	char tempReview[MAX_SIZE]; // stores review data from file
	int tempRating; // stores rating data from file
	std::ifstream inFile; // file stream

	inFile.open(filename);
	if (!inFile)
		return false;

	inFile.get(tempTopic, MAX_SIZE, ';');
	while (!inFile.eof())
	{
		inFile.get();
		inFile.get(tempAddress, MAX_SIZE, ';');
		inFile.get();
		inFile.get(tempSummary, MAX_SIZE, ';');
		inFile.get();
		inFile.get(tempReview, MAX_SIZE, ';');
		inFile.get();
		inFile >> tempRating;
		inFile.ignore(MAX_SIZE, '\n');
	
		Website newWebsite(tempTopic, tempAddress, tempSummary, tempReview, tempRating);
		insert(newWebsite);

		inFile.get(tempTopic, MAX_SIZE, ';');
	}
	inFile.close();
	return true;
}



bool Table::saveToFile(const char filename[])
/* Purpose: saves data to file
 * Parameters: const char filename[] - name of file to save data to
 * Return: bool - true if data was successfully saved, false if not
 */
{
	LinkedList::Node * curr; // reference to current node being saved
	std::ofstream outFile; // file stream

	outFile.open(filename);
	if (!outFile)
		return false;

	for (int i = 0; i < *arraySize; i++)
	{
		if (table[i])
		{
			curr = table[i]->head;
			while (curr)
			{
				outFile << curr->data->topic << ';' << curr->data->address << ';' << curr->data->summary << ';' << curr->data->review << ';' << *(curr->data->rating) << std::endl;
				curr = curr->next;
			}
		}
	}
	outFile.close();
	return true;	
}
