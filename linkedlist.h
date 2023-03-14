#ifndef LINKEDLIST
#define LINKEDLIST

typedef struct LLNode{
    int id;
    char name[20];
    double gpa;
    struct LLNode* next;
}LLNode;

LLNode* createNode(int id, char name[], double gpa);
LLNode* InsertNode(LLNode *head, LLNode *newNode);
double AverageGPA(LLNode* head);
void PrintLL(LLNode* head);
LLNode* destroyLL(LLNode *head);



#endif

