#ifndef STACK_H
#define MAX   10
typedef struct stack
{
    int data[MAX];
    int top;//en üst elemanı tutacak.
}Stack;

int peek(Stack *s, int *out);

int isEmpty(Stack *s);

void initStack(Stack *s);

void printStack(Stack *s);

int isStackFull(Stack *s);

int pushStack(Stack *s, int value);

int popStack(Stack *s, int *out);
#define STACK_H
#endif