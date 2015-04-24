/*
 * Michael Shihrer
 * Lab 8, CSCI 112
 * 24 Apr 15
 */

 //includes
 #include <stdlib.h>
 #include <stdio.h>

 //Constants
 #define NAME_SIZE    25      //Max size of firstName and lastName

 //Student struct
 typedef struct
 {
   int sid;                   //Student ID
   char lastName[NAME_SIZE];  //Last Name
   char firstName[NAME_SIZE]; //First Name
   float *grades;             //Grades pointer
   float gpa;                 //Calculated GPA
 } student;

 //Prototypes
 student inputStudent(int);   //Function to input student info
 float calcGPA(student, int); //Function to calculate GPA
 void printStudents();        //Function to print out entered student info

 //Main function - collects user input and starts program
 int main(void)
 {
   int numberOfStudents = 0;    //Stores the total number of students entered
   int numberOfGrades = 0;      //Stores the total number of grades entered

   printf("Enter the number of students:> ");         //Print menu to ask for number of students
   scanf("%d", &numberOfStudents);                    //Store total number of students into numberOfStudents variable
   printf("Enter the number of grades to track:> ");  //Print to ask for number of grades
   scanf("%d", &numberOfGrades);                      //Store total number of grades into numberOfGrades variable

   printf("\nThere are %d students.\n", numberOfStudents);  //Prints confirmation of number of students entered
   printf("There are %d grades.\n\n", numberOfGrades);      //Prints confirmation of number of grades entered

   student *studentsArray = (student *) malloc(numberOfStudents * sizeof(student));   //Allocate appropriate memory from heap for the students array

   for(int i = 0; i < numberOfStudents; i++)              //Loop through with numberOfStudents as a bound
   {
     *(studentsArray + i) = inputStudent(numberOfGrades); //Calls the inputStudent function
   }

   printStudents(studentsArray, numberOfStudents, numberOfGrades);  //Calls the printStudents function

   //Exit with code 0
   return 0;
 }

 //Asks user for input of student information
 student inputStudent(int numberOfGrades)
 {
   student newStudent;  //Holds new student info, returned at end of function

   printf("Enter information for student:\n");
   printf("\tEnter SID:> ");                           //Ask for student id
   scanf("%d", &newStudent.sid);                       //Get student id from input
   printf("\tEnter last name:> ");                     //Ask for last name
   scanf("%s", &newStudent.lastName);                  //Get last name from input
   printf("\tEnter first name:> ");                    //Ask for first name
   scanf("%s", &newStudent.firstName);                 //Get first name from input
   printf("\tEnter grades (seperated by space):> ");   //Ask for grades

   newStudent.grades = (float *) malloc(numberOfGrades * sizeof(float));  //Allocate appropriate amount of memory from heap for grades array

   for(int i = 0; i < numberOfGrades; i++)    //Loops for numberOfGrades times
   {
     scanf("%f", &(newStudent.grades[i]));    //Store inputed grade information
   }

   printf("\n");  //Necessary for formating

   newStudent.gpa = calcGPA(newStudent, numberOfGrades);  //Calculate GPA based on entered information

   //Returned newStudent with all entered information
   return newStudent;
 }

 //Calculates GPA from entered information
 float calcGPA(student studentRecord, int numberOfGrades)
 {
   float sum = 0.0; //Initial sum variable

   for(int i = 0; i < numberOfGrades; i++)  //Must loop through each grade
   {
     sum += studentRecord.grades[i];        //Add value of each grade to sum variable
   }

   return sum/(float)numberOfGrades;        //Divide sum by number of grades for an average
 }

 //Prints student info in formatted manner
 void printStudents(student *students, int numberOfStudents, int numberOfGrades)
 {
   for(int si = 0; si < numberOfStudents; si++)                                         //Loop through for each student
   {
     printf("Student ID #%d\n",(students + si)->sid);                                   //Print student ID
     printf("\tName:\t%s %s\n",(students + si)->firstName, (students + si)->lastName);  //Print full name
     printf("\tGrades:\t");                                                             //Print  grades

     for(int gi = 0; gi < numberOfGrades; gi++)                                         //Loop through each grade of each student
     {
       printf("%.1f ",(students + si)->grades[gi]);                                     //Prints out current grade of current student
     }
     printf("\n\tGPA:\t%.2f\n",(students + si)->gpa);                                   //Print calculated GPA
   }
 }
