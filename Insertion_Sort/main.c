#include<stdio.h>

int main()
{
    int Array[]={15,65,8,7,45,32,15,69};
    int key;
    int size = (int)(sizeof(Array)/sizeof(Array[0]));
    
    for (int i= 1 ; i < size;i++)
    {
        key = Array[i];
        int j=i-1;
        while (j>=0 && Array[j]>key)
        {
            Array[j+1] = Array[j];
            j=j-1;
        }
        Array[j+1] = key;
         

    }
    for (int k = 0;k<size;k++)
    {
        printf("%d\n",Array[k]);
    } 


    return 0;
}