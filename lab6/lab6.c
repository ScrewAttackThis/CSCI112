/*
 * Michael Shihrer
 * Lab 6, CSCI 112
 * 27 Mar 15
 */

#include <stdio.h>
#include <math.h>

void printCode(int [12]);
void checkBarcode(int [12]);
int stepOne(int [12]);
int stepTwo(int [12]);
int stepThree(int, int);
int stepFour(int);
void stepFive(int, int);


int main(void)
{
  //Input variable
  int validInput;

  //Barcode aray
  int barcode[12];
  //{0,7,9,4,0,0,8,0,4,5,0,1} valid
  //{0,1,1,1,1,0,8,5,6,8,0,7} valid
  //{0,5,1,0,0,0,1,3,8,1,0,1} valid
  //{0,2,4,0,0,0,1,6,2,8,6,0} invalid

  // Print welcome message
  printf("\nEnter a bar code to check.  Seperate digits with a space > \n");

  for(int i = 0; i < 12; i++)
  {
    scanf("%d", &barcode[i]);
  }

  checkBarcode(barcode);

  return 0;
}
void checkBarcode(int barcode[12])
{
  printCode(barcode);
  int oddSum = stepOne(barcode);
  int evenSum = stepTwo(barcode);
  int totalSum = stepThree(oddSum, evenSum);
  int checkDigit = stepFour(totalSum);
  stepFive(checkDigit, barcode[11]);
}

void printCode(int barcode[12])
{
  printf("\n\nYou entered the code: ");
  for(int i = 0; i < 12; i++)
  {
    printf("%d ",barcode[12]);
  }

  printf("\n");
}

int stepOne(int barcode[12])
{
  int sum = 0;
  for(int i=0; i < 12; i+=2)
  {
    sum += barcode[i];
  }
  sum *= 3;

  printf("STEP 1: Sum of odds times 3 is %d\n",sum);

  return sum;
}

int stepTwo(int barcode[12])
{
  int sum = 0;
  for(int i=1; i < 11; i+=2)
  {
    sum += barcode[i];
  }

  printf("STEP 2: Sum of even digits is %d\n",sum);

  return sum;
}

int stepThree(int oddSum, int evenSum)
{
  int totalSum = oddSum + evenSum;
  printf("STEP 3: Total sum is %d\n",totalSum);
  return totalSum;
}

int stepFour(int totalSum)
{
  int lastDigit = totalSum % 10;

  int checkDigit;
  if(lastDigit == 0)
  {
    checkDigit = lastDigit;
  }
  else
  {
    checkDigit = 10 - lastDigit;
  }

  printf("STEP 4: Calculated check digit is %d\n",checkDigit);
  return checkDigit;
}

void stepFive(int checkDigit, int lastDigit)
{
  if(checkDigit == lastDigit)
  {
    //valid
    printf("STEP 5: Check digit and last digit match\nBarcode is VALID.\n");
  }
  else
  {
    //invalid
    printf("STEP 5: Check digit and last digit do not match\nBarcode is INVALID.\n");
  }
}
