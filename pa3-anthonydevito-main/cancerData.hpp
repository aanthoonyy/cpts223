#pragma once

#include <string>
#include <iostream> // added header file

using namespace std;

class CancerData {
public:
    CancerData(){}
    CancerData(string _countryName, double _cancerRate)
    {
        this->countryName = _countryName;
        this->cancerRate = _cancerRate; 
    }
    ~CancerData(){}

    string getCountryName() { return countryName;}
    double getCancerRate() { return cancerRate;}

    bool operator<(const CancerData& other) const {
        return this->cancerRate > other.cancerRate;
    }

    bool operator>(const CancerData& other) const {
        return this->cancerRate < other.cancerRate;
    }

    bool operator<=(const CancerData& other) const {
        return this->cancerRate >= other.cancerRate;
    }

    bool operator>=(const CancerData& other) const {
        return this->cancerRate <= other.cancerRate;
    }

    void print() const{
        // cout << "country name: " << countryName << endl;
        // cout << "cancer rate: " << cancerRate << endl;
        cout << countryName << ". " << cancerRate << ">" << endl;
    }

    
private:
    string countryName;
    double cancerRate;
};

    

