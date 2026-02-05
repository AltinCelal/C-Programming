#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include<stdio.h>

typedef struct   
{
    int *data;//elemanların adresini tutacak.
    size_t size;//mevcut eleman sayısı
    size_t capacity;//bellekte ayrılan kapasite.
}ArrayList;

ArrayList* arraylist_create(size_t capacity);

int arraylist_add(ArrayList * list, int value);

int arraylist_get(ArrayList *list, size_t index, int *out);

void arraylist_free(ArrayList *list);

int arraylist_insert(ArrayList *list, int index, int value);





#endif