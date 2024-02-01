#include <ctime>
#include <cstdlib>
#include "ListMyJoesph.hpp"

void testListMJ(){
    srand(time(NULL));
    int x = rand() % 1025; // N
    int y = rand() % x; // M
    int line = rand() % 25;
// Repeat the tests for : N=4,M=3  ; N=8,M=3 ;  N=16,M=3 ;  N=32,M=3 ; N=64,M=3 ; N=128,M=3 ; 
// N=256,M=3 ; N=512,M=3 ; N=1024,M=3 ; N=512,M=2 ; N=512,M=4 ; N=512,M=8 ; N=512,M=16 ;  
// N=512,M=32 ; N=512,M=64 ; N=512,M=128 ;  N=512,M=256 
    //int x = 512; // N
    //int y = 256; // M
    ListMyJosephus lmj;
    double timingBetweenElims;
    double totalTime;
    fstream testFile("listTesting.txt", std::ios_base::app);

    clock_t start=clock();
    timingBetweenElims = lmj.RunListMyJosephus(x,y, line);
    clock_t end=clock();
    totalTime = (double)(end - start)/CLOCKS_PER_SEC;
    testFile << "N:" << x << " M: "<< y << endl <<"Total CPU TIME: " 
            << totalTime*1000 <<" milliseconds" << endl << "AVG time between deletion: " 
            << timingBetweenElims*1000000 << " microseconds" << endl << endl;
    



}