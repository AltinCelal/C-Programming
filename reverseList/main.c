#include <stdio.h>
#include"node.h"

int main()
{
    Node *head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    printf("Orijinal liste:\n");
    printList(head);

    reverseList(&head);

    printf("\nTersine cevrilmis liste:\n");
    printList(head);

    return 0;

}

