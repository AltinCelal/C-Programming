#include <stdio.h>
#include <stdlib.h>
#include"stack.h"



int main()
{
    Stack *s = stack_create(2);
    int x;

    stackPush(s, 10);
    stackPush(s, 20);
    stackPush(s, 30); // realloc olur
    
    stackPop(s, &x);
    printf("Cikan: %d\n", x);

    stackPeek(s, &x);
    printf("Ustteki: %d\n", x);

    stackFree(s);
    return 0;

}

