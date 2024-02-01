#include "Heap.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main (void){
    srand(time(0));
    Heap<int> h;


    for (int i = 1; i <= 1000; i++)
    {

        h.push(rand() % 1000000 + 1);
        
    }
    h.print_array();
    h.print_smallest();
    return 0;
}