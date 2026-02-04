#include<stdio.h>

int most_frequent(const int *arr, int size, int *value, int *count);
int main()
{
    int arr[]={5,6,8,7,5,1,2,5,5,5,3,5};

    int value;
    int count;
    int size = (int)(sizeof(arr)/sizeof(arr[0]));

    most_frequent(arr,size,&value,&count);

    printf("value : %d , count : %d\n",value,count);


}

int most_frequent(const int *arr, int size, int *value, int *count)
{
    int current=1;
    int max_index;
    int max =1;
    if (arr == NULL || size<1)
    {
        return 0;
    }

    for(int i =0;i<size-1;i++)
    {
        
        for(int j = i+1;j<size; j++)
        {
            if(arr[i]==arr[j])
            {
                current++;
            }
            if (current>max)
            {
                max=current;
                max_index =i;
            }
        }
        current=1;
    }
    *value = arr[max_index];
    *count = max;
    return 1;


}