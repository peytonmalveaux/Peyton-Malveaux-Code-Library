
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

LLNode* createNode(int id, char name[20], double gpa){
        LLNode* create = (LLNode*) malloc(sizeof(LLNode));
        create->id = id;
        create->gpa = gpa;
        strcpy(create->name, name);
        create->next = NULL;
        return create;
}

LLNode* InsertNode(LLNode *head, LLNode *newNode){
    LLNode *n = newNode;
    LLNode* cur = head;
    LLNode* prev = NULL;
    while((cur != NULL) && (strcmp(cur->name, newNode->name) <= 0)){
        prev = cur;
        cur = cur->next;
    }
    if(prev == NULL){
        n->next = cur;
        return n;
    }
    prev->next = n;
    cur->next  = cur;
    return head;
}
double AverageGPA(LLNode* head){
    LLNode* thisNode = head;
    double sum = 0;
    int i = 0;
    while (thisNode != NULL) {
    sum += thisNode->gpa;
    i++;
    thisNode = thisNode->next;
    }
    double avg;
    avg = sum/4;
    printf("Average = %.2lf\n", avg);
    return avg;
}

void PrintLL(LLNode* head){
    LLNode* thisNode = head;


    while (thisNode != NULL) {
    printf("(%d,%s,%.2lf) -> ", thisNode->id, thisNode->name, thisNode->gpa);
    thisNode = thisNode->next;
    }
}
LLNode* destroyLL(LLNode *head){
    while (head != NULL) {

    LLNode* t = head;
    head = head->next;
    free(t);
    }

    return head;
}
