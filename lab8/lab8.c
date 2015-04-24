/*
 * Michael Shihrer
 * Lab 8, CSCI 112
 * 24 Apr 15
 */

 //includes
 #include <stdlib.h>
 #include <stdio.h>

 //Constants
 #define NAME_SIZE    25

 //Prototypes
 void inputStudent(int);
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

   printf("Enter the number of students:> ");
   scanf("%d", &numberOfStudents);
   printf("Enter the number of grades to track:> ");
   scanf("%d", &numberOfGrades);

   printf("\nThere are %d students.\n", numberOfStudents);
   printf("\nThere are %d grades.\n", numberOfGrades);

   student *studentsArray = (student *) malloc(numberOfStudents * sizeof(student));

   //Exit with code 0
   return 0;
 }

 void inputStudent(int numberOfGrades)
 {
   student newStudent;
   printf("Enter information for student:\n");
   printf("Enter SID:> ");
   printf("Enter last name:> ");
   printf("Enter first name:> ");
   prinf("Enter grades (seperated by space):> ");
 }
