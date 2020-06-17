#pragma once

//#include statements
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h> 
#include <stdlib.h>
#include "QueueNode.h"


//using statements
using std::cout;
using std::cin;
using std::endl;

class Queue
{
public: // Member functions
	Queue();
	~Queue();
	//random number generator function
	int generate_arrival_express();
	int generate_arrival_normal();
	int get_run_time();
	int time_elapsed = 0;
	bool enqueue(int customerNumber, int service, int total);
	int dequeue();

private:
	QueueNode *pHead;
	QueueNode *pTail;
};

//the error I was getting was because of a circular dependency in the include statements