#ifndef NODE_H
typedef struct List
{
    int data;
    struct List *next;

} Node;

Node * createNode(int value);

void append(Node **head,int value);

void printList(Node *head);

void reverseList(Node **head);
#define NODE_H
#endif

