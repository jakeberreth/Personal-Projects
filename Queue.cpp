#include "Queue.h"
#include "QueueNode.h"
#include <time.h>

//constructor
Queue::Queue()
{
	this->pHead = this->pTail = nullptr;
}


//destructor
Queue::~Queue()
{

}

//generate arrival time for express lane function definition
int Queue::generate_arrival_express()
{
	srand(time(0));
	int num = rand() % 5 + 1;
	return num;
}

int Queue::generate_arrival_normal()
{
	srand(time(0));
	int num = 3 + rand() % ((8 + 1) - 3);
	return num;
}

int Queue::get_run_time()
{
	int runTime = 0;
	cout << "How long would you like the simulation to run (in minutes)? " << endl;
	cin >> runTime;
	return runTime;
}

bool Queue::enqueue(int customerNumber, int service, int total)
{
	QueueNode *pMem = new QueueNode();
	bool success = false;

	if (pMem != nullptr)
	{
		// allocated space
		success = true;
		if (this->pHead == nullptr)
		{
			// empty queue
			this->pHead = this->pTail = pMem;
		}
		else
		{
			// non empty queue
			this->pTail->setNextPtr(pMem); 
			this->pTail = pMem;
		}
	}
	return success;
}

int Queue::dequeue()
{
	int customerNum = 5;
	QueueNode *pTemp = nullptr;

	if (this->pTail == this->pHead)
	{
		pTemp = this->pHead;
		this->pHead = this->pTail = nullptr;
		customerNum = pTemp->getCustomerNumber(); //make setters and getters for data values
		delete pTemp;
	}
	else
	{
		// more than 1 node in queue
		pTemp = this->pHead;
		this->pHead = this->pHead->getNextPtr();
		customerNum = pTemp->getCustomerNumber();
		delete pTemp;
	}

	return customerNum;
}