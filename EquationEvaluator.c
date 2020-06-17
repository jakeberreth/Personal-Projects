#include "EquationEvaluator.h"

void newtons_second_law_of_motion()
{
	double mass = 0, acceleration = 0, force = 0;
	printf("NEWTON'S SECOND LAW OF MOTION\n\n");
	printf("Please enter decimal values for mass (kg) and acceleration (m/s^2): \n");
	printf("Mass: ");
	scanf("%lf", &mass);
	printf("Acceleration: ");
	scanf("%lf", &acceleration);
	force = mass * acceleration;
	printf("Newton's Second Law of Motion: force (F) = mass x acceleration\n\n");
	printf("F = %.2lf N\n\n", force);
}

void cylinder_volume()
{
	double pi = 3.14, radius = 0, height = 0, volume = 0;
	printf("---------------------------\n\nVOLUME OF A CYLINDER\n\n");
	printf("Please enter decimal values for the radius (m) and height (m) of a cylinder: \n");
	printf("Radius: ");
	scanf("%lf", &radius);
	printf("Height: ");
	scanf("%lf", &height);
	volume = pi * height * (radius * radius);
	printf("Volume (V) of a cylinder: PI x radius^2 x height\n\n");
	printf("V = %.2lf m^3\n\n", volume);
}

void character_encoding()
{
	int shiftKey = 0;
	char encodedCharacter = 0, plaintextCharacter;
	printf("---------------------------\n\nENCODED CHARACTER\n\n");
	printf("Please enter the character to encode: ");
	scanf(" %c", &plaintextCharacter);
	printf("Enter the shift key: ");
	scanf("%d", &shiftKey);
	encodedCharacter = (plaintextCharacter - 'A') + 'a' - shiftKey;
	printf("Encoded character = %c\n\n", encodedCharacter);
}

void distance_between_two_points()
{
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0, distance = 0;
	printf("---------------------------\n\nDISTANCE BETWEEN TWO POINTS\n\n");
	printf("Please enter the positions in units on a coordinate grid, of the two points: \n");
	printf("X for point 1: ");
	scanf("%lf", &x1);
	printf("Y for point 1: ");
	scanf("%lf", &y1);
	printf("X for point 2: ");
	scanf("%lf", &x2);
	printf("Y for point 2: ");
	scanf("%lf", &y2);
	printf("Distance (D) between two points: square root of (x1 - x2)^2 + (y1 - y2)^2\n\n");
	distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	printf("D = %.2lf units\n\n", distance);
}

void tangent_function()
{
	double theta = 0, tangentTheta = 0;
	printf("---------------------------\n\nTANGENT FUNCTION\n\n");
	printf("Please enter a degree value for theta: ");
	scanf("%lf", &theta);
	printf("tan(theta) = sin(theta)/cos(theta)\n\n");
	tangentTheta = sin(theta) / cos(theta);
	printf("tan(theta) = %.2lf rad.\n\n", tangentTheta);
}

void total_resistance_of_resistors_in_parallel()
{
	int r1, r2, r3;
	double totalResistance = 0;
	printf("---------------------------\n\nTOTAL RESISTANCE OF RESISTORS IN PARALLEL\n\n");
	printf("Please enter the resistance values of three resistors (ohms), each separated by one space: ");
	scanf("%d%d%d", &r1, &r2, &r3);
	printf("Total resistance (R) = 1 / (1/R1 + 1/R2 + 1/R3)\n\n");
	totalResistance = 1 / (1 / (double)r1 + 1 / (double)r2 + 1 / (double)r3);
	printf("R = %.2lf ohms\n\n", totalResistance);
}

void general_equation()
{
	double x, y, z, finalY;
	int a;
	printf("---------------------------\n\nGENERAL EQUATION\n\n");
	printf("Please enter a decimal value for x, y, and z, and an integer value for a, all separated by spaces: ");
	scanf("%lf%lf%lf%d", &x, &y, &z, &a);
	printf("y = (2 / 3) - y + z * x / (a % 2) + 3.14\n\n");
	finalY = (2 / 3) - y + z * x / (a % 2) + 3.14;
	printf("y = %.2lf\n\n", finalY);
}


