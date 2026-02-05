#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arraylist.h"

ArrayList* arraylist_create(size_t capacity)
{
    ArrayList *list = malloc(sizeof(ArrayList));
    if(!list) return NULL;

    list->data = malloc(capacity*sizeof(int));

    if(!list->data)
    {
        free(list);
        return NULL;
    }

    list->size = 0;
    list->capacity = capacity;
    return list;

}


int arraylist_add(ArrayList * list, int value)
{
    if(list->size == list->capacity)
    {
        size_t newCap = list->capacity * 2;
        int *tmp = realloc(list->data,newCap * sizeof(int));
        if (!tmp) return -1;

        list->data = tmp;
        list->capacity = newCap;
    }

    list->data[list->size++] = value;
    return 0;

}

int arraylist_get(ArrayList *list, size_t index, int *out)
{
    if (index >= list->size) return -1;
    *out = list->data[index];
    return 0;
}


void arraylist_free(ArrayList *list)
{
    if (!list) return;
    free(list->data);
    free(list);
}

int arraylist_insert(ArrayList *list, int index, int value)
{
    if (!list) return -1;


    if (list->size == list->capacity)
    {
        size_t newCap = list->capacity * 2;
        int *tmp = realloc(list->data, newCap * sizeof(int));
        if (!tmp) return -1;

        list->data = tmp;
        list->capacity = newCap;
    }

    
    if (index < 0 || index > (int)list->size)
        return -1;

   
    memmove(
        &list->data[index + 1],
        &list->data[index],
        (list->size - index) * sizeof(int)
    );

    
    list->data[index] = value;
    list->size++;

    return 0;
}
