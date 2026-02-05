#include <stdio.h>
#include <stdlib.h>
#include"node.h"

Node* findMiddle(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // 1 adım
        fast = fast->next->next;     // 2 adım
    }

    return slow;
}

Node * createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));

    if (!newNode) return NULL;

    newNode->data = value;
    newNode->next = NULL;
    return newNode;

}


void append(Node **head,int value)
{
    Node *newNode = createNode(value);

    if (!newNode) return ;

    if(*head == NULL)
    {
        *head = newNode;
        
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

}


void printList(Node *head)
{
    if(head == NULL) return;

    while(head!=NULL)
    {
        printf("%d ->",head->data);
        head = head->next;
    }
    printf("NULL\n");

}

void reverseList(Node **head)
{

    Node *prevNode = NULL;
    Node *currNode = *head;
    Node *nextNode = NULL;



    while (currNode != NULL) {
        nextNode = currNode->next;   // sonraki node'u sakla
        currNode->next = prevNode;   // yönü ters çevir
        prevNode = currNode;         // prev'i ilerlet
        currNode = nextNode;         // curr'u ilerlet
    }

    *head = prevNode;
}