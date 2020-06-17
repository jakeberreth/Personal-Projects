/***************************
Name: Jake Berreth
Project: 
****************************/

#include "Queue.h"
#include "Data.h"
#include "QueueNode.h"
#include "testQueue.h"

int main()
{
	//variables
	int customerNumberNormal = 1, customerNumberExpress = 1;
	int serviceTimeNormal = 0, serviceTimeExpress = 0;
	int totalTimeNormal = 0, totalTimeExpress = 0;
	int amountTimeElapsed = 0;
	int runTime = 0;

	Queue express;
	Queue normal;
	runTime = express.get_run_time();
	serviceTimeExpress = express.generate_arrival_express();
	serviceTimeNormal = normal.generate_arrival_normal();
	cout << "This simulation will run for " << runTime << " minutes. " << endl;
	cout << "Arrival time of the first customer in the normal lane: " << serviceTimeNormal << endl;
	cout << "Arrival time of the first customer in the express lane: " << serviceTimeExpress << endl;

	Tests t;
	t.testEnqueueOnEmptyQueue();
	t.testDequeue();

	//int time = 0;
	//while (time < runTime)
	//{
	//	
	//}
}
