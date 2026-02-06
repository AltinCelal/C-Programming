#include <stdio.h>
#include <stdlib.h>
#include"stack.h"
Stack* stack_create(int capacity)
{
    Stack *s = malloc(sizeof(Stack));

    if (!s) return NULL;

    s->data = malloc(sizeof(int)*capacity);
    if(!(s->data)) 
    {
        free(s);
        return NULL;
    }
    s->top = -1;
    s->capacity = capacity;
    return s;
}

int isEmpty(Stack *s)
{
    if (s->top == -1)
    {
        return 0;
    }
    else
    return 1;

}

int isFull(Stack *s)
{
    if(s->top == s->capacity-1)
    {
        return 0;
    }
    else
    return 1;

}

int stack_grow(Stack *s)
{
    int newCap = s->capacity*2;

    int *tmp = realloc(s->data,newCap*sizeof(int));

    if(!tmp)
        return -1;

    s->data = tmp;
    s->capacity = newCap;
    return 0;
}

int stackPush(Stack *s,int value)
{
    if (!isFull(s))
    {
        if(stack_grow(s)!=0)
            return -1;
        
    }
    s->data[++s->top] = value;
    return 0;   

}


int stackPop(Stack *s, int* out)
{
    if(isEmpty(s)==0)
    {
        printf("Stack is empty!");
        return -1;
    }

    *out = s->data[s->top--];
    return 0;
}

int stackPeek(Stack *s, int * out)
{
    if(isEmpty(s)==0)
    {
        printf("Stack is empty!");
        return -1;
    }

    *out = s->data[s->top];
    return 0;

}

void stackFree(Stack *s)
{
    if(!s) return;

    free(s->data);
    free(s);
}