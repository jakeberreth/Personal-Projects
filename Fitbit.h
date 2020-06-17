#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//enum sleep definition
typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

//struct FitbitData definition
typedef struct fitbit 
{ 
	char patient[10];      
	char minute[9];      
	double calories;      
	double distance;      
	unsigned int floors;      
	unsigned int heartRate; 
	unsigned int steps; 
	Sleep sleepLevel; 
} FitbitData;

//Function prototypes
void parse_records(FILE *pInput, char recordsTemp[][200], char records[][200], double calculations_cals_distance[], unsigned int calculations_floors_steps_heart_rate[], FitbitData fitbitArray[]);
int calculations_of_totals(FitbitData fitbitArray[], double calculations_cals_distance[], int calculations_floors_steps_heart_rate[]);
double calculate_average_heart_rate(int total);
int calculate_poor_sleep_range(FitbitData fitbitArray[], char minutes[][20]);
void recordTests(FitbitData fitbitArray[]);
