#pragma once
#include <iostream>
#include <ctime>
#include <ostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Destination.h"

using namespace std;

class VectorMyJosephus {
  public:
    
    VectorMyJosephus(){};
    VectorMyJosephus(int M, int N){}

    double RunVectorMyJosephus(int N, int M, int line){

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
            vector<string> erased;
            int Ncopy = N;
            double time_between_erases = 0;
            while(destinations.size() != 1)
            {
                  if (count == 0)
                  {
                  cout << "original destinations" << endl;
                  printAllDestinations();
                  count++;
                  }
                  if (count != Ncopy){
                  cout << endl << endl << "round number " << count << endl;
                  }
                   printAllDestinations();
                  clock_t start=clock();
                  eliminateDestination(destinations, M, N, count, erased, Ncopy, line, time_between_erases);
                  clock_t end=clock();
                  time_between_erases += (double)(end - start)/CLOCKS_PER_SEC;
                  count++;
              }
        
          if (destinations.size() == 1) {
                    cout << endl << "------------------------------" << endl << "Survivor ";
                      destinations[0].printDestinationName();
                      cout << "#";
                      destinations[0].printPosition();
                      cout << endl << "N value: " << Ncopy << " M value: " << M << " selected line: " << line << endl; 

            //cout << "test" << time_between_erases << endl;
            
                return (time_between_erases / count);
            
        }
        //currentLine++;
    }
    

    ~VectorMyJosephus() {}
    
    void clear() {
      destinations.clear();
    }
    
    int currentSize() {
      return destinations.size();
    }
    
    bool isEmpty() {
      return destinations.empty();
    }
    
    double eliminateDestination(vector<Destination> &destinations, int M, int N, int count, vector<string> erased, int Ncopy, int line, double time_between_erases) {
      
      // if (count == 0)
      // {
      // cout << "original destinations" << endl;
      // printAllDestinations();
      // count++;
      // }
      // if (count != Ncopy){
      // cout << endl << endl << "round number " << count << endl;
      // }
      
      // if (destinations.size() == 1) {
      //   cout << endl << "------------------------------" << endl << "Survivor ";
      //     destinations[0].printDestinationName();
      //     cout << endl << "N value: " << Ncopy << " M value: " << M << " selected line: " << line << endl;
      //     double test = 0;
      //     test = time_between_erases;
      //     return test;
      // }

      N = ((N + M) % destinations.size());
      cout << endl;
      cout << "removing " << destinations[N].name << "#" << destinations[N].position << endl << endl;
      //cout << "still in the list" << endl;
      erased.push_back(destinations[N].name);
      
      destinations.erase(destinations.begin() + N);
      
      
      //cout << "survivors" << endl;
     
      //cout << "survivors" << endl;
      //eliminateDestination(destinations, M, N, count + 1, erased, Ncopy, line, time_between_erases);
        }
      
    
    
    void printAllDestinations() {
      for (int i = 0; i < destinations.size(); i++)
      {

        destinations[i].printDestinationName();
        cout << "#";
        destinations[i].printPosition();
        cout << ";";
        
      }
    }
    
  private:
    int M;
    int N;
    vector<Destination> destinations;
    
};

