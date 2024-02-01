#pragma once
#include <iostream>
#include <string>


using namespace std;

class Destination {
  public:
    //Destination(int pos, string city_name) : position(pos), name(city_name) {}

    Destination()
    {
      position = 0;
      name = "";
    }
    Destination(int pos, string city_name){
      this->name = city_name;
      this->position = pos;
    }


    ~Destination() {}
    
    void printPosition() {
      cout << position;
    }
    
    void printDestinationName() {
      cout << name;
    }


  
    int position;
    string name;
};

