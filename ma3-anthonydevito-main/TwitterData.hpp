#ifndef TWITTER_DATA_H
#define TWITTER_DATA_H

#include <iostream>
#include <string>

class TwitterData
{
public:
	TwitterData ();

	// Task 1(b) - Implement the Big Five for TwitterData
	// destructor
	~TwitterData();
	//Copy constructor - deep copy
	TwitterData(const TwitterData& other);
	//Move constructor
	TwitterData(TwitterData&& other);
	//Copy assignment operator
	TwitterData& operator=(TwitterData& other);
	//Move assignment operator
	TwitterData& operator=(TwitterData&& other);

	std::string getUserName() const; // we do want to return a copy of the string, not the pointer
	std::string getActualName() const; //assume actualname = last,first;  do we do want to return a copy of the string, not the pointer
	std::string getEmail() const; // we do want to return a copy of the string, not the pointer
	std::string getCategory() const; // we do want to return a copy of the string, not the pointer
	int getNumTweets() const; // we do want to return a copy of the integer, not the pointer

	void setUserName(const std::string &newUserName); // Task 1(a) - you need to implement
	void setActualName(const std::string& newActualName); // Task 1(a) - you need to implement
	void setEmail(const std::string &newEmail); // Task 1(a) - you need to implement
	void setCategory(const std::string &newCategory); // Task 1(a) - you need to implement
	void setNumTweets(const int &newNumTweets); // Task 1(a) - you need to implement

private:
	// assume actualname = last,first
	std::string *mpUserName, *mpActualName, 
		*mpEmail, *mpCategory;
	int *mpNumTweets;	
};

#endif

