#include "QueueNode.h"

QueueNode::QueueNode()
{
	pNext = nullptr;
}

QueueNode::~QueueNode()
{
	//destructor
}

void QueueNode::setNextPtr(QueueNode *newNext)
{
	pNext = newNext;
}

QueueNode *QueueNode::getNextPtr() const
{
	return pNext;
}

void QueueNode::setDataPtr(Data *newData)
{
	pData = newData;
}

Data *QueueNode::getDataPtr() const
{
	return pData;
}

void QueueNode::setCustomerNumber(int customerNum)
{
	customerNumber = customerNum;
}

int QueueNode::getCustomerNumber()
{
	return customerNumber;
}

void QueueNode::setService(int service)
{
	serviceTime = service;
}

int QueueNode::getServiceTime()
{
	return serviceTime;
}

void QueueNode::setTotal(int total)
{
	totalTime = total;
}

int QueueNode::getTotalTime()
{
	return totalTime;
}


