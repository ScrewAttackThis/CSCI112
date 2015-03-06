/*
 * Michael Shihrer
 * Lab 4, CSCI 112
 * 5 Mar 15
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//Constants
#define PI 3.14159
#define LOOP_LIMIT 90

//MENU enum definition
typedef enum MENU {
	SINE,
	COSINE,
	TANGENT,
	QUIT
} menu_t;


//Function prototypes
void userMenu();
void computeSin(double angle);
void computeCos(double angle);
void computeTan(double angle);
void computeValues();
double degreeToRadian(double angle);
double radianToDegree(double angle);

int main(void)
{
	userMenu();
}

void userMenu()
{
	//Menu variable
	menu_t input;
	do
	{
		printf("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\n");
		printf("Enter your choice > ");
		scanf("%d",&input);

		switch(input)
		{
			case SINE:
				computeValues(computeSin);
				break;
			case	COSINE:
				computeValues(computeCos);
				break;
			case TANGENT:
				computeValues(computeTan);
				break;
			default:
				printf("%d is an invalid option.  Please try again.\n", input);
				break;
		}
	}while(!(input == QUIT));
}

void computeSin(int angle)
{
	double result = 0.0;
	result = sin(degreeToRadian(angle));
	printf("\tsin(%d) = %.4f\n", angle, radianToDegree(result));
}

void computeCos(int angle)
{
	printf("\tCompute cosine\n");
}

void computeTan(int angle)
{
	if(angle == 90 || angle == 270)
	{
		printf("\ttan(%d) is UNDEFINED\n", angle);
	}
	else
	{
		printf("\tCompute tangent\n");
	}
}

void computeValues(double (*computeFunction)(double))
{
	for(int i = 0; i <= LOOP_LIMIT; i+=15)
	{
		(*computeFunction)(i);
	}
}

double degreeToRadian(double angle)
{
	return (PI * angle)/180.0;
}

double radianToDegree(double angle)
{
	return (angle * 180.0)/PI;
}
