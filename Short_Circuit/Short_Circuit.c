#include<stdio.h>

int main()
{
    int a = 1;
    int b = 0;

    if(a && ++b)
    {
        //burada 2. kısım da çalıştı çünkü
        // a true ve and bağlacı var KISA DEVRE YOK!
    }
    printf("b value is : %d",b);

    int c = 0;
    int d = 0;

    if (c && ++d)
    {
        // burada kısa devre var 
        //ikinci kod çalışmaz çünkü
        // c false her durumda ve bağlacında 
        //false dönecek.
    }
    printf("d value is : %d",d);

    if (printf("Hello\n"))
    {
        printf("Printed something\n");
    }
    /*if içinde sadece karşılaştırma değil 
    atama da yapabiliriz. Yukarıda Hello çalışır
    çıktı olarak karakter sayısı veriri 0 
    olmadığı için alttaki printte çalışır.*/

    /*int value = 5;

    printf("%d\n", value++);  // 5 önce yazdırılır sonra artırılır.
    printf("%d\n", value);    // 6*/



}