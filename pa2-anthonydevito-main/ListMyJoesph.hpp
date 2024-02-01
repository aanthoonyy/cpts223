#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <list>
#include "Destination.h"

using namespace std;

class ListMyJosephus {
  public:
  
    ListMyJosephus(){}

    double RunListMyJosephus(int N, int M, int line){
      srand(time(NULL));
       string grab;
    
    ifstream infile("destinations.csv");
    int currentLine = 1;
    int index = 0;
    while (getline(infile, grab))
    {
        if (currentLine == line)
        {
            stringstream ss(grab);
            string item;
            while (getline(ss, item, ';') && destinations.size() < N)
            {
                ++index;
                Destination dest(index, item);
                destinations.push_back(dest);
                
            }

        }
        currentLine++;
    }
      int count = 0;
      int Ncopy = N;
      double avgTimeBetweenElims;
      while (destinations.size() != 1 && count != Ncopy)
      {
        if (count == 0)
        {
        cout << "original destinations" << endl;
        printAllDestinations();
        count++;
        }
        clock_t start=clock();
        cout << "round #" << count << endl;
        
        printAllDestinations();
        cout << endl;
        cout << endl;
        eliminateDestination(destinations, M, N);
        clock_t end=clock();
        avgTimeBetweenElims += (double)(end - start)/CLOCKS_PER_SEC;
        count++;
      }
      
      if (destinations.size() == 1) {
        cout << "-------------" << endl;
        cout << "Survivor: ";
        destinations.front().printDestinationName();
        cout << "#";
        destinations.front().printPosition();
        cout << endl;
        cout << endl << "N value: " << N << " M value: " << M << " selected line: " << line << endl;
          
          
          return avgTimeBetweenElims / count;
      }
      
            
    }
  
    ~ListMyJosephus() {}
    
    void clear() {
      destinations.clear();
    }
    
    int currentSize() {
      return destinations.size();
    }
    
    bool isEmpty() {
      return destinations.empty();
    }
    
    void eliminateDestination(list<Destination> &destinations, int M, int N) {

      //printAllDestinations();
      // cout << "removing " << destinations.front() + N << "#" << endl << endl;
      // cout << "still in the list" << endl;
      
      N = ((N + M - 1) % destinations.size());
      auto beg = destinations.begin();
      advance(beg, N);
      cout << "removing ";
      beg->printDestinationName();
      cout<<"#";
      beg->printPosition();
      cout << ";" << endl << endl;
      
      destinations.erase(beg);
      
      //cout << "still in the game" << endl;
      
        
      //eliminateDestination(destinations, M, N);
      }
      
    
    
    void printAllDestinations() {
      auto beg = destinations.begin();
      for (int i = 1; i < destinations.size(); i++)
      {
        advance(beg, i);
        //cout << "";
        beg->printDestinationName();
        cout<<"#";
        beg->printPosition();
        cout << ";";
        
        
      }
      cout << endl;
    }

  private:
    int M;
    int N;
    list<Destination> destinations;
    
};

