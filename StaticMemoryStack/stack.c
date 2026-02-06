#include<stdio.h>
#include"stack.h"
/*
++s->top ile ++(s->top) aynı ifadeler
-> önceliği ++ da daha yüksek!!
*/

void initStack(Stack *s)
{
    s->top=-1;//stack boş,geçerli veri yok.

}

int isStackFull(Stack *s)
{

    if (s->top==MAX-1)
    {
        return 1;
    }
    return 0;
}

int pushStack(Stack *s, int value)
{
if (isStackFull(s)==1)
    {return -1;}

    s->data[++s->top] = value;
    return 0;
}

int popStack(Stack *s, int *out)
{
    if (isEmpty(s)) {
        return -1;
    }

    *out = s->data[s->top--];
    return 0;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void printStack(Stack *s)
{
    if (isEmpty(s)) {
        printf("Stack bos.\n");
        return;
    }

    printf("Stack (ustten alta): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int peek(Stack *s, int *out)
{
    if (isEmpty(s))
        return -1;

    *out = s->data[s->top];
    return 0;
}