#ifndef STACK_H
typedef struct Stack 
{
    int *data;
    int top;
    int capacity;
}Stack;
Stack* stack_create(int capacity);
int isEmpty(Stack *s);
int isFull(Stack *s);
int stack_grow(Stack *s);
int stackPush(Stack *s,int value);
int stackPop(Stack *s, int* out);
int stackPeek(Stack *s, int * out);
void stackFree(Stack *s);

#define STACK_H
#endif