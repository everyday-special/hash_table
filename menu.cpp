/* Purpose: Defines the menu member functions
 * Author: Matthew Lidell
 * CS260 Project 3
 * Date: 11/7/21
 * file: menu.cpp
 */
#include "menu.h"


Menu::Menu()
{
	table = new Table();
	results = new Website[MAX_SIZE];
	results_size = new int(0);
}



Menu::~Menu()
{
	delete table;
	table = nullptr;
	delete results_size;
	delete [] results;
	results_size = nullptr;
	results = nullptr;
}



void Menu::run()
{
	char reply; // Used to store user input

	do
	{
		printMenu();
		reply = getReply();
		doCommand(reply);
	}
	while (reply != 'q');
}



void Menu::printMenu()
{
	std::cout << "\nMenu Options:" << std::endl;
	std::cout << "a) Display all websites in the table." << std::endl;
	std::cout << "b) Display all websites of a specific topic." << std::endl;
	std::cout << "c) Insert a new website into the table." << std::endl;
	std::cout << "d) Retrieve all websites of a specific topic." << std::endl;
	std::cout << "e) Edit a specific website." << std::endl;
	std::cout << "f) Remove all websites with a rating of 1." << std::endl;
	std::cout << "g) View last retrieved results." << std::endl;
	std::cout << "h) View the chain lengths of the table." << std::endl;
	std::cout << "q) Quit." << std::endl;
}



const char Menu::getReply()
{
	std::cout << "Please make a selection from the options shown above: " << std::endl;
	return getChar();
}



void Menu::doCommand(const char reply)
{
	std::cout << std::endl;
	switch (reply)
	{
		case 'a':
			displayAll();
			break;
		case 'b':
			displayTopic();
			break;
		case 'c':
			insert();
			break;
		case 'd':
			remove();
			break;
		case 'e':
			edit();
			break;
		case 'f':
			retrieve();
			break;
		case 'g':
			viewRetrievedResults();
			break;
		case 'h':
                        viewChainLengths();
                        break;
		case 'q':
			std::cout << "Exiting menu..." << std::endl;
			break;
		default:
			std::cout << "'" << reply << "' is not a valid option. Please try again." << std::endl;
	}
}



const Website Menu::getWebsite()
{
	char newTopic[MAX_SIZE];
	char newAddress[MAX_SIZE];
	char newSummary[MAX_SIZE];
	char newReview[MAX_SIZE];
	int newRating;

	std::cout << "Please enter the website's topic: ";
	getString(newTopic);
	std::cout << "Please enter the website's address: ";
	getString(newAddress);
	std::cout << "Please enter a summary of the website: ";
	getString(newSummary);
	std::cout << "Please enter your review of the website: ";
	getString(newReview);
	std::cout << "Please enter a rating of the website from 1 to 5: ";
	newRating = getInt();
	while (newRating < 1 || newRating > 5)
	{
		std::cout << "Please enter a rating from 1 to 5: ";
		newRating = getInt();
	}
	return Website(newTopic, newAddress, newSummary, newReview, newRating);
}



void Menu::insert()
{
	Website newWebsite = getWebsite();

	table->insert(newWebsite);
}



void Menu::displayAll()
{
	bool ret = table->display();
	if (!ret)
		std::cout << "\nTable is empty." << std::endl;
}



void Menu::displayTopic()
{
	char query[MAX_SIZE];
	bool ret;

	std::cout << "\nPlease enter the topic you wish to search for: " << std::endl;
	getString(query);
	ret = table->displayByTopic(query);
	if (!ret)
		std::cout << "No websites with a topic of '" << query << "' are in the table." << std::endl;
}



void Menu::retrieve()
{
	char query[MAX_SIZE];
	bool ret;

	std::cout << "\nPlease enter the topic for which you wish to retrieve all websites: " << std::endl;
	getString(query);
	*results_size = 0;
	ret = table->retrieve(query, results, *results_size);
	if (ret)
		std::cout << *results_size << " were retrieve for '" << query << "'.\nSelect option 'g' in the menu to view the retrieved results." << std::endl;
	else
		std::cout << "No websites with a topic of '" << query << "' are in the table. No websites were retrieved." << std::endl;
}



void Menu::viewRetrievedResults()
{
	std::cout << "\nViewing previously retrieved results:" << std::endl;
	for (int i = 0; i < *results_size; i++)
		std::cout << i <<")'\n'" << results[i] << std::endl;
}



void Menu::edit()
{
	char queryTopic[MAX_SIZE];
	char queryAddress[MAX_SIZE];
	char newReview[MAX_SIZE];
	int newRating;
	bool ret;

	std::cout << "Please enter the topic of the website you want changed: ";
	getString(queryTopic);
	std::cout << "Please enter the address of the website you want changed: ";
	getString(queryAddress);
	std::cout << "Please enter your new review for this website: ";
	getString(newReview);
	std::cout << "Please enter the new rating for this website (from 1 to 5): ";
	newRating = getInt();
	while (newRating < 1 || newRating > 5)
	{
		std::cout << "The rating must be a number from 1 to 5. Please try again: ";
		newRating = getInt();
	}
	ret = table->edit(queryTopic, queryAddress, newReview, newRating);
	if (!ret)
		std::cout << "'" << queryTopic << "' and '" << queryAddress << "' did not match any existing entries." << std::endl;
	else
		std::cout << "'" << queryAddress << "' was successfully updated." << std::endl;
}



void Menu::remove()
{
	std::cout << table->remove() << " websites with a rating of 1 were removed from the table." << std::endl;
}



void Menu::viewChainLengths()
{
	table->chainLengths();
}
