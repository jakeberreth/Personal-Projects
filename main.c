/*********************************************************************
Name: Jake Berreth
Project: Fitbit Data Integration
Date Completed: September 4, 2019
Description: Clean and parse the data in a Fitbit.csv file 
			 into corresponding fields and display calculations 
             in a Results.csv file
**********************************************************************/

#include "Fitbit.h"

int main()
{
	//Open FitbitData.csv for mode read
	FILE *pInput = fopen("FitbitData.csv", "r");

	//Declare an array of FitbitData structs
	FitbitData fitbitArray[1440];

	/*Declare a temporary array to store the lines in the file
	  to then store in another array after a condition is met*/
	char recordsTemp[1444][200], records[1444][200];

	//Check the success of file opening operation
	if (pInput == NULL)
	{
		printf("FitbitData.csv did not open successfully.\n\n\n");
	}
	else
	{
		printf("FitbitData.csv opened successfuly.\n\n\n");
	}

	/*Declarations of variables: total calories, total distance, 
	  total floors climbed, total steps, and average heartrate*/
	double calculations_cals_distance[2] = { 0.0 }; //Must be initialized
	unsigned int calculations_floors_steps_heart_rate[3] = { 0 }; 

	/*Read each record in the file as a string one line at a time
	  and parse the data members in each line into corresponding fields
	  in the array of FitbitData structs*/
	parse_records(pInput, recordsTemp, records, calculations_cals_distance, 
		          calculations_floors_steps_heart_rate, fitbitArray);

	/*Calculations: total calories, total distance, total floors climbed
	                total steps, largest number of steps take in one minute*/
	int maxSteps = calculations_of_totals(fitbitArray, calculations_cals_distance, 
		                                  calculations_floors_steps_heart_rate);

	//Calculate the average heart rate over 24 hours
	double averageHeartRate = calculate_average_heart_rate(calculations_floors_steps_heart_rate[2]);

	/*Calculate the longest range of poor sleep:
	  minutes array to store the starting and ending minutes
	  of the longest range of poor sleep*/
	char minutes[2][20];
	int greatestSum = calculate_poor_sleep_range(fitbitArray, minutes);

	/*Function to print lines from the file before or after being cleaned
	  and parsed, to check that the previous functions worked correctly*/
	//recordTests(fitbitArray);

	//Open Results.csv for mode write
	FILE *pOutput = fopen("Results.csv", "w");

	//Print calculations to the Results.csv file
	fprintf(pOutput, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
	fprintf(pOutput, "%.2lf, %.2lf, %d, %d, %d, %.2lf, %s:%s", calculations_cals_distance[0], 
			calculations_cals_distance[1], calculations_floors_steps_heart_rate[1], 
		    calculations_floors_steps_heart_rate[0], maxSteps, averageHeartRate, minutes[0], minutes[1]);

	//Close FitbitData.csv and Results.csv
	fclose(pInput);
	fclose(pOutput);

	//Exit status: The program ran successfully
	return 0;
}