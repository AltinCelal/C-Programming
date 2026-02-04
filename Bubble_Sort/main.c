#include <stdio.h>

int main()
{
    int Array[] = {15, 8, 6, 91, 23, 9,65,89,45,3215};
    int ElementsOfArray;
    size_t n = sizeof(Array)/sizeof(Array[0]);
    ElementsOfArray = (int)n;
    
    
    for(int i = 0 ; (i< ElementsOfArray-1); i++ )
    {
        int tempValue;
        for(int j=0 ; j<ElementsOfArray-1-i;j++)
        {
            if (Array[j]>Array[j+1])
            {
                tempValue=Array[j+1];
                Array[j+1]=Array[j];
                Array[j]=tempValue;
            }

        }

    }

    for(int k = 0 ; k<ElementsOfArray; k++)
    {
        printf("%d\n",Array[k]);

    }

    return 0;
}
