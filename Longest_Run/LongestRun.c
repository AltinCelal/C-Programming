#include <stdio.h>
/*
Bir dizide ardışık en uzun artan alt dizinin uzunluğunu bul.
Girdi:  {1, 2, 3, 2, 3, 4, 5, 1}
Çıktı:  4        // {2, 3, 4, 5}
size == 0

size == 1

Tüm elemanlar eşit

Tüm elemanlar azalan

Negatif sayılar
*/
int longest_increasing_run(const int *arr, int size);

int main()
{
    int Arr[]={1, 2, 3, 2, 3, 4, 5, 1};
    int size = (int)(sizeof(Arr)/sizeof(Arr[0]));

    int result = longest_increasing_run(Arr,size);
    printf("Result: %d",result);
}


int longest_increasing_run(const int *arr, int size)
{
    if (size == 0)
        return 0;
    if (size == 1)
        return 1;

    int result = 1;
    int temp = 1;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            temp++;
            if (temp > result)
                result = temp;
        }
        else
        {
            temp = 1;
        }
    }

    return result;
}
