#include<stdio.h>
#include <limits.h>// int_min için

int find_second_max(const int *arr, int size, int *second);

int main()
{

    int Arr[]={-3, 5,6,989,56,12,324};
    int SizeArr=(int)(sizeof(Arr)/sizeof(Arr[0]));

    int second;


    int a = find_second_max(Arr,SizeArr,&second);
    printf("\nsecond max : %d \n return value: %d",second,a);
}

int find_second_max(const int *arr, int size, int *second)
{
    if (size < 2)
        return 0;

    int max = INT_MIN;
    int secondmax = INT_MIN;
    int found = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            if (max != INT_MIN || found)
            {
                secondmax = max;
                found = 1;
            }
            max = arr[i];
        }
        else if (arr[i] < max && (!found || arr[i] > secondmax))
        {
            secondmax = arr[i];
            found = 1;
        }
    }

    if (!found)
        return 0;

    *second = secondmax;
    return 1;
}
