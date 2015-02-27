#include <stdio.h>

/*
* Michael SHihrer
* Lab 2, CSCI 112
* 12 Feb 15
*/

double get_input(void)
{
	double input = 0.0;		//Stores input
	printf("Enter a value > ");	//Prompt user for input
	scanf("%lf", &input);		//Accept input from user

	return input;			//Returns user input
}

double get_next(double x1, double x2)
{
	double x = 0.0;			//Stores the next computed value

	x = (x1)/2.0 + 3.0*x2;		//Equation for determining next value

	return x;
}

void print_result(double output)
{
	printf("The result is  %3.2lf \n", output);	//Outputs result in specified format
}

int main(void)
{
	double x1 = 0.0;		//Stores x(n-1) value
	double x2 = 0.0;		//Stores x(n-2) value
	double x3 = 0.0;		//Stores x(n) value

	x1 = get_input();		//Assign x(n-1) value
	x2 = get_input();		//Assign x(n-2) value

	int i = 3;
	for(i;i<6;i++)			//Loop through enough times to calculate the 5th number
	{
		x3 = get_next(x1,x2);	//Get x3 value
		x1 = x2;		//Swap values so we can calculate the next in the series
		x2 = x3;
	}

	print_result(x3);		//Print result
	return 0;
}
