#include "Data.h"

Data::Data()
{
	//default constructor
}

Data::Data(int customerNum, int service, int total)
{
	customerNumber = customerNum;
	serviceTime = service;
	totalTime = total;
}

Data::~Data()
{
	//destructor
}

void Data::setCustomerNumber(int customerNum)
{
	customerNumber = customerNum;
}

int Data::getCustomerNumber()
{
	return customerNumber;
}

void Data::setService(int service)
{
	serviceTime = service;
}

int Data::getServiceTime()
{
	return serviceTime;
}

void Data::setTotal(int total)
{
	totalTime = total;
}

int Data::getTotalTime()
{
	return totalTime;
}

