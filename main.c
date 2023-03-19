#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "route-records.h"

int main( int argc, char *argv[] )
{
    /* 1. Declare variables here */
    FILE* fp;
    RouteRecord* r;


    int flightsLength;
    /* 2. Check command line arguments here. If a command line argument (for the file name) is missing, print out the following: ERROR: Missing file name and end the program */
    /*if (argc < 3) {
      printf("missing argument\n");
      exit(-1);
    }

    /* 3. Attempt to open the file. Print out Opening <filename>... before you call fopen(). */
    printf("Opening data.csv...");
    /* 4. Check to see if the file opens. If it does not open, print out ERROR: Could not open file and end the program. */
        fp = fopen("data.csv","r");
        if(fp == NULL){
            printf("Error File could not open");
            exit(1);
        }
/* 5. Do the following to load the records into an array of RouteRecords

5.1 Call createRecords(), which will read through the file once to find the total number of lines/records in the file. Use this count, to dynamically allocate memory for an array of RouteRecords. It returns a pointer to that array. Don't forget to rewind the file pointer.

5.2 Call fillRecords() to go through the CSV file again to fill in the values. It will then return the actual number of items the array has. Recall that not all records in the original CSV file will be entered into the array. Print the number of unique routes operated by different airlines: Unique routes operated by airlines: ???

    		5.3 Close the the file.
    */
    r = createRecords(fp);
    flightsLength = fillRecords(r, fp);

    fclose(fp);


    /* 6. Create an infinite loop that will do the following:

    		6.1 Call printMenu()

    		6.2 Ask the user to input a value for the menu

    		6.3 Handle the case in which a non-integer value is entered

    		6.4 Create a switch/case statement to handle all the menu options

	    		6.4.1 Each option requires the user to enter a search key

	    		6.4.2 Quit needs to free the array

    */
    int i =0;
  while(i != 1){
    int userChoice;
    char key1[4];
    char key2[4];

    SearchType st;
    printMenu();
    printf("Enter Your Choice Below: \n");
    scanf("%d", &userChoice);
    /*while(userChoice <= 0 || userChoice > 5){
        printf("Enter a different number");
        scanf("%d", &userChoice);
    }*/
    switch(userChoice){
   case 1:
        // By ROUTE
        st = ROUTE;
        printf("Enter the origin: ");
        scanf("%s", key1);
        printf("\n");
        printf("Enter destination: ");
        scanf("%s", key2);

    break;
       case 2:
        // By Origin
        st = ORIGIN;
        printf("Enter the origin: ");
        scanf("%s", key1);
        printf("\n");


    break;

       case 3:
        // By DESTINATION
        st = DESTINATION;

        printf("Enter destination: ");
        scanf("%s", key1);
        printf("\n");
    break;

       case 4:
        // By Airline
        st = AIRLINE;
        printf("Enter the AIRLINE: ");
        scanf("%s", key1);
        printf("\n");
    break;

       default:
        printf("\n");
        i++;
    }
    searchRecords(r,flightsLength, key1, key2, st);




  }
    return 0;
}
