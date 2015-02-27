#include <stdio.h>

/*
* Michael Shihrer
* Lab 3, CSCI 112
* 27 Feb 15
*/

//Function prototypes
int get_input();
int is_valid(int input);
void print_pattern(int input);

int main(void)
{
	//Prints the pattern from valid input
	print_pattern(get_input());
}

int get_input()
{
	//Initial input variable
	int input = 0;
	
	//User input loop
	do
	{
		printf("Enter an odd number between 1 and 9 > ");
		//Scans for an integer input
		scanf("%d", &input);
	}while(!is_valid(input));
	
	//Return the validated input
	return input;
}

//Validates input against 3 cases.  Returns 0 for false, 1 for true.
int is_valid(int input)
{
	//Case for even numbers
	if((input % 2) == 0) 
	{
		printf("You have entered an even number.  Please try again.\n");
		return 0;
	}
	//Case for numbers larger than 9
	else if(input > 9)
	{
		printf("You have entered a number greater than 9.  Please try again.\n");
		return 0;
	}
	//Case for numbers smaller than 1
	else if(input < 1)
	{
		printf("You have entered a number less than 1.  Please try again.\n");
		return 0;
	}

	return 1;
}

//Prints out pattern
void print_pattern(int input)
{
	//Top half of pattern
	//First loop handles rows
	for(int row = 1; row <= input; row+=2)
	{
		//Prints out space padding
		printf("%*s", input - row,"");
		//Second loop handles columns
		for(int col = 1; col <= row; col++)
		{
			//Prints the column we're on
			printf("%d",col);
			//Enters a single space after the digit unless we're on the last column
			if(col!=row)
			{
				printf("%*s", 1,"");
			}
		}
		
		//Enters a newline to keep things lined up
		printf("\n");
	}
	
	//Bottom half of pattern
	//First loop handles rows
	for(int row = input - 2; row >= 1; row-=2)
	{
		//Prints out space padding
		printf("%*s",input-row,"");
		//Second loop handles columns
		for(int col = 1; col <= row; col++)
		{
			//Print out the column we're currently on
			printf("%d",col);
			//Add a single space between digits unless we're on the last column
			if(col != row)
			{
				printf("%*s",1,"");
			}
		}
		
		//Enter newline to keep things lined up
		printf("\n");
	}
}
