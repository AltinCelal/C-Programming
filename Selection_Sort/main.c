#include<stdio.h>

int main()
{
    int minValue;
    int tempValue;
    int tempIndex;
    int Array[]={65,8,88,98,65,15,32,55,4,352};
    int Size = (int)(sizeof(Array)/sizeof(Array[0]));
  
    for(int i = 0; i<Size-1; i++)
    {
        minValue=Array[i];
        tempIndex=i;
        for(int j=i+1 ; j<Size;j++)
        {
            
            if(minValue>Array[j])
            {
                minValue=Array[j];
                tempIndex=j;
            }
            
        }
        tempValue=Array[i];
        Array[i]=Array[tempIndex];
        Array[tempIndex]=tempValue;
    }

    for(int k =0 ; k<Size ; k++)
    {
        printf("%d\n",Array[k]);
    }



}