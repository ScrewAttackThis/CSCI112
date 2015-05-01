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
 void doFileStuff(FILE *fin1p, FILE *fin2p, FILE *foutp);

 //Main function
 int main(int argc, char *argv[])
 {
   FILE *fin1p;   //elements_file1.csv
   FILE *fin2p;   //elements_file2.csv
   FILE *foutp;   //elements.csv

   fin1p = fopen("elements_file1.csv","r");
   fin2p = fopen("elements_file2.csv","r");
   foutp = fopen("elements.csv","w");

   //Error checking
   if(fin1p == NULL)
   {
     printf("Error loading elements_file1.csv");
     exit(1);
   }else if(fin2p == NULL)
   {
     printf("Error loading elements_file2.csv");
     exit(1);
   }else if(fin2p == NULL)
   {
     printf("Error loading elements.csv");
     exit(1);
   }

   doFileStuff(fin1p,fin2p,foutp);

   //Close files
   fclose(fin1p);
   fclose(fin2p);
   fclose(foutp);

   //Loop through arguments
   for(int i = 1; i < 0; i++)
   {

   }
 }

 void doFileStuff(FILE *fin1p, FILE *fin2p, FILE *foutp)
 {
   char curLineF1[LINE_SIZE];
   char curLineF2[LINE_SIZE];

   char curLineF1Copy[LINE_SIZE];
   char curLineF2Copy[LINE_SIZE];

   fgets(curLineF1, LINE_SIZE, fin1p);
   fgets(curLineF2, LINE_SIZE, fin2p);

   strcpy(curLineF1Copy, curLineF1);
   strcpy(curLineF2Copy, curLineF2);

   while(1)
   {

     if(feof(fin1p) || feof(fin2p))
     {
       break;
     }

     int atomic1 = atoi(strtok(curLineF1, delim));
     int atomic2 = atoi(strtok(curLineF2, delim));

     if(atomic1 < atomic2)
     {
       fprintf(foutp, curLineF1Copy);
       curLineF1[0] = '\0';
       fgets(curLineF1, LINE_SIZE, fin1p);
       strcpy(curLineF1Copy, curLineF1);
     }
     else
     {
       fprintf(foutp, curLineF2Copy);
       curLineF2[0] = '\0';
       fgets(curLineF2, LINE_SIZE, fin2p);
       strcpy(curLineF2Copy, curLineF2);
     }

     if(feof(fin1p) || feof(fin2p))
     {
       break;
     }
   }

   //Determine which file ended, print rest of other file
   if(feof(fin1p))
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
   else
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

   printf("File merging complete.\n");
 }
