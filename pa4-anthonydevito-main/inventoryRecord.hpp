#pragma once

#include <string>
#include <iostream> // added header file

using namespace std;

class inventoryRecord {
public:
    inventoryRecord(){
        // this->ID = 0;
        // this->type = nullptr;
        // this->stock = 0;
    }
    inventoryRecord(int _id, string _type, int _stock)
    {
        this->ID = _id;
        this->type = _type;
        this->stock = _stock;
    }
    ~inventoryRecord(){}

    int getID() {return ID;}
    string getType(){return type;}
    int getStock(){return stock;}


    bool operator<(const inventoryRecord& other) const {
        return this->ID > other.ID;
    }

    bool operator>(const inventoryRecord& other) const {
        return this->ID < other.ID;
    }

    bool operator<=(const inventoryRecord& other) const {
        return this->ID >= other.ID;
    }

    bool operator>=(const inventoryRecord& other) const {
        return this->ID <= other.ID;
    }

    bool operator==(const inventoryRecord& other) const {
        return this->ID == other.ID;
    }
    bool operator!=(const inventoryRecord& other) const {
        return this->ID != other.ID;
    }
    

    

    void print() const{
        // cout << "country name: " << countryName << endl;
        // cout << "cancer rate: " << cancerRate << endl;
        cout << "Id: " << ID << ", type: " << type << ", stock: " << stock << endl;
    }

    
private:
    int ID;
    string type;
    int stock;

};

    

