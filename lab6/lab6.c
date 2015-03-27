/*
 * Michael Shihrer
 * Lab 6, CSCI 112
 * 27 Mar 15
 */

#include <stdio.h>
#include <math.h>

void checkBarcode(int [12]);
int sumOdd(int [12]);
int sumEven(int [12]);

int main(void)
{
  //Input variable
  int validInput;

  //Barcode aray
  int barcode[12] = {0,1,1,1,1,0,8,5,6,8,0,7};
  //{0,7,9,4,0,0,8,0,4,5,0,1}
  //0 1 1 1 1 0 8 5 6 8 0 7
  //0 5 1 0 0 0 1 3 8 1 0 1
  //0 2 4 0 0 0 1 6 2 8 6 0

  // Print welcome message
  printf("\nEnter a bar code to check.  Seperate digits with a space > \n");

  checkBarcode(barcode);

  return 0;
}

void checkBarcode(int barcode[12])
{
  //Loop through twice, once for odd and once for even
  int oddSum = sumOdd(barcode);
  int evenSum = sumEven(barcode);

  int totalSum = oddSum * 3 + evenSum;

  printf("total sum > %d \n",totalSum);

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

  printf("check digit > %d \n",checkDigit);
  printf("last digit > %d \n",barcode[11]);
  if(checkDigit == barcode[11])
  {
    //valid
    printf("valid\n");
  }
  else
  {
    //invalid
    printf("invalid\n");
  }
}

int sumOdd(int barcode[12])
{
  int sum = 0;
  for(int i=0; i < 12; i+=2)
  {
    sum += barcode[i];
  }

  printf("sum of odd digits > %d \n", sum);
  return sum;
}

int sumEven(int barcode[12])
{
  int sum = 0;
  for(int i=1; i < 11; i+=2)
  {
    sum += barcode[i];
  }

  printf("sum of even digits > %d \n", sum);

  return sum;
}
