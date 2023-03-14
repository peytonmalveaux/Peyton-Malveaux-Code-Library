
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

int main(int argc, char* argv[]){
    FILE* fp;
    LLNode* node;
    LLNode* head = NULL;
    if (argc == 2) {
    } else {
    printf("ERROR NO ARGS");
    return -1;
    }
    fp = fopen(argv[1], "r");

    if(fp == NULL){

        printf("ERROR FILE NOT OPEN");
        return -1;
    }
    //Go through the file line by line until the end of the file. As we are using a linked list we do not need to know the number of lines beforehand.

        int id;
        char name[20];
        double gpa;

    while (fscanf(fp, "%d,%[^,],%lf", &id, name, &gpa) != EOF){
        node = createNode(id, name, gpa);
        head = InsertNode(head, node);
        }
    fclose(fp);
    AverageGPA(head);
    PrintLL(head);

    destroyLL(head);

return 0;
}
