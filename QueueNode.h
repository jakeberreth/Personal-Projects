#pragma once

//#include statements
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h> 
#include <stdlib.h>
#include "Data.h"


//using statements
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::istream;
using std::fstream;

class QueueNode
{
public: // Member functions
	QueueNode();
	~QueueNode();
	void setNextPtr(QueueNode *newNext);
	QueueNode *getNextPtr() const;
	void setDataPtr(Data *newData);
	Data *getDataPtr() const;
	void setCustomerNumber(int customerNum);
	void setService(int service);
	void setTotal(int total);
	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();


private:
	int customerNumber;
	int serviceTime;  
	int totalTime;
	Data *pData;   
	QueueNode *pNext;
};