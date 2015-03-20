/*
 * Michael Shihrer
 * Lab 5, CSCI 112
 * 20 Mar 15
 */

#include <stdio.h>
#include <math.h>

// List of all function declarations ( prototypes )
// Displays user menu , reads input , and validates the input
int user_menu ();
// Equation functions are pass by reference
void equation1(float *); // Calculate motion equation 1
void equation2(float *); // Calculate motion equation 2
void equation3(float *); // Calculate motion equation 3
void equation4(float *); // Calculate motion equation 4
// User input functions return a value from user
float get_position_initial(void); // Prompts user for x0
float get_position_final(void); // Prompts user for xf
float get_velocity_initial(void); // Prompts user for v0
float get_velocity_final(void); // Prompts user for vf
float get_acceleration(void); // Prompts user for a
float get_time(void); // Prompts user for t

int main(void)
{
  //Input variable
  int validInput;

  do
  {
    //Print menu and return valid input.
    validInput = user_menu();

    //Stores result and allow pass pointer by reference.
    float result;

    //Handle menu choices
    switch(validInput)
    {
      case 1:
        equation1(&result);
        break;
      case	2:
        break;
      case 3:
        break;
      case 5:
        //exit program
        printf("Thank you for using the MOTION EQUATION CALCULATOR . Goodbye .\n");
        return 0;
      break;
    }

    //Print out formatted result
    printf("Your result is %.4f.\n\n", result);
  }while(validInput != 5);

  return 0;
}

int user_menu()
{
	//input variable
	int input;

  do //Keep asking for option until valid input is entered
  {

    //print menu
  	printf("\nChoose a motion equation 1-4 or choose 5 to QUIT > ");
    //Scan user input
  	scanf("%d",&input);

    //Validate that input is 1-5 inclusive
    if(input < 1 || input > 5)
    {
      printf("Invalid option. Please try again.\n");
    }
  }while(input < 1 || input > 5);

  return input;
}

void equation1(float *result)
{
  float v0 = get_velocity_initial(); //Get initial velocity
  float a = get_acceleration(); //Get acceleration
  float t = get_time(); //Get time

  * result = v0 + (a*t);
}

// Prompts user for x0
float get_position_initial()
{
  return 0.0;
}

// Prompts user for xf
float get_position_final()
{
  return 0.0;
}

// Prompts user for v0
float get_velocity_initial()
{
  float v0;
  printf("\tEnter initial velocity > ");

  scanf("%f", &v0);
  return v0;
}

// Prompts user for vf
float get_velocity_final()
{
  return 0.0;
}

// Prompts user for a
float get_acceleration ()
{
  float a;
  printf("\tEnter acceleration > ");
  scanf("%f", &a);
  return a;
}

// Prompts user for t
float get_time ()
{
  float t;
  printf("\tEnter time > ");
  scanf("%f", &t);
  return t;
}
