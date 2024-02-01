#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include "node.hpp"
using namespace std;


class Data{

public:
    string command;
    string definition;
    string points;

    

    Data(){command = "", definition = "", points = "";}
    Data(string command, string definition, string points)
    {
        this->command = command;
        this->definition = definition;
        this->points = points;
        
    }

};
