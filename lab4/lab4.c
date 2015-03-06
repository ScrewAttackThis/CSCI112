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
double computeSin(double angle);
double computeCos(double angle);
double computeTan(double angle);
void computeValues();
double degreeToRadian(double angle);

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
			case QUIT:
				break;
			default:
				printf("%d is an invalid option.  Please try again.\n", input);
				break;
		}
	}while(!(input == QUIT));
}

double computeSin(double angle)
{
	printf("Compute sine");
	return 0.0;
}

double computeCos(double angle)
{
	printf("Compute cosine");
	return 0.0;
}

double computeTan(double angle)
{
	if(angle == 90 || angle == 270)
	{
		printf("UNDEFINED");
	}
	else
	{
		printf("Compute tangent");
	}
	return 0.0;
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
	return PI * angle/180;
}
