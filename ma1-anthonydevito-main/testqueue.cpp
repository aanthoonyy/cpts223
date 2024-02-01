#include "testqueue.hpp"
// Constructor to initialize queue
testQueue::testQueue()
{

}

// Destructor to free memory allocated to the queue
testQueue::~testQueue()
{
	//delete arr; // you are not required to test this function;
	            // however, are there issues with it?
}

// Utility function to remove front element from the queue


/* Test ID: test dequeue check - tdqc
Unit: queue::dequeue ()
Description: test to determine if queue::dequeue () dequeues nodes
Test steps:
1. Construct an empty queue object
2. queues 5 nodes
3 checks sizes of queue
3. dequeues 5 nodes
4. checks size of queue
()
Test data: size = 0
Precondition: has 5 nodes queued
Postcondition: queue has 0 nodes
Expected result: queue has 0 nodes; cout "passed"
Actual result: queue has 0 nodes; cout "passed"
Status: passed
*/
void testQueue::testDequeue()
{
    queue *q;
	testQueue *tQ;

    q = new queue(5);
    
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    int test = q->size();
    if (test == 5){
        
        q->dequeue();
        q->dequeue();
        q->dequeue();
        q->dequeue();
        q->dequeue();
        test = q->size();
        if (test == 0)
        {
            cout << "testDequeue passed" << endl;
        }
    }
    else{
        cout << "testDequeue() failed " << endl;
    }
}

/* Test ID: test queue check - tqc
Unit: queue::Enqueue ()
Description: test to determine if queue::enqueue () queues nodes
Test steps:
1. Construct an empty queue object
2. queues 5 nodes
3 checks sizes of queue
3. 
()
Test data: size = 0
Precondition: 
Postcondition: queue has 5 nodes
Expected result: queue has 5 nodes; cout "passed"
Actual result: queue has 5 nodes; cout "passed"
Status: passed
*/
void testQueue::testEnqueue()
{
    queue *q;
	testQueue *tQ;

    q = new queue(5);
    
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    int test = q->size();
    if (test == 5){
        cout << "testEnqueue() passed" << endl;
    }
    else{
        cout << "testEnqueue() failed " << endl;
    }
    
    
}


/* Test ID: test peek - tp
Unit: queue::peek ()
Description: test to determine if queue::peek () peeks the first node correctly
Test steps:
1. Construct an empty queue object
2. queues 5 nodes
3 checks if the peeked node is equal to the first node
3. 
()
Test data: size = 0
Precondition: 
Postcondition: queue has 5 nodes
Expected result: peek noded is the same as the first insertered node
Actual result: peek noded is the same as the first insertered node
Status: passed
*/
void testQueue::testPeek()
{
	queue *q;
	testQueue *tQ;

    q = new queue(5);

    q->enqueue(0);
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);

    int test;
    test = q->peek();
    if (test == 0){
        cout << "testPeek() passed" << endl;
    }
    else{
        cout << "testPeek() failed" << endl;
    }
}

/* Test ID: test size - ts
Unit: queue::size ()
Description: test to determine if queue::size () returns correct queue size
Test steps:
1. Construct an empty queue object
2. queues 5 nodes
3 checks if the size is equal to 5
3. 
()
Test data: size = 0
Precondition: queue has 5 nodes
Postcondition: queue has 5 nodes verified
Expected result: testsize validates that there are 5 nodes in that queue
Actual result: testsize validates that there are 5 nodes in that queue
Status: passed
*/
void testQueue::testSize()
{
	queue *q;
	testQueue *tQ;

    q = new queue(5);

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    int test;
    test = q->size();
    if (test == 5)
    {
        cout << "testSize() passed" << endl;
    }
    else
    {
        cout << "testSize() failed" << endl;
    }

}

/* Test ID: Empty queue check - EQC
Unit: queue::isEmpty ()
Description: test to determine if queue::isEmpty () returns 1 if a
queue object is empty
Test steps:
1. Construct an empty queue object
2. Invoke queue::isEmpty ()
3
3. Conditionally evaluate the valued returned by queue::isEmpty
()
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is still empty
Expected result: queue is empty; 1 is returned
Actual result: queue is empty; 1 is returned
Status: passed
*/
void testQueue::testIsEmpty()
{
    queue *q;
	testQueue *tQ;

    bool test;
    test = q->isEmpty();

    if (test == true)
    {
        cout << "test isEmpty() passed" << endl;
    }
    else
    {
        cout << "test isEmpty() failed" << endl;
    }
}

/* Test ID: test is full - tif
Unit: queue::isFull ()
Description: test to determine if queue::isFull () tells if the queue is full
Test steps:
1. Construct an empty queue object
2. queues 5 nodes
3 uses a bool to set test varible to isFull() result (true or false)
3. 
()
Test data: size = 0
Precondition: queue has 5 nodes
Postcondition: returns true
Expected result: the queue is full
Actual result: the queue is full
Status: passed
*/
void testQueue::testIsFull()
{
    
    queue *q = new queue(5);
    testQueue *tQ;

    //q = new queue(5);

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    bool test;
    test = q->isFull();
    if (test == true){
        cout << "test isFull() passed" << endl;
    }
    else {
        cout << "test isFull() failed" << endl;
    }
}
