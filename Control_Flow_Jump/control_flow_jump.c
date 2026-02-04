#include<stdio.h>

int main()
{
    //goto -unconditional jump
    printf("1\n");

        goto atla;

        printf("2\n");   // This line does not work.
    atla:
        printf("3\n");

        //break- exit the loop
   for (int i = 0; i < 5; i++) {
        if (i == 2)
            break;

        printf("%d\n", i);
    }
    printf("Bitti\n");


    //contine - jump to the beginning of the loop
    for (int i = 0; i < 5; i++) {
        if (i == 2)
            continue;

        printf("%d\n", i);
    }

    printf("\n\n\n");

    int x=-1;
    unsigned int y=1;
    if(y>x)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
/*
işaretli ve işaretsiz karşılaştırılırsa sonuç önce işaretli işaretsize dönüştürülür daha sonra karşılaştırma 
yapılır. -1 = 111 1111 1111 1111 -> bunun değeri -1
pozitife değiştirilmesi için baştaki 1 artık unsigned biti oluyor 
4.2 milyar küsür oluyor o yüzden 4.2 milyar>1 
*/


/*
ATAMANIN YAPTIĞI NESNEYE DOĞRU TÜR DEĞİŞİR.
x = y  -> x double ise , y yi ilk önce double a çevirir sonra x e atar.
func(x) -> func in parametresi int olsun, argüman ise double olsun. argüman gönderirken int e çevirir. 


dezavantajı: 
//	büyük türden küçüğe kopyalama yaparken veri kaybı olur.
//	
//	char c; [-128 / 127] tutar
//	int i = 987;
//	c = i;    char 987 tutamayacağı için veri kaybı olur.
//	printf("%d",c); --> -37 çıkar

-37 nin sebebi ÇOOOOOK ÖNEMLİ
//	987 -- > HEX te 3DB dir. hex ten hesaplıyorum çünkü hesaplaması daha kolay. binary den de hesaplanır.
//	char 1 byte yani -> 3DB den 3 olmayacak -> DB kaldı -> DB = 1101 1011 -> bu da işaretli char türden negatif bir değer	
//	işaretli lerde en soldaki 1 negatif olduğunu belirtir zaten.Hesaplayarken 2 ye tümleyeni alınır. değer bulunur ve başına 
//  - konur.sayının negatifi alınır.
//
//	1101 1011 in 2 ye tümleyeni -> 0010 0101 -> 37 -> -37 dir.
//
//	Warningde de conversion from int to char possible loss of data verir.
//	Bu kod yanlış kabul edilir.
//	eğer bilerek yapıldıysa:
//	burada type-casting yapılmalı.
*/

    x = 20;
	y = 10;
	double dval = 3;
//	
	double d = (x > 10 ? y : dval) / 3;     //ternary operator tur değisikliği işlemini double türde yapar.
 printf("Celal\n");
    printf("d = %f\n",d);            
}