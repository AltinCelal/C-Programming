#include<stdio.h>
/*
Linear search is used for unsorted arrays with a time complexity of O(n).
*/

int linear_search(const int *arr, const size_t size, int target)
{
    for (int i = 0 ; i < size ; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    return -1;

}

int main()
{
    int Arr[]={15,68,98,452,32,6548,65,78,95,12,32,45,78,21};

    size_t size = sizeof(Arr)/sizeof(Arr[0]);

    int result = linear_search(Arr,size,78);

    printf("Result : %d\n",result);
}