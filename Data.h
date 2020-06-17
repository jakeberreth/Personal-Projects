#pragma once

//#include statements
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h> 
#include <stdlib.h>

//using statements
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::istream;
using std::fstream;

class Data
{
public: // Member functions
	Data();
	Data(int customerNum, int service, int total);
	~Data();
	void setCustomerNumber(int customerNum);
	void setService(int service);
	void setTotal(int total);
	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();
	
private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
}; // This memory needs to be allocated on the heap!