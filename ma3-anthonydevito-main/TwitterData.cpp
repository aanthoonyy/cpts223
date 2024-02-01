#include "TwitterData.hpp"
#include <string>

using namespace std;
TwitterData::TwitterData () 
{
	mpUserName =  mpActualName = mpEmail = mpCategory = nullptr;
	mpNumTweets = nullptr;
}

// destructor
TwitterData::~TwitterData()
{
	// Task 1(b) - you need to implement
}

//Copy constructor - deep copy
TwitterData::TwitterData(const TwitterData& other) 
{
	// Task 1(b) - you need to implement
    mpUserName = new std::string;
	mpActualName = new string;
	mpEmail = new string;
	mpCategory = new string;
	mpNumTweets = new int;
    *mpUserName = other.getUserName();
	*mpActualName = other.getActualName();
	*mpEmail = other.getEmail();
	*mpCategory = other.getCategory();
	*mpNumTweets = other.getNumTweets();
}

//Move constructor
TwitterData::TwitterData(TwitterData&& other)
{
	// Task 1(b) - you need to implement
	this->mpUserName = other.mpUserName;
	this->mpActualName = other.mpActualName;
	this->mpEmail = other.mpEmail;
	this->mpCategory = other.mpCategory;
	this->mpNumTweets = other.mpNumTweets;

	other.mpUserName = nullptr;
	other.mpActualName = nullptr;
	other.mpEmail = nullptr;
	other.mpCategory = nullptr;
	other.mpNumTweets = nullptr;
}

//Copy assignment operator
TwitterData& TwitterData::operator=(TwitterData& other)
{
	// Task 1(b) - you need to implement
	*mpUserName = *other.mpUserName;
	*mpActualName = *other.mpActualName;
	*mpEmail = *other.mpEmail;
	*mpCategory = *other.mpCategory;
	*mpNumTweets = *other.mpNumTweets;

	return *this;

}

//Move assignment operator
TwitterData& TwitterData::operator=(TwitterData&& other)
{
	// Task 1(b) - you need to implement
    if (this != &other)
    {
        delete mpUserName;
        delete mpActualName;
        delete mpEmail;
        delete mpCategory;
        delete mpNumTweets;
        
        mpUserName = other.mpUserName;
        mpActualName = other.mpActualName;
        mpEmail = other.mpEmail;
        mpCategory = other.mpCategory;
        mpNumTweets = other.mpNumTweets;
        
        other.mpUserName = nullptr;
        other.mpActualName = nullptr;
        other.mpEmail = nullptr;
        other.mpCategory = nullptr;
        other.mpNumTweets = nullptr;
    }
    return *this;
}

std::string TwitterData::getUserName() const
{
	return *(this->mpUserName);
}

std::string TwitterData::getActualName() const
{
	return *(this->mpActualName);
}

std::string TwitterData::getEmail() const
{
	return *(this->mpEmail);
}

std::string TwitterData::getCategory() const
{
	return *(this->mpCategory);
}

int TwitterData::getNumTweets() const
{
	return *(this->mpNumTweets);
}

void TwitterData::setUserName(const std::string& newUserName)
{
	// Task 1(a) - you need to implement
	// do we need to allocate space for a std::string here?
	*mpUserName = newUserName;
}
// assume actualname = last,first;
void TwitterData::setActualName(const std::string& newActualName)
{
	// Task 1(a) - you need to implement
	// do we need to allocate space for a std::string here?
	*mpActualName = newActualName;
}

void TwitterData::setEmail(const std::string& newEmail)
{
	// Task 1(a) - you need to implement
	// do we need to allocate space for a std::string here?
	*mpEmail = newEmail;
}

void TwitterData::setCategory(const std::string& newCategory)
{
	// Task 1(a) - you need to implement
	// do we need to allocate space for a std::string here?
	*mpCategory = newCategory;
}

void TwitterData::setNumTweets(const int& newNumTweets)
{
	// Task 1(a) - you need to implement
	// do we need to allocate space for an int here?
	*mpNumTweets = newNumTweets;

}