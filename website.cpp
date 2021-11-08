/* Matthew Lidell
 * CS 260
 * Project 3
 * 11/3/21
 * File: website.cpp
 * Purpose: Defines website class member and friend functions
 */
#include "website.h"

Website::Website()
{
	topic = nullptr;
	address = nullptr;
	summary = nullptr;
	review = nullptr;
	rating = nullptr;
}



Website::Website(const char newTopic[], const char newAddress[], const char newSummary[], const char newReview[], const int newRating)
/* Overloaded constructor for website class
 * Parameters:
 * 	-const char newTopic[] - cstring representing the new website's topic
 * 	-const char newAddress[] - cstring representing the new website's address
 * 	-const char newSummary[] - cstring representing the new website's summary
 * 	-const char newReview[] - cstring representing the new website's review
 * 	-const int newRating - integer representing the new website's rating from 1 to 5
 * Return: None
 */
{
	int strLen; // Stores length of input strings

	strLen = strlen(newTopic);
	this->topic = new char[++strLen];
	strcpy(this->topic, newTopic);
	strLen = strlen(newAddress);
	this->address = new char[++strLen];
	strcpy(this->address, newAddress);
	strLen = strlen(newSummary);
	this->summary = new char[++strLen];
	strcpy(this->summary, newSummary);
	strLen = strlen(newReview);
	this->review = new char[++strLen];
	strcpy(this->review, newReview);
	this->rating = new int(newRating);
}



Website::Website(const Website& srcWebsite)
/* Copy constructor for website class
 * Parameters:
 * 	-const Website srcWebsite - website object whose data is being copied into a new website object
 * Return: None
 */
{
        int strLen; // Stores length of input strings

	strLen = strlen(srcWebsite.topic);
        this->topic = new char[++strLen];
        strcpy(this->topic, srcWebsite.topic);
        strLen = strlen(srcWebsite.address);
        this->address = new char[++strLen];
        strcpy(this->address, srcWebsite.address);
        strLen = strlen(srcWebsite.summary);
        this->summary = new char[++strLen];
        strcpy(this->summary, srcWebsite.summary);
        strLen = strlen(srcWebsite.review);
        this->review = new char[++strLen];
        strcpy(this->review, srcWebsite.review);
        this->rating = new int((*srcWebsite.rating));
}



Website::~Website()
/* Destructor for website class
 * Parameters: None
 * Return: None
 */
{
	delete [] topic;
	topic = nullptr;
	delete [] address;
	address = nullptr;
	delete [] summary;
	summary = nullptr;
	delete [] review;
	review = nullptr;
	delete rating;
	rating = nullptr;
}



void Website::operator=(const Website& srcWebsite)
/* Overloaded assignment operator for website class
 * Parameters:
 *      -const Website& srcWebsite - website object whose data is being copied into a new website object
 * Return: None
 */
{
	int strLen; // Stores length of input strings

	delete [] topic;
	delete [] address;
	delete [] summary;
	delete [] review;
	delete rating;

        strLen = strlen(srcWebsite.topic);
        this->topic = new char[++strLen];
        strcpy(this->topic, srcWebsite.topic);
        strLen = strlen(srcWebsite.address);
        this->address = new char[++strLen];
        strcpy(this->address, srcWebsite.address);
        strLen = strlen(srcWebsite.summary);
        this->summary = new char[++strLen];
        strcpy(this->summary, srcWebsite.summary);
        strLen = strlen(srcWebsite.review);
        this->review = new char[++strLen];
        strcpy(this->review, srcWebsite.review);
        this->rating = new int((*srcWebsite.rating));
}



/*void Website::getTopic(char result[])
* Accessor method for topic attribute
 * Parameters: char result[] - topic attribute is copied into this cstring
 * Return: None
 *
{
	strcpy(result, this->topic);
}



void Website::getAddress(char result[])
* Accessor method for address attribute
 * Parameters: char result[] - address attribute is copied into the cstring
 * Return: None
 *
{
	strcpy(result, this->address);
}*/



/*int Website::getRating()
* Accessor method for rating attribute
 * Parameters: None
 * Return: int - integer value of rating attribute
 *
{
	return *(this->rating);
}*/



void Website::setReview(const char newReview[])
/* Mutator method for review attribute
 * Parameters: const char& newReview[] - cstring containing the new value for the review attribute
 * Return: None
 */
{
	int strLen; // Stores length of input strings

	delete [] this->review;
	strLen = strlen(newReview);
	this->review = new char[++strLen];
	strcpy(this->review, newReview);

}



void Website::setRating(const int& newRating)
/* Mutator method for rating attribute
 * Parameters: const int& newRating - int representing the new value for the rating attribute
 * Return: None
 */
{
	delete this->rating;
	this->rating = new int(newRating);
}



std::ostream& operator<<(std::ostream& out, const Website& website)
/* Overloaded << operator for website class
 * Parameters:
 * 	-std::ostream& out - ostream object
 * 	-const Website& website - website object whose data is being printed
 * Return:
 * 	-std::ostream& - ostream object with data being printed
 */
{
	out << "Topic: " << website.topic;
	out << "\nAddress: " << website.address;
	out << "\nSummary: " << website.summary;
	out << "\nReview: " << website.review;
	out << "\nRating: " << *(website.rating) << "/5";
	return out;
}
