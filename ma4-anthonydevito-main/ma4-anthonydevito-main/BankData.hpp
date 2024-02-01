#ifndef BANK_DATA_H
#define BANK_DATA_H

#include <iostream>

class BankData
{
public:
	// Are the Big Five necessary?
	// How will this data work with the std::map?
	BankData(){
    mpAcctNum = new int(0);
    mpSavingsAmount = new double(0);
    mpCheckingAmount = new double(0);
    }

    // Copy constructor
	BankData(const BankData& other) {
		mpAcctNum = new int(*other.mpAcctNum);
		mpSavingsAmount = new double(*other.mpSavingsAmount);
		mpCheckingAmount = new double(*other.mpCheckingAmount);
	}


	// move constructor
    BankData(BankData&& other) noexcept{
		mpAcctNum = other.mpAcctNum;
        mpSavingsAmount = other.mpSavingsAmount;
        mpCheckingAmount = other.mpCheckingAmount;

        other.mpAcctNum = nullptr;
        other.mpSavingsAmount = nullptr;
        other.mpCheckingAmount = nullptr;
    }

    // copy assignment operator
    BankData& operator=(const BankData& other)
    {
        if (this != &other)
        {
            *mpAcctNum = *other.mpAcctNum;
            *mpSavingsAmount = *other.mpSavingsAmount;
            *mpCheckingAmount = *other.mpCheckingAmount;
        }
        return *this;
    }

	// move assigment operator
	BankData& operator=(BankData&& other) noexcept
    {
        if (this != &other)
        {
            delete mpAcctNum;
            delete mpSavingsAmount;
            delete mpCheckingAmount;

            mpAcctNum = other.mpAcctNum;
            mpSavingsAmount = other.mpSavingsAmount;
            mpCheckingAmount = other.mpCheckingAmount;

            other.mpAcctNum = nullptr;
            other.mpSavingsAmount = nullptr;
            other.mpCheckingAmount = nullptr;
        }
        return *this;
    }

	~BankData()
    {
        delete mpAcctNum;
        delete mpSavingsAmount;
        delete mpCheckingAmount;
    }

	int getAcctNum() const {return *mpAcctNum;} // we do want to return a copy of the int, not the pointer
	double getSavingsAmount() const {return *mpSavingsAmount;} // we do want to return a copy of the double, not the pointer
	double getCheckingAmount() const {return *mpCheckingAmount;} // we do want to return a copy of the double, not the pointer

	void setAcctNum(const int& newAcctNum) {*mpAcctNum = newAcctNum;} // you need to implement
	void setSavingsAmount(const double& newSavingsAmount) {*mpSavingsAmount = newSavingsAmount;} // you need to implement
	void setCheckingAmount(const double& newCheckingAmount){*mpCheckingAmount = newCheckingAmount;} // you need to implement

private:
	int* mpAcctNum;
	double* mpSavingsAmount, * mpCheckingAmount;
};

#endif

