/*
 * Michael Shihrer
 * Lab 6, CSCI 112
 * 27 Mar 15
 */

#include <stdio.h>
#include <math.h>

void printCode(int [12]);
void checkBarcode(int [12]);
int getTotalSum(int [12]);
int getCheckDigit(int);
void validateBarcode(int, int);


int main(void)
{
  //Barcode array stores user input
  int barcode[12];

  // Print welcome message
  printf("\nEnter a bar code to check.  Seperate digits with a space > \n");

  //Get user input and store it into barcode array
  for(int i = 0; i < 12; i++)
  {
    scanf("%d", &barcode[i]);
  }

  //Begin barcode check
  checkBarcode(barcode);

  //Exit with code 0
  return 0;
}
void checkBarcode(int barcode[12])
{
  //Print entered barcode
  printCode(barcode);

  //Start step three and save result in totalsum variable
  int totalSum = getTotalSum(barcode);

  //Start step four and save resultin checkDigit variable
  int checkDigit = getCheckDigit(totalSum);

  //Start step five
  validateBarcode(checkDigit, barcode[11]);
}

//Prints barcode by looping through each element of the array
void printCode(int barcode[12])
{
  printf("\nYou entered the code: ");

  //Loop through array
  for(int i = 0; i < 12; i++)
  {
    //Print current element
    printf("%d ",barcode[i]);
  }

  //Prints final new line
  printf("\n");
}

int getTotalSum(int barcode[12])
{
  int oddSum = 0;   //Stores odd sum
  int evenSum = 0;  //Stores even sum

  for(int i = 0; i < 11; i++) //Loop through elements of barcode array except for last digit
  {
    if(i % 2 == 0) //Odd digits
    {
      oddSum += barcode[i]; //Add current element to sum of odd digits
    }
    else //Even digits
    {
      evenSum += barcode[i]; //Add current element to sum of even digits
    }
  }

  //Multiply the odd sum by 3 according to algorithm
  oddSum *= 3;

  //Add oddsum and even sum for the total sum
  int totalSum = oddSum + evenSum;

  //Print results for steps
  //Print results of step 1
  printf("STEP 1: Sum of odds times 3 is %d\n",oddSum);
  //Print results of step 2
  printf("STEP 2: Sum of even digits is %d\n",evenSum);
  //Print results of step 3
  printf("STEP 3: Total sum is %d\n",totalSum);

  return totalSum;  //Return the total sum
}

//Determines the check digit
int getCheckDigit(int totalSum)
{
  int lastDigit = totalSum % 10; //Gets last digit of total sum

  int checkDigit;
  if(lastDigit == 0) //If last digit is 0, that's the check digit
  {
    checkDigit = lastDigit;
  }
  else //Otherwise, the check digit is 10 minus the last digit
  {
    checkDigit = 10 - lastDigit;
  }

  //Print results of step 4
  printf("STEP 4: Calculated check digit is %d\n",checkDigit);

  return checkDigit; //Return the check digit
}

//Compares the check digit to the last digit of the bar code
void validateBarcode(int checkDigit, int lastDigit)
{
  if(checkDigit == lastDigit) //Barcode is valid
  {
    //Print that the results are valid
    printf("STEP 5: Check digit and last digit match\nBarcode is VALID.\n");
  }
  else //Barcode is invalid
  {
    //Print that the results are invalid
    printf("STEP 5: Check digit and last digit do not match\nBarcode is INVALID.\n");
  }
}
