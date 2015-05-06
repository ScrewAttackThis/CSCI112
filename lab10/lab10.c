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
 void UserMenu();
 void Search();
 void CreateRecords();
 Movie *ScanList(int);
 Movie *SearchRecords(int);
 int InsertNode(Movie *);
 int DeleteNode(int);
 void PrintList();
 void PrintNode(Movie *);
 void DeleteRecord();
 void InsertRecord();

 //Globals (movies database)
 Movie *head;

 int main()
 {

   //Instantiate 5 hardcoded records
   CreateRecords();

   //Display menu and start program
   UserMenu();
 }

 void UserMenu(Movie *movies)
 {
   //Variable to store user input
   int input = 0;

   //Menu loop
   do
   {
     //User menu options
     printf("\nEnter 1-5 to select one of the following options:\n");
     printf("\t1. Print database\n");
     printf("\t2. Search database\n");
     printf("\t3. Insert new record\n");
     printf("\t4. Delete record\n");
     printf("\t5. Exit\n");

     //Get user input
     scanf("%d", &input);

     //Switch control on user input
     switch(input)
     {
        case 1: //Print the database records
          PrintList(movies);
          break;
        case 2: //Search for a specific movie
          Search(movies);
          break;
        case 3: //Insert a new record
          InsertRecord(movies);
          break;
        case 4: //Delete a record
          DeleteRecord(movies);
          break;
        case 5: //Exit the program
          printf("Thank you for using the movie database program!\n");
          break;
        default:  //User didn't select a valid option
          printf("Invalid option.  Please enter 1-5.\n");
     }

   }while(input != 5); //Exit the loop (and program) if user selects the option
 }

 //Search records for user entered movie
 void Search()
 {
   int searchID;  //Stores user input for search
   printf("\tEnter a movie ID to search the database:\n");
   scanf("%d", &searchID);  //Retrieve input from user for search

   Movie *result = SearchRecords(searchID);  //Conduct search and save result
   //Result has to be not null
   if(result != NULL)
   {
     //Successful search
     printf("\tSearch succesful.\n");

     //Print out the appropriate node
     PrintNode(result);
   }
   else
   {
     //Search failed to find results
     printf("\tSearch unsuccesful.  Movie not found.\n");
   }
 }

 //Create 5 hardcoded movie records
 void CreateRecords()
 {
   //Declare nodes and allocate memory
   head = (Movie*) malloc(sizeof(Movie));
   Movie *node2 = (Movie*) malloc(sizeof(Movie));
   Movie *node3 = (Movie*) malloc(sizeof(Movie));
   Movie *node4 = (Movie*) malloc(sizeof(Movie));
   Movie *node5 = (Movie*) malloc(sizeof(Movie));

   //Initialize nodes with information
   head->movieID = 0;
   strcpy(head->title,"Pulp Fiction");
   head->yearReleased = 1994;
   strcpy(head->director, "Quentin Tarantino");
   strcpy(head->starActor, "Bruce Willis");
   head->imdbRating = 8.9;

   node2->movieID = 1;
   strcpy(node2->title, "Saving Private Ryan");
   node2->yearReleased = 1998;
   strcpy(node2->director, "Steven Spielberg");
   strcpy(node2->starActor, "Tom Hanks");
   node2->imdbRating = 8.6;

   node3->movieID = 2;
   strcpy(node3->title, "The Matrix");
   node3->yearReleased = 1999;
   strcpy(node3->director, "The Wachowski Brotherss");
   strcpy(node3->starActor, "Keanu Reeves");
   node3->imdbRating = 8.7;

   node4->movieID = 3;
   strcpy(node4->title, "The Godfather");
   node4->yearReleased = 1972;
   strcpy(node4->director, "Francis Ford Copola");
   strcpy(node4->starActor, "Al Pacino");
   node4->imdbRating = 9.2;

   node5->movieID = 4;
   strcpy(node5->title, "The Shawshank Redemption");
   node5->yearReleased = 1994;
   strcpy(node5->director, "Frank Darabont");
   strcpy(node5->starActor, "Tim Robbins");
   node5->imdbRating = 9.3;

   //Insert nodes into linked list
   InsertNode(node2);
   InsertNode(node3);
   InsertNode(node4);
   InsertNode(node5);
 }

 //Search for an element in movies database, returns previous element (never null)
 //Needed for link list operations such as insert and delete
 Movie *ScanList(int searchMovieID)
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

   return previousNode;
 }

 //Search for an element in movies database.  Returns current element.
 //Useful for when you don't need the previous element and easier to deal with the head.
 Movie *SearchRecords(int searchMovieID)
 {
   Movie *currentNode = head; //Start at head

   //Loop from head until all elements have been searched or a match is found
   while(currentNode != NULL && currentNode->movieID != searchMovieID)
   {
     currentNode = currentNode->next;
   }

   //Returns null if no match is found
   return currentNode;
 }

 //Linked list operation to insert new node in sorted
 int InsertNode(Movie *newNode)
 {
   Movie *previousNode, *nextNode;  //Declare variables for previous and next nodes of list
   previousNode = ScanList(newNode->movieID); //Search for the previous node

   //Establish new head
   //ScanList returned the head as previousNode
   if(previousNode == head && newNode->movieID < previousNode->movieID)
   {
     head = newNode;
     head->next = previousNode;
     return 1;
   }
   else
   {
     return 0;
   }

   nextNode = previousNode->next; //Set the nextNode

   //Insert new node if the nextNode is null or the movie IDs don't match
   if((nextNode == NULL) || (nextNode->movieID != newNode->movieID))
   {
     previousNode->next = newNode;  //Set newNode in correct spot
     newNode->next = nextNode;  //Replace nextNode in new spot
     return 1;
   }
   else
   {
     //free(newNode);
     return 0;
   }
 }

 //Linked list operation to delete node
 int DeleteNode(int searchMovieID)
 {
   Movie *previousNode, *deleteNode;

   previousNode = ScanList(searchMovieID);

   if(previousNode == head && head->movieID == searchMovieID)
   {
     deleteNode = previousNode;
     head = previousNode->next;
   }
   else
   {
     deleteNode = previousNode->next;
   }

   if((deleteNode != NULL) && (deleteNode->movieID == searchMovieID))
   {
     previousNode->next = deleteNode->next;
     free(deleteNode);
     return 1;
   }
   else
   {
     return 0;
   }
 }

 //Function to print out entire database
 void PrintList()
 {
   Movie *currentNode =  head; //Set the head as current node

   //Iterate through each node
   while(currentNode != NULL)
   {
     //Print node
     PrintNode(currentNode);

     //Set the current node to the next node, go through loop again
     currentNode = currentNode->next;
   }
 }

 //Helper function for printing out individual nodes
 void PrintNode(Movie *node)
 {
   printf("\nMovie ID: %d\n", node->movieID);           //Prints movie's ID
   printf("\tTitle: %s\n", node->title);                //Prints movie's title
   printf("\tDirected by: %s\n", node->director);       //Prints movie's director
   printf("\tReleased in: %d\n", node->yearReleased);   //Prints movie's release date
   printf("\tStarring: %s\n", node->starActor);         //Prints movie's star
   printf("\tIMDB rating: %.1f\n", node->imdbRating);   //Prints movie's rating
 }

 //Function to delete a record from database
 void DeleteRecord()
 {
   //Prompt user and accept input for what to search for.
   int movieID;
   printf("Enter the ID of the movie you wish to delete: \n");
   scanf("%d", &movieID);

   if(DeleteNode(movieID))
   {
     //Alert user that a match was found.
     printf("\tThe movie with ID %d has been deleted.\n", movieID);
   }
   else
   {
     //Alert the user that a match was not found
     printf("\tThe movie was not found in the records.  Delete cancelled.\n");
   }
 }

 //Function for inserting a new record
 void InsertRecord()
 {
   //Variables for storing user input
   int newMovieID;
   char newMovieTitle[STRING_MAX];
   char newMovieDirector[STRING_MAX];
   int newMovieYear;
   char newMovieActor[STRING_MAX];
   float newMovieRating;

   //User prompts
   printf("Follow the instructions to insert a new record.\n");
   printf("\tType in a Movie ID: ");
   scanf("%d", &newMovieID);

   printf("\tType in a movie title: ");
   scanf("%s", newMovieTitle);

   printf("\tType in the director's name: ");
   scanf("%s", newMovieDirector);

   printf("\tType in year the movie was released: ");
   scanf("%d", &newMovieYear);

   printf("\tType in the star actor's name: ");
   scanf("%s", newMovieActor);

   printf("\tType in the IMDB rating: ");
   scanf("%f", &newMovieRating);

   //New node being inserted
   Movie *newNode = (Movie*) malloc(sizeof(Movie));

   //Set values for new node to be inserted
   newNode->movieID = newMovieID;
   strcpy(newNode->title, newMovieTitle);
   strcpy(newNode->director, newMovieDirector);
   newNode->yearReleased = newMovieYear;
   strcpy(newNode->starActor, newMovieActor);
   newNode->imdbRating = newMovieRating;

   if(InsertNode(newNode))
   {
     //Succesful insertion
     printf("New movie succesfully added.\n");
   }
   else
   {
     //Unsuccesful insertion.
     printf("New movie failed to add.\n");
   }
 }
