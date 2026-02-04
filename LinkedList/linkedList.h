#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node
{
    int data;
    struct Node* next;
}Node;
void addEnd(Node** head,int value);

void printNode(Node * head);

void deleteEndNode(Node **head);

void insertAfter(Node**head, int after, int value);

void deleteAfter(Node**head, int after);

void deleteHead(Node**head);
#endif