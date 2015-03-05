include <stdio.h>
include <math.h>

typedef enum {
	sine,
	cosine,
	tangent,
	quit
} MENU;
 
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
	MENU input;
	//Menu enum
	do
	{
		print("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\n");
		print("Enter your choice > ");

		scanf("%d",&input);
	}while(!is_valid(input));
}

bool is_valid(MENU input)
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
