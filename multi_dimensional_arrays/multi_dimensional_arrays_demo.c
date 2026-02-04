#include<stdio.h>
#include <stdlib.h>
void f1(int (*p)[5],size_t size)
{
    for (int i = 0 ; i<size; i++)
    {
        for (int j = 0 ; j< 5 ; j++)
        {
            printf("value of arr[%d][%d]: %d\n",i,j,p[i][j]);
        }
    }

}

void doldur(int (*ptr)[5],size_t size)
{
    for (int i = 0 ;i<size; i++ )
    {
        for(int j = 0 ; j< 5 ; j++ )
        {
            ptr[i][j] = rand()%100;
        }
    }
}
int main()
{

    int arr[]={15,65,98,6};

    int multi_dimensional_array [4][5];
    /*doldur(multi_dimensional_array,sizeof(multi_dimensional_array));
    bu şekilde kullanmak hata sizeof(multi_dimensional_array) 80 döndürür.
    */

    doldur(multi_dimensional_array,4);
    f1(multi_dimensional_array,4);



}