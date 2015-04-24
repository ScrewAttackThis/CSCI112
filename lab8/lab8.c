/*
 * Michael Shihrer
 * Lab 8, CSCI 112
 * 24 Apr 15
 */

 //includes
 #include <stdio.h>

 //Constants
 #define NAME_SIZE = 25;

 //Prototypes

 //Student struct
 typedef struct Students
 {
   int sid;
   char lastName[NAME_SIZE];
   char firstName[NAME_SIZE];
   float *grades;
   float gpa;
 } student;

 //Main function - collects user input and starts program
 int main(void)
 {
   int numberOfStudents = 0;
   int numberOfGrades = 0;

   printf("\nEnter the number of students:> ");
   scanf("%d", &numberOfStudents);
   printf("\nEnter the number of grades to track:> ");
   scanf("%d", &numberOfGrades);

   printf("\n\nThere are %d students.\n", numberOfStudents);
   printf("\n\nThere are %d grades.\n", numberOfGrades);

   //Exit with code 0
   return 0;
 }
