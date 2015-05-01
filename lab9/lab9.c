/*
 * Michael Shihrer
 * Lab 9, CSCI 112
 * 1 May 15
 */

 //includes
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>

 //constants
 #define LINE_SIZE    100

 //globals
 const char delim[2] = ",";

 //prototypes
 void fileMerge(FILE *fin1p, FILE *fin2p, FILE *foutp);
 void findElement();

 //Main function
 int main(int argc, char *argv[])
 {
   FILE *fin1p;   //File pointer for elements_file1.csv
   FILE *fin2p;   //File pointer for elements_file2.csv
   FILE *foutp;   //File pointer for elements.csv

   fin1p = fopen("elements_file1.csv","r");   //Opens elements_file1.csv
   fin2p = fopen("elements_file2.csv","r");   //Opens elements_file2.csv
   foutp = fopen("elements.csv","w");         //Opens elements.csv

   //Error checking
   if(fin1p == NULL)        //Check if elements_file1.csv opened
   {
     printf("Error loading elements_file1.csv");
     exit(1); //Exit program
   }else if(fin2p == NULL)  //Check if elements_file2.csv opened
   {
     printf("Error loading elements_file2.csv");
     exit(1); //Exit program
   }else if(fin2p == NULL)  //Check if elements.csv opened
   {
     printf("Error loading elements.csv");
     exit(1); //Exit program
   }

   fileMerge(fin1p,fin2p,foutp);  //Calls function to merge files

   //Close files
   fclose(fin1p);
   fclose(fin2p);
   fclose(foutp);

   //Loop through arguments
   for(int i = 1; i < argc; i++)
   {
     findElement(argv[i]);  //Search for elements passed as command line arguments
   }
 }

 //Function to merge two files into one, keeps them sorted
 void fileMerge(FILE *fin1p, FILE *fin2p, FILE *foutp)
 {
   char curLineF1[LINE_SIZE]; //Stores current line from first file
   char curLineF2[LINE_SIZE]; //Stores current line from second file

   char curLineF1Copy[LINE_SIZE]; //Stores copy of curLine from first file
   char curLineF2Copy[LINE_SIZE]; //Stores copy of  curLine from second file

   fgets(curLineF1, LINE_SIZE, fin1p);  //Get a line from first file
   fgets(curLineF2, LINE_SIZE, fin2p);  //Get a line from second file

   strcpy(curLineF1Copy, curLineF1);  //Copy line from first file
   strcpy(curLineF2Copy, curLineF2);  //Copy line from second file

   //Loop until end of file is reached
   while(1)
   {
     //Checks if end of file has been reached in either first or second file
     if(feof(fin1p) || feof(fin2p))
     {
       break;
     }

     int atomic1 = atoi(strtok(curLineF1, delim));  //Get atomic number from first file
     int atomic2 = atoi(strtok(curLineF2, delim));  //Get attomic number from second file

     //Compare atomic numbers
     if(atomic1 < atomic2)    //If first atomic number is smaller, print it to output file
     {
       fprintf(foutp, curLineF1Copy);       //Print curLine from file 1
       curLineF1[0] = '\0';                 //Reset curLine
       fgets(curLineF1, LINE_SIZE, fin1p);  //Get next line from file 1
       strcpy(curLineF1Copy, curLineF1);    //Copy new curLine from file 1
     }
     else //Second atomic number is smaller, print it
     {
       fprintf(foutp, curLineF2Copy);       //Print curLine from file 2
       curLineF2[0] = '\0';                 //Reset curLine
       fgets(curLineF2, LINE_SIZE, fin2p);  //Get next line from file 2
       strcpy(curLineF2Copy, curLineF2);    //Copy new curLine from file 2
     }
   }

   //Determine which file ended, print rest of other file
   if(feof(fin1p))
   {
     while(1)
     {
       if(feof(fin2p))
       {
         break;
       }

       fgets(curLineF2, LINE_SIZE, fin2p);
       fprintf(foutp, curLineF2);
     }
   }
   else
   {
     while(1)
     {
       if(feof(fin1p))
       {
         break;
       }

       fgets(curLineF1, LINE_SIZE, fin1p);
       fprintf(foutp, curLineF1);
     }
   }

   printf("File merging complete.\n");
 }

 void findElement(char *symArg)
 {
   FILE *elFile;
   elFile = fopen("elements.csv","r");

   //Error checking
   if(elFile == NULL)
   {
     printf("Error loading elements.csv");
     exit(1);
   }

   char curLine[LINE_SIZE];
   char curLineCopy[LINE_SIZE];

   while(1)
   {
     if(feof(elFile))
     {
       break;
     }

     fgets(curLine, LINE_SIZE, elFile);
     strcpy(curLineCopy, curLine);

     if(curLine[0] == '\0')
     {
       continue;
     }

     curLine[0] = '\0';

     char *atomic_number = strtok(curLineCopy, delim);
     char *atomic_weight = strtok(NULL, delim);
     char *name = strtok(NULL, delim);
     char *symbol = strtok(NULL, delim);
     char *year = strtok(NULL, delim);
     char *category = strtok(NULL, delim);

     if(strcmp(symArg, symbol) == 0)
     {
       printf("\nElement: %s\n", name);
       printf("\tSymbol: %s\n", symbol);
       printf("\tAtomic Number: %s\n", atomic_number);
       printf("\tAtomic Weight: %s\n", atomic_weight);
       if(!strcmp(year,"ancient"))
       {
         printf("\tDiscovered in: %s\n", year);
       }

       break;
     }
   }

   fclose(elFile);
 }
