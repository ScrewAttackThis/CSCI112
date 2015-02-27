#include <stdio.h>

/*
* Michael Shihrer
* Lab 3, CSCI 112
* 27 Feb 15
*/

int get_input();
int is_valid(int input);
void print_pattern(int input);

int main(void)
{
	print_pattern(get_input());
}

int get_input()
{
	int input = 0;
	do
	{
		printf("Enter an odd number between 1 and 9 > ");
		scanf("%d", &input);
	}while(!is_valid(input));

	return input;
}

int is_valid(int input)
{
	if((input % 2) == 0) 
	{
		printf("You have entered an even number.  Please try again.\n");
		return 0;
	}
	else if(input > 9)
	{
		printf("You have entered a number greater than 9.  Please try again.\n");
		return 0;
	}
	else if(input < 1)
	{
		printf("You have entered a number less than 1.  Please try again.\n");
		return 0;
	}

	return 1;
}

void print_pattern(int input)
{
	for(int row = 1; row <= input; row+=2)
	{
		printf("%*s", input - row,"");

		for(int col = 1; col <= row; col++)
		{
			printf("%d",col);
			printf("%*s", 1,"");
		}
		
		printf("\n");
	}
	
	for(int row = input - 2; row >= 1; row-=2)
	{
		printf("%*s",input-row,"");
		
		for(int col = 1; col <= row; col++)
		{
			printf("%d",col);
			printf("%*s",1,"");
		}

		printf("\n");
	}
}
