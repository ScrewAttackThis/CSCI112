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

 //Student struct
 typedef struct
 {
   int sid;
   char lastName[NAME_SIZE];
   char firstName[NAME_SIZE];
   float *grades;
   float gpa;
 } student;

 //Prototypes
 student inputStudent(int);
 float calcGPA(student, int);

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
   printf("There are %d grades.\n", numberOfGrades);

   student *studentsArray = (student *) malloc(numberOfStudents * sizeof(student));

   for(int i = 0; i < numberOfStudents; i++)
   {
     *(studentsArray + i) = inputStudent(numberOfGrades);
   }
   //Exit with code 0
   return 0;
 }

 student inputStudent(int numberOfGrades)
 {
   student newStudent;

   printf("Enter information for student:\n");
   printf("Enter SID:> ");
   scanf("%d", &newStudent.sid);
   printf("Student id entered: %d", newStudent.sid);
   printf("Enter last name:> ");
   scanf("%s", &newStudent.lastName);
   printf("Enter first name:> ");
   scanf("%s", &newStudent.firstName);
   printf("Enter grades (seperated by space):> ");

   newStudent.grades = (float *) malloc(numberOfGrades * sizeof(float));

   for(int i = 0; i < numberOfGrades; i++)
   {
     scanf("%d", &(newStudent.grades[i]));
   }

   newStudent.gpa = calcGPA(&newStudent, numberOfGrades);
   printf("%.2f",newStudent.gpa);
   /*printf("Grades entered: ");
   for(int i = 0; i < numberOfGrades; i++)
   {
     printf("%d ", *newStudent.grades[i]);
   }*/

   return newStudent;
 }

 float calcGPA(student *studentRecord, int numberOfGrades)
 {
   float sum = 0.0;

   for(int i = 0; i < numberOfGrades; i++)
   {
     sum += studentRecord->grades[i];
   }
   return sum/numberOfGrades;
 }
