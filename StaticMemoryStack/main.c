#include<stdio.h>
#include"stack.h"
/*
STACK ->LIFO
*/


int main()
{
    Stack s;
    int x;

    initStack(&s);

    pushStack(&s, 10);
    pushStack(&s, 20);
    pushStack(&s, 30);

    printStack(&s);

    popStack(&s, &x);
    printf("Cikan: %d\n", x);

    peek(&s, &x);
    printf("Ustteki: %d\n", x);

    printStack(&s);

    return 0;


}