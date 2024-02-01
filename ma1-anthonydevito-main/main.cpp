// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn

#include "queue.cpp"
#include "testqueue.cpp"

//attributes
// comments could be considered poor, could use more in queue.cpp but i think overall testqueue.cpp has enough
// i could have added multiple conditionals for each test case to pass to make sure it passes
// maybe it would have been nice to be able to have a queue that gets inserted into the test cases so i dont have to make a queue everytime
// test cases could all be done in one test function
// print out more data to the screen so the user can see what got tested specifically

// main function
int main()
{
	// call your test functions here!
	
	testQueue *tQueue;
	
	tQueue = new testQueue();
	
	tQueue->testSize();

	cout << endl;
	tQueue->testIsFull();

	cout << endl;
	tQueue->testIsEmpty();

	cout << endl;
	tQueue->testSize();

	cout << endl;
	tQueue->testEnqueue();

	cout << endl;
	tQueue->testDequeue();


	cout << endl;
	tQueue->testPeek();
	

	return 0;
}

