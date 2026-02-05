#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arraylist.h"

int main()
{   
    ArrayList *list = arraylist_create(2);
    if (!list) {
        printf("arraylist_create failed\n");
        return 1;
    }

    printf("=== arraylist_add test ===\n");
    arraylist_add(list, 10);
    arraylist_add(list, 20);
    arraylist_add(list, 30);   // realloc olmalı

    for (size_t i = 0; i < list->size; i++) {
        int value;
        arraylist_get(list, i, &value);
        printf("%d ", value);
    }
    printf("\n\n");

    printf("=== arraylist_insert (middle) ===\n");
    arraylist_insert(list, 1, 99);  // 10, 99, 20, 30

    for (size_t i = 0; i < list->size; i++) {
        int value;
        arraylist_get(list, i, &value);
        printf("%d ", value);
    }
    printf("\n\n");

    printf("=== arraylist_insert (front) ===\n");
    arraylist_insert(list, 0, 77);  // 77, 10, 99, 20, 30

    for (size_t i = 0; i < list->size; i++) {
        int value;
        arraylist_get(list, i, &value);
        printf("%d ", value);
    }
    printf("\n\n");

    printf("=== arraylist_insert (back) ===\n");
    arraylist_insert(list, list->size, 55); // sona ekleme

    for (size_t i = 0; i < list->size; i++) {
        int value;
        arraylist_get(list, i, &value);
        printf("%d ", value);
    }
    printf("\n\n");

    printf("=== arraylist_get bounds test ===\n");
    if (arraylist_get(list, 100, &(int){0}) != 0)
        printf("Out of bounds get OK\n");

    arraylist_free(list);
    return 0;


}