#include<stdio.h>

int longest_ones_run(const int *arr, int size);

int main()
{
    int arr[] ={1,1,1,0,0,1,1,1,1,1,0,1,1};
    int size = (int)(sizeof(arr)/sizeof(arr[0]));

    int result = longest_ones_run(arr,size);

    printf("result : %d\n",result);
}



int longest_ones_run(const int *arr, int size)
{
    if (arr == NULL || size <= 0)
        return 0;

    int current_run = 0;
    int max_run = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
        {
            current_run++;

            if (current_run > max_run)
                max_run = current_run;
        }
        else
        {
            current_run = 0;
        }
    }

    return max_run;
}
