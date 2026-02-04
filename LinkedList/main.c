#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"
int main()
{
    Node *head = NULL;
   
    addEnd(&head,15);
    addEnd(&head,56);
    addEnd(&head,45);
    addEnd(&head,9);
    addEnd(&head,1325);
    addEnd(&head,77);

    printNode(head);
    printf("\n\n\n");

    deleteEndNode(&head);
    deleteEndNode(&head);
    
    insertAfter(&head,56,11);
    printNode(head);
    
    printf("\n\n\n");

    
    deleteHead(&head);
    deleteHead(&head);
    insertAfter(&head,9,999);
    
    insertAfter(&head,999,111);
    deleteHead(&head);
    printNode(head);



}
