/* Purpose: Defines the menu class
 * Author: Matthew Lidell
 * CS260 Project 3
 * Date: 11/7/21
 * file: menu.h
 */
#pragma once
#include "table.h"


class Menu
/*
 */
{
	public:
		Menu();
		~Menu();
		void run();

	private:
		void printMenu();
		const char getReply();
		void doCommand(const char reply);
		void displayAll();
		void displayTopic();
		void insert();
		const Website getWebsite();
		void retrieve();
		void viewRetrievedResults();
		void edit();
		void remove();
		void viewChainLengths();
		Table * table; // Pointer to table object
		Website * results; // Stores retrieved results between retrievals
		int * results_size; // Stores size of retrieved results between retrievals
};
