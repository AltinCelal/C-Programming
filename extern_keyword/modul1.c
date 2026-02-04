#include <stdio.h>
#include"modul.h"
int counter = 15;//global olmalı.!!!!
int main()
{
    
    printf("value of a in modul1: %d\n adress of modul1 : %p\n",counter,&counter);
    artir1();
    feed();

}
