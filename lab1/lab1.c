#include <stdio.h>
/*
 * Michael Shihrer
 * Lab 1, CSCI 112
 * 28 Jan 15
 */


int main(void)
{
	double fahrenheit;  //Store entered value
	double celsius;  //Store result

	//Ask for fahrenheit input
	printf("Enter a temperature in degrees Fahrenheit > ");
	scanf("%lf", &fahrenheit);

	//Convert fahrenheit to celsius equation
	celsius = (fahrenheit - 32) * 5.0/9.0;

	//Print result to standard output
	printf("%f degrees Fahrenheit is equal to %f degrees Celsius. \n", fahrenheit, celsius);

	//Ask for celsius input
	printf("Enter a temperature in degrees Celsius > ");
	scanf("%lf", &celsius);

	//Convert celsius to fahrenheit
	fahrenheit = celsius * 9.0/5.0 + 32;

	//Print results to standard output
	printf("%f degrees Celsius is equal to %f degrees Fahrenheit. \n", celsius, fahrenheit);
	return 0;
}
