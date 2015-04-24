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
 void printStudents();

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
   printf("There are %d grades.\n\n", numberOfGrades);

   student *studentsArray = (student *) malloc(numberOfStudents * sizeof(student));

   for(int i = 0; i < numberOfStudents; i++)
   {
     *(studentsArray + i) = inputStudent(numberOfGrades);
   }

   printStudents(studentsArray, numberOfStudents, numberOfGrades);

   //Exit with code 0
   return 0;
 }

 student inputStudent(int numberOfGrades)
 {
   student newStudent;

   printf("Enter information for student:\n");
   printf("\tEnter SID:> ");
   scanf("%d", &newStudent.sid);
   printf("\tEnter last name:> ");
   scanf("%s", &newStudent.lastName);
   printf("\tEnter first name:> ");
   scanf("%s", &newStudent.firstName);
   printf("\tEnter grades (seperated by space):> ");

   newStudent.grades = (float *) malloc(numberOfGrades * sizeof(float));

   for(int i = 0; i < numberOfGrades; i++)
   {
     //BROKEN AS SHIT
     scanf("%f", &(newStudent.grades[i]));
   }
   printf("\n\n");
   newStudent.gpa = calcGPA(newStudent, numberOfGrades);

   return newStudent;
 }

 float calcGPA(student studentRecord, int numberOfGrades)
 {
   float sum = 0.0;

   for(int i = 0; i < numberOfGrades; i++)
   {
     sum += studentRecord.grades[i];
   }

   return sum/(float)numberOfGrades;
 }

 void printStudents(student *students, int numberOfStudents, int numberOfGrades)
 {
   for(int si = 0; si < numberOfStudents; si++)
   {
     printf("Student ID #%d\n",(students + si)->sid);
     printf("\tName:\t%s %s\n",(students + si)->firstName, (students + si)->lastName);
     printf("\tGrades:\t");
     for(int gi = 0; gi < numberOfGrades; gi++)
     {
       printf("%.1f ",(students + si)->grades[gi]);
     }
     printf("\n\tGPA:\t%.2f\n",(students + si)->gpa);
   }
 }
