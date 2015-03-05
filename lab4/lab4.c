#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//MENU enum definition
typedef MENU enum {
	SINE,
	COSINE,
	TANGENT,
	QUIT
} menu_t;

/*
 * Michael Shihrer
 * Lab 4, CSCI 112
 * 5 Mar 15
 */

//Function prototypes

int main(void)
{
}

void userMenu()
{
	//Menu variable
	menu_t input;
	do
	{
		print("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\n");
		print("Enter your choice > ");

		scanf("%d",&input);
	}while(!is_valid(input));
}

bool is_valid(menu_t input)
{
}

double computeSin(double angle)
{
}

double computeCos(double angle)
{
}

double computeTan(double angle)
{
}
