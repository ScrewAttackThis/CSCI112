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
void computeSin();
void computeCos();
void computeTan();
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
				computeSin();
				break;
			case	COSINE:
				computeCos();
				break;
			case TANGENT:
				computeTan();
				break;
			default:
				printf("%d is an invalid option.  Please try again.\n", input);
				break;
		}
	}while(!(input == QUIT));
}

void computeSin()
{
	for(int i = 0; i <= LOOP_LIMIT; i+=15)
	{
		double result = 0.0;
		result = sin(degreeToRadian(i));
		printf("\tsin(%d) = %.4f\n", i, result);
	}
}

void computeCos(int angle)
{
	for(int i = 0; i <= LOOP_LIMIT; i+=15)
	{
		double result = 0.0;
		result = sin(degreeToRadian(i));
		printf("\tcos(%d) = %.4f\n", i, result);
	}
}

void computeTan(int angle)
{
	for(int i = 0; i <= LOOP_LIMIT; i+=15)
	{
		if(angle == 90 || angle == 270)
		{
			printf("\ttan(%d) is UNDEFINED\n", angle);
		}
		else
		{
			double result = 0.0;
			result = tan(degreeToRadian(i));
			printf("\ttan(%d) = %.4f\n", i, result);
		}
	}
}

double degreeToRadian(double angle)
{
	return PI * angle/180.0;
}
