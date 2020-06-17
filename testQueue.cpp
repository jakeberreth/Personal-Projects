#include "testQueue.h"

void Tests::testEnqueueOnEmptyQueue()
{
	Queue q; // q is init to empty using default constructor
	bool success = false; // true, false
	int c = 4;
	int s = 2;
	int t = 43;

	success = q.enqueue(c, s, t);

	if (success)
	{
		std::cout << "Allocated space successfully!" << std::endl;
	}
	else {
		std::cout << "Not allocated successfully" << std::endl;
	}
}

void Tests::testDequeue()
{
	Queue q;
	int customerNum = 5;
	bool success = false;
	customerNum = q.dequeue();
	if (customerNum > 0)
	{
		std::cout << "Success!" << endl;
	}
	else 
	{
		std::cout << "Fail." << endl;
	}
}

//in order to get this to work, I had to correctly initialize the constructor of Queue, to nullptr