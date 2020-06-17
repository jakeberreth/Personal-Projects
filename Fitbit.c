#include "Fitbit.h"


//FUNCTION: parse_records
//Return type: void
//Reads all the Fitbit data records in the 
//FitbitData.csv file, one string at a time
void parse_records(FILE *pInput, char recordsTemp[][200], char records[][200], double calculations_cals_distance[], unsigned int calculations_floors_steps_heart_rate[], FitbitData fitbitArray[])
{
	//Temporary array used to manipulate lines read in from the file
	char recordDefinition[200];

	//Get the first line of the file, which is not included in the data
	fgets(recordDefinition, 200, pInput);

	//While loop to dedup and clean each line in the file
	int i = 0, k = 0;
	while (i < 1444)
	{
		fgets(recordDefinition, 200, pInput);
			for (int j = 0; j < strlen(recordDefinition); ++j)
			{
				if (recordDefinition[j] == ',' && recordDefinition[j + 1] == ',')
				{
					char tempStr[100];
					strcpy(tempStr, &recordDefinition[j + 1]);
					recordDefinition[j + 1] = '-';
					recordDefinition[j + 2] = '1';
					strcpy(&recordDefinition[j + 3], tempStr);
				}
				if (recordDefinition[j] == '\n')
				{
					recordDefinition[j] = '\0';
				}

				if (recordDefinition[j] == ',' && recordDefinition[j + 1] == '\n')
				{
					recordDefinition[j + 1] = '-';
					recordDefinition[j + 2] = '1';
					recordDefinition[j + 3] = '\0';
				}
			}
			//Copy the manipulated line to the records array
			strcpy(recordsTemp[k], recordDefinition);
			i++;
			k++;
		}
	//Change any lines with the wrong patient name to the correct patient name
	i = 0;
	while (i < 1444)
	{
		if (recordsTemp[i][1] = '3')
		{
			recordsTemp[i][0] = '1';
			recordsTemp[i][1] = '2';
			recordsTemp[i][2] = 'c';
			recordsTemp[i][3] = 'x';
			recordsTemp[i][4] = '7';
		}
		i++;
	}
	//Compare lines to check for duplicates
	i = 0, k = 0;
	while (i < 1444)
	{
		if (strcmp(recordsTemp[i], recordsTemp[i + 1]) == 0)
		{
			i++;
		}
		else {
			strcpy(records[k], recordsTemp[i]);
			i++;
			k++;
		}
	}
	//While loop to parse lines into corresponding fields, convert strings into field types
	//and store into FitbitData array
	i = 0;
	while (i < 1440)
	{
		strcpy(fitbitArray[i].patient, strtok(records[i], ","));
		strcpy(fitbitArray[i].minute, strtok(NULL, ","));
		fitbitArray[i].calories = atof(strtok(NULL, ","));
		fitbitArray[i].distance = atof(strtok(NULL, ","));
		fitbitArray[i].floors = atoi(strtok(NULL, ","));
		fitbitArray[i].heartRate = atoi(strtok(NULL, ","));
		fitbitArray[i].steps = atoi(strtok(NULL, ","));
		fitbitArray[i].sleepLevel = atoi(strtok(NULL, "\0"));
		i++;
	}
}

//FUNCTION: calculations_of_totals
//Return type: int
//calculates the total values for steps, floors, heartrate, calories, 
//distance, and the max number of steps in one minute
int calculations_of_totals(FitbitData fitbitArray[], double calculations_cals_distance[], int calculations_floors_steps_heart_rate[])
{
	int i = 0;
	while (i < 1440)
	{
		if (fitbitArray[i].calories != -1.0 && fitbitArray[i].distance != -1 &&
			fitbitArray[i].floors != -1 && fitbitArray[i].heartRate != -1 &&
			fitbitArray[i].steps != -1)
		{
			calculations_cals_distance[0] += fitbitArray[i].calories;
			calculations_cals_distance[1] += fitbitArray[i].distance;
			calculations_floors_steps_heart_rate[0] += fitbitArray[i].steps;
			calculations_floors_steps_heart_rate[1] += fitbitArray[i].floors;
			calculations_floors_steps_heart_rate[2] += fitbitArray[i].heartRate;
		}
		i++;
	}
	i = 0;
	int max = 0;
	while (i < 1440)
	{
		if (fitbitArray[i].steps > max)
		{
			max = fitbitArray[i].steps;
		}
		i++;
	}
	return max;
}

//FUNCTION: calculate_average_heart_rate
//Return type: double
//Calculates the average heart rate over 24 hours
double calculate_average_heart_rate(int total)
{
	double average = total / 1440.0;
	return average;
}

//FUNCTION: calculate_poor_sleep_range
//Return type: int
//calculates the range of poor sleep over 24 hours
int calculate_poor_sleep_range(FitbitData fitbitArray[], char minutes[][20])
{
	int i = 0, j = 0, k = 0, temp = 0, greatestSum = 0;
	int sum[20] = { 0 };
	char startingMinute[20];
	char endingMinute[20];
	while (i < 1440)
	{
		j = 1;
		if (fitbitArray[i].sleepLevel > 1)
		{
			int currentSum = fitbitArray[i].sleepLevel;
			while (fitbitArray[i + j].sleepLevel > 1)
			{
				currentSum += fitbitArray[i + j].sleepLevel;
				sum[k] = currentSum;
				j++;
				temp = j - 1;
			}
			j = 1;
			if (fitbitArray[i + j].sleepLevel > 1)
			{
				if (sum[k] > sum[k - 1])
				{
					greatestSum = sum[k];
					strcpy(startingMinute, fitbitArray[i].minute);
					strcpy(endingMinute, fitbitArray[i + temp].minute);
				}
				k++;
			}		
		}
		i += j + 1;
	}
	strcpy(minutes[0], startingMinute);
	strcpy(minutes[1], endingMinute);

	return greatestSum;
}

//FUNCTION: recordTests
//Return type: void
//Used for testing to make sure that the records and fitbit struct array 
//stored the correct data
void recordTests(FitbitData fitbitArray[])
{
	printf("\n\n\n\n\n");
	/*printf("Test 1: Record 20, SL 1 - %d\n", fitbitArray[20].sleepLevel);
	printf("Test 2: Record 1432, SL 3 - %d\n", fitbitArray[1432].sleepLevel);*/
	int i = 0;
	while (i < 1400)
	{
		printf("Record %d: Calories: %.7lf\n", i + 1, fitbitArray[i].calories);
		i++;
	}

	i = 0;
	/*while (i < 1440)
	{
		if (fitbitArray[i].floors > 0)
		{
			printf("record %d: %d\n", i + 1, fitbitArray[i].floors);
		}
		i++;
	}*/
}