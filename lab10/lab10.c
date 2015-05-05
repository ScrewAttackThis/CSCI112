/*
 * Michael Shihrer
 * Lab 10, CSCI 112
 * 5 May 15
 */

 //includes
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>

 //Constants
 #define STRING_MAX 100

 //Movie typedef
 typedef struct movieType Movie;

 //Movie linkedlist struct
 struct movieType {
   int movieID;
   char title[STRING_MAX];      //Contains title of movie
   int yearReleased;            //Stores year movie was released
   char director[STRING_MAX];   //Stores the name of the director
   char starActor[STRING_MAX];  //Stores the name of the star actor
   float imdbRating;            //Stores the rating from IMDB
   Movie *next;                 //Pointer to next node of list
 };

 //Function prototypes
 void UserMenu(Movie *a);
 void CreateRecords(Movie *);
 void CreateRecords(Movie *);
 Movie ScanList(Movie *, int);
 void InsertNode(Movie *, Movie *);
 void DeleteNode(Movie *, int);
 void PrintList(Movie *);

 int main()
 {
   Movie *movieRecords = (Movie *) malloc(sizeof(Movie));
   CreateRecords(movieRecords);
   UserMenu(movieRecords);
 }

 void UserMenu(Movie *movies)
 {
   int input = 0;
   do
   {
     printf("Enter 1-5 to select one of the following options:\n");
     printf("\t1. Print database\n");
     printf("\t2. Search database\n");
     printf("\t3. Insert new record\n");
     printf("\t4. Delete record\n");
     printf("\t5. Exit\n");

     switch(input)
     {
       case 1:
        PrintList(movies);
        break;
       case 2:
        break;
       case 3:
        break;
       case 4:
        break;
       case 5:
        printf("Thank you for using the movie database program!");
        break;
     }

   }while(input != 5);
 }

 //Create 5 hardcoded movie records
 void CreateRecords(Movie *head)
 {
   //Declare nodes and allocate memory
   Movie *node1 = (Movie*) malloc(sizeof(Movie));
   Movie *node2 = (Movie*) malloc(sizeof(Movie));
   Movie *node3 = (Movie*) malloc(sizeof(Movie));
   Movie *node4 = (Movie*) malloc(sizeof(Movie));
   Movie *node5 = (Movie*) malloc(sizeof(Movie));

   //Initialize nodes with information
   strcpy(node1->title,"Pulp Fiction");
   node1->yearReleased = 1994;
   strcpy(node1->director, "Quentin Tarantino");
   strcpy(node1->starActor, "Bruce Willis");
   node1->imdbRating = 8.9;

   strcpy(node2->title, "Saving Private Ryan");
   node2->yearReleased = 1998;
   strcpy(node2->director, "Steven Spielberg");
   strcpy(node2->starActor, "Tom Hanks");
   node2->imdbRating = 8.6;

   strcpy(node3->title, "The Matrix");
   node3->yearReleased = 1999;
   strcpy(node3->director, "The Wachowski Brotherss");
   strcpy(node3->starActor, "Keanu Reeves");
   node3->imdbRating = 8.7;

   strcpy(node4->title, "The Godfather");
   node4->yearReleased = 1972;
   strcpy(node4->director, "Francis Ford Copola");
   strcpy(node4->starActor, "Al Pacino");
   node4->imdbRating = 9.2;

   strcpy(node5->title, "The Shawshank Redemption");
   node5->yearReleased = 1994;
   strcpy(node5->director, "Frank Darabont");
   strcpy(node5->starActor, "Tim Robbins");
   node5->imdbRating = 9.3;

   //Insert nodes into linked list
   InsertNode(head, node1);
   InsertNode(head, node2);
   InsertNode(head, node3);
   InsertNode(head, node4);
   InsertNode(head, node5);
 }

 //Search for an element in movies database
 Movie *ScanList(Movie *head, int searchMovieID)
 {
   Movie *previousNode, *currentNode; //declare variables for previous and current nodes of list
   previousNode = head;           //Set previous to head node.
   currentNode = head->next;      //Set current to next node.

   //Search until there are no more nodes or movieID is greater than the searchID
   while((currentNode != NULL) && (currentNode->movieID < searchMovieID))
   {
     previousNode = currentNode;        //Set previous to current node
     currentNode = currentNode->next;   //Set current to the next node
   }
 }

 void InsertNode(Movie *head, Movie *newNode)
 {
   Movie *previousNode, *nextNode;  //Declare variables for previosu and next nodes of list
   previousNode = ScanList(head, newNode->movieID);
   nextNode = previous->next;

   if((nextNode == NULL) || (strcmp(nextNode->title, newNode->title) != 0))
   {
     previousNode->next = newNode;
     newNode->next = nextNode;
   }
   else
   {
     printf("Movie already exists in database.");
     free(newNode);
   }
 }

 void DeleteNode(Movie *head, int searchMovieID)
 {
   Movie *previousNode, deleteNode;

   previousNode = ScanList(head, searchMovieID);
   deleteNode = previousNode->next;

   if((deleteNode != NULL) && (deleteNode->movieID == searchMovieID)
   {
     previousNode->next = deleteNode->next;
     free(deleteNode);
   }
   else
   {
     printf("Movie not found in database.");
   }
 }

 void PrintList(Movie *head)
 {
   Movie *currentNode =  *head;

   while(currentNode != NULL)
   {
     printf("Movie: %s\n", currentNode->title);
     printf("\tDirected by: %s\n", currentNode->director);
     printf("\tReleased in: %d\n", currentNode->yearReleased);
     printf("\tStarring: %s\n", currentNode->starActor);
     printf("\tIMDB rating: %.1f", currentNode->imdbRating);

     currentNode = currentNode->next;
   }
 }
