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
   if(feof(fin1p))  //File 1 ended
   {
     strcpy(curLineF2,curLineF2Copy);

     while(1) //Loop through file 2
     {
       if(feof(fin2p))  //Make sure file 2 hasn't ended
       {
         break; //Ends loops
       }

       fprintf(foutp, curLineF2); //Merge it to file 3
       fgets(curLineF2, LINE_SIZE, fin2p);  //Get curline from file 2
     }
   }
   else //File 2 ended
   {
     strcpy(curLineF1,curLineF1Copy);
     
     while(1) //Loop through file 1
     {
       if(feof(fin1p))  //Make sure file 1 hasn't ended
       {
         break; //Ends loop
       }

       fprintf(foutp, curLineF1); //Merge it to file 3
       fgets(curLineF1, LINE_SIZE, fin1p);  //Get curline from file 1
     }
   }

   printf("File merging complete.\n");
 }

 //Function finds passed element symbol in elements.csv
 void findElement(char *symArg)
 {
   FILE *elFile;  //Element file pointer
   elFile = fopen("elements.csv","r");  //Open elements.csv for reading

   //Error checking
   //Closes program if elements.csv couldn't be opened
   if(elFile == NULL)
   {
     printf("Error loading elements.csv");
     exit(1);
   }

   //Variables to store current line from file and a copy
   char curLine[LINE_SIZE];
   char curLineCopy[LINE_SIZE];

   //Loop through elements.csv until end of file
   while(1)
   {
     //Check for end of file, exit loop if it's found
     if(feof(elFile))
     {
       break;
     }

     //Get current line and then copy it
     fgets(curLine, LINE_SIZE, elFile);
     strcpy(curLineCopy, curLine);

     //Skips empty line
     if(curLine[0] == '\0')
     {
       continue;
     }

     //Split copy of current line based on delimiter
     char *atomic_number = strtok(curLineCopy, delim);  //set the atomic number
     char *atomic_weight = strtok(NULL, delim);         //set the atomic weight
     char *name = strtok(NULL, delim);                  //set the element name
     char *symbol = strtok(NULL, delim);                //set the element symbol
     char *year = strtok(NULL, delim);                  //set the element's discovered year
     char *category = strtok(NULL, delim);              //set the element's category

     curLine[0] = '\0';   //Reset curline

     //Check to see if curline contains element being searched for
     if(strcmp(symArg, symbol) == 0)
     {
       //Element found
       printf("\nElement: %s\n", name);                 //Print name
       printf("\tSymbol: %s\n", symbol);                //Print symbol
       printf("\tAtomic Number: %s\n", atomic_number);  //Print atomic number
       printf("\tAtomic Weight: %s\n", atomic_weight);  //Print atomic weight
       if(strcmp(year, "ancient") != 0)                 //Print discovered year if it's not ancient
       {
         printf("\tDiscovered in: %s\n", year);
       }

       //Element found, no need to keep searching
       break;
     }
   }

   //Cleanup file use
   fclose(elFile);
 }
