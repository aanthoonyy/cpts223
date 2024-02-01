
#include <ctime>
#include <cstdlib>
#include "VectorMyJoseph.hpp"
#include <iostream>
#include <fstream>
void testVectorMJ(){
    srand(time(NULL));
    int x = rand() % 1025;
    int y = rand() % x;
//     Repeat the tests for : N=4,M=3  ; N=8,M=3 ;  N=16,M=3 ;  N=32,M=3 ; N=64,M=3 ; N=128,M=3 ; 
// N=256,M=3 ; N=512,M=3 ; N=1024,M=3 ; N=512,M=2 ; N=512,M=4 ; N=512,M=8 ; N=512,M=16 ;  
// N=512,M=32 ; N=512,M=64 ; N=512,M=128 ;  N=512,M=256 
    //int x = 512; // N
    //int y = 256; // M
    int line = rand() % 25 + 1;
    fstream testFile("vectorTesting.txt", std::ios_base::app);
    VectorMyJosephus vmj;
    double timeBetweenTwo;
    clock_t start=clock();
    timeBetweenTwo = vmj.RunVectorMyJosephus(x,y, line);
    clock_t end=clock();

       double total_time = (double)(end - start)/CLOCKS_PER_SEC;
      testFile << "N:" << x << " M: "<< y << endl <<"Total CPU TIME: " << total_time*1000 <<" milliseconds" << endl << "AVG time between deletion: " << timeBetweenTwo*100000 << " microseconds" << endl << endl;

}