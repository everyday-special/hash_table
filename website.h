/* Matthew Lidell
 * CS 260
 * Project 3
 * 11/3/21
 * File: website.h
 * Purpose: Defines the website class
 */
#pragma once
#include <cstring>
#include <ostream>

class Website
/* Clas representing an website information
 */
{
	public:
		Website();
		Website(const char newTopic[], const char newAddress[], const char newSummary[], const char newReview[], const int newRating);
		Website(const Website& srcWebstire);
		~Website();
		void operator=(const Website& srcWebsite);
		//void getTopic(char result[]);
		//void getAddress(char result[]);
		//void getSummary(char result[]);
		//void getReview(char result[]);
		//int getRating();
		void setReview(const char newReview[]);
		void setRating(const int& newRating);
		
		friend std::ostream& operator<<(std::ostream& out, const Website& website);

	private:
		char * topic; // Holds website topic
		char * address; // Holds website address
		char * summary; // Holds summary of website contents
		char * review; // Holds written review of website
		int * rating; // Holds numerical rating of 1 to 5
		friend class LinkedList;
		friend class Table;
};
