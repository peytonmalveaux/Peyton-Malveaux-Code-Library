#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "route-records.h"

RouteRecord* createRecords(FILE * fileIn){
    //RouteRecord* records;


      fileIn = fopen("data.csv", "r");

    if (fileIn == NULL)
    {
        printf("Could not open file data.csv");
        return 0;
    }

            int count = 1;
            //counts the number of lines
            char buffer[1000];
            while (!feof(fileIn) && count != -1)
            {
            fgets(buffer, 1000, fileIn);
            count++;
            }

    RouteRecord* records = (RouteRecord*)malloc(count * sizeof(RouteRecord));

    for(int i = 0; i <= 6; i++){
        records->passCount[i] = 0;
    }

      rewind(fileIn);
    return records;

}
int fillRecords(RouteRecord* r, FILE* fileIn){
    char temp[1024];
    char var[13];
    int month;
    int tempPassCount;

    int result = 0;
    fgets(temp, 1024, fileIn);
    char o[4];
    char d[4];
    char a[4];
    int i = 0;



    for(i = 0; i < feof(fileIn); i++)
    {

    fscanf(fileIn,"%d,%[^,],%[^,],%[^,],%[^,],%d", &month, o, d, a, var, &tempPassCount);

        result = findAirlineRoute(r, 1024, o, d, a, i);
        if(result != -1){
            strcpy(r[result].origin, o);
            strcpy(r[result].destination, d);
            strcpy(r[result].airline, a);


          r[result].passCount[month-1] = r[result].passCount[month-1] + tempPassCount;
          i++;
        }
        else{
        r[result].passCount[month-1] = r[result].passCount[month-1] + tempPassCount;

        }

    }
return i;
}

int findAirlineRoute(RouteRecord* r, int length, const char* origin, const char* destination, const char* airline, int curIdx){
    if(curIdx < 0){
        return -1;
    }
    if(strcmp(r[curIdx].origin, origin) == 0 && strcmp(r[curIdx].destination, destination) == 0 && strcmp(r[curIdx].airline, airline) == 0){
        return curIdx;
    }

    return findAirlineRoute(r, length, origin, destination, airline, curIdx-1);

}

void searchRecords(RouteRecord* r, int length, const char* key1, const char* key2, SearchType st){
    int i = 0;
    //int j = 0;
    int monthPass[6] = {0,0,0,0,0,0};
    int tempPass = 0;
    int matches = 0;

    for(i = 0; i < length; i++){
    //FOR ORIGIN
    if (st == ORIGIN && strcmp(r[i].origin, key1)==0){
                printf("%s ",r[i].airline);
                printf("(%s - %s)",r[i].origin, r[i].destination);
                matches++;

                for (int j = 0; j < 6; j++){
                monthPass[j] += r[i].passCount[j];
                }
            }

    //FOR DESTINATION

        else if (st == DESTINATION){
            if(strcmp(key1, r[i].destination)==0){
                printf("%s ",r[i].airline);
                printf("From %s to %s ",r[i].origin, r[i].destination);
                matches++;
            for (int j = 0; j < 6; j++){
            monthPass[j] += r[i].passCount[j];
            }
            }

        }

    //FOR AIRLINE

         else if (st == AIRLINE){
            if(strcmp(key1, r[i].airline)==0){
                printf("%s ",r[i].airline);
                printf("From %s to %s ",r[i].origin, r[i].destination);
                matches++;
                printf("Matches : %d\nTotal Passengers : %d", matches, tempPass);
            for (int j = 0; j < 6; j++){
            monthPass[j] += r[i].passCount[j];
            }
            }

        }

    //FOR ROUTE
        else if(st == ROUTE){
            if(strcmp(key1, r[i].origin)==0 && strcmp(key2, r[i].destination)==0){
            printf("%s ", r[i].airline);
            printf("From %s to %s ",r[i].origin, r[i].destination);
            matches++;
            printf("Matches : %d\nTotal Passengers : %d", matches, tempPass);
                for (int j = 0; j < 6; j++){
                monthPass[j] += r[i].passCount[j];
                }
            }
        }
        else{
            printf("No matches were found\n");
        }

    }

        printf("Matches : %d\n", matches);
       int totaltotal = monthPass[0] + monthPass[1] + monthPass[2] + monthPass[3] + monthPass[4] + monthPass[5];
            printf("Total Passengers: %d\n", totaltotal);
            for (i = 0; i < 6; i++)
            {
            printf("Total Passengers in Month %d: %d\n", i + 1,
            monthPass[i]);
            }
            printf("\n");
            printf("Average Passengers per month: %d\n", totaltotal / 6);
            printf("\n");


    }



void printMenu(){
printf( "\n\n######### Airline Route Records Database MENU #########\n" );
printf( "1. F by Route\n" );
printf( "2. Search by Origin Airport\n" );
printf( "3. Search by Destination Airport\n" );
printf( "4. Search by Airline\n" );
printf( "5. Quit\n" );
printf( "Enter your selection: " );
}



