#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main()
{

    //rand() INT DEĞER DÖNDÜRÜR.
    //printf("\n%d",RAND_MAX); bu şekilde her çalıştırmada aynı değeri verir çünkü seed değeri aynı
    srand(time(NULL));//burada seed değerini zamana bağlı kılıyoruz bu şekilde her çalıştırmada farklı
    //bir deger verir.
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());
    /*
    aslında bir rastgelelik yoktur arka planda bir matematik denkleminden çıkan sonucu verir.

    srand(123) rastgele deger üreteci 123 den başlasın demek.

    time(NULL) 1 ocak 1970 ten bu yana geçen her saniye.Her saniye değişir.
    */
   /*while (1)
    {
        srand(time(NULL));
        printf("%d\n", rand());
        buradaki hata while çok hızlı yani saniye değişmeden çok kez yazdırıyor o yüzden aynı değerler dönüyor.
    }
    
*/


int a = rand() % 10; // 0 ile 9 arasında rasgele sayı üretir        0- (N-1)


/*
    iki aralık arasında üretmek için örn:A-B arasında
    A+rand() % (B-A+1)
    
    */


    //mesela 215 ile 191 arasında üretelim

    int randValue = 191 + rand() % (215-191+1);

    printf("RandValue : %d",randValue);

}