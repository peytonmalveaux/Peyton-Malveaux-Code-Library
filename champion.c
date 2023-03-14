#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "champion.h"

Champion* createChampion(){
    Champion* champion = (Champion*)malloc(sizeof(Champion));
    int number = (1 + rand() % 100);
    if (number <= 25) {
        champion->roll = MAGE;
        champion->level = 5 + rand() % 8;

    } else if (number <= 50) {
        champion->roll = FIGHTER;
        champion->level = 1 + rand() % 4;

    } else if (number <= 75) {
        champion->roll = SUPPORT;
        champion->level = 3 + rand() % 6;
    } else{
        champion->roll = TANK;
        champion->level = 1 + rand() % 8;
    }
    return champion;
}

//INSERT AFTER FUNTION
Champion* addChampion(Champion *head, Champion *c ){
    if(head == NULL)
        return c;
    Champion* tmp = head;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = c;
    return head;
}

//BUILD CHAMPION LIST
Champion* buildChampionList( int n ){
    Champion* head = (Champion*)malloc(sizeof(Champion));
    for(int i = 0; i < n; i++){
        Champion* n = createChampion();
        head = addChampion(head, n);
    }
    return head;
}
Champion* removeChampion(Champion *head){
    Champion* cur = head;
    Champion* prev = NULL;
    Champion* next = NULL;

    while(cur != NULL){
        next = cur->next;
        prev = cur;
        cur = next;
    }
    return prev;
}
void printChampionList(Champion *head){
    Champion* node = head;
    char roll[7];
    while(node != NULL){
        if(node->roll == MAGE)
            strcpy(roll, "(M)");
        if(node->roll == SUPPORT)
            strcpy(roll, "(S)");
        if(node->roll == FIGHTER)
            strcpy(roll, "(F)");
        if(node->roll == TANK)
            strcpy(roll, "(T)");
        
        
        printf("%s%d ",roll, node->level);
        node = node->next;
    }
}
Champion* destroyChampionList( Champion *head ){
    while (head != NULL) {
    Champion* node = head;
    head = head->next;
    free(node);
    }
return head;
}
