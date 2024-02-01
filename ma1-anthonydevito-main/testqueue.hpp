#pragma once
#include <iostream>
#include <cstdlib>
#include "queue.hpp"
using namespace std;

// define default capacity of the queue
#define SIZE 10

// Class for queue
class testQueue
{
    

public:
	testQueue(); 	// constructor
	~testQueue();   				// destructor

	void testDequeue();
	void testEnqueue();
	void testPeek();
	void testSize();
	void testIsEmpty();
	void testIsFull();
};

