#include<stdlib.h>
#include<stdio.h>
int main()
{
    /*
    Sequence point,
    bir noktaya gelindiğinde
    önceki yan etkilerin tamamlandığının garanti edildiği yerdir.
    Öncesi bitmiştir sonrası başlayabilir.


    Yan Etki (Side Effect) Nedir?
        Bir ifadenin programın durumunu değiştirmesi:
            x = 5;   x değişti → side effect
            x++;     x değişti → side effect
            --x;     x değişti → side effect

        !!! x + 5;  sadece hesap → side effect yok

        Bir nesne, yan etkisi tamamlanmadan tekrar kullanılırsa → Undefined Behavior


        Sequence Point Nerelerde Var?

        En önemlileri 👇

        1️⃣ ; (Statement sonu)
        
        x++;
        y = x;

        ; → sequence point

        x++ tamamlandı

        y = x güvenli

        2️⃣ Logical operatörler
        && ve ||
        ptr && ptr->data
        Sol taraf biter

        Sonra sağ tarafa geçilir (gerekirse)

        3️⃣ Ternary ?:
        cond ? a : b


        cond tamamen biter

        Sonra sadece biri çalışır

        4️⃣ Virgül operatörü ,
        (a++, b)


        a++ biter

        sonra b çalışır

        5️⃣ Function call
        func(x);


        Argümanlar değerlendirilir

        Sonra fonksiyon çağrılır

        🔹 Sequence Point OLMAYAN Yerler (Tehlikeli)
        x++ + x        // ❌
        x = x++        // ❌
        a[i++] = i     // ❌


        ➡️ Undefined Behavior

        🔍 Neden UB?
        x++ + x


        x++ → x değişecek

        x → x okunuyor

        Ama:

        önce mi artacak?

        sonra mı?

        compiler karar verir

        ➡️ Standart garanti vermez





        !!!!! x = x++; UB dir.
        sequence point olmadan x 2 defa değiştiriliyor.
        Sonuç : Yan etkiye maruz kalmış nesneyi yan etki notkası geçmeden kullanmayın.





        !!!!!!!!!!!!!!!!!!!!!!
        Maximum munch kuralı: Derleyici, mümkün olan en uzun geçerli token’ı seçer.



        5, 7

        5 çalışır

        sequence point

        7 çalışır

        ifadenin sonucu = 7

    
    int x = 1;
	int y = 1;
	int z = 1;
	
	x += y += z;
	//x = (x + (y = (y + z)));
	
	printf("%d %d %d",x,y,z); 3-2-1


    

*/

    int x = 2, y, z;

	x *= 3 + 2;
	printf("%d\n", x); //10

	x *= y = z = 4;
	printf("%d\n", x);//40

	x = y == z;// y==z den 1 çıkar.
	printf("%d\n", x);

	x == (y = z); // burada karşılaştırma var 1==4 den 0 döner ama x e atanmamış.
	printf("%d\n", x);

    x = -3 + 4 * 5 - 6;
	printf("%d\n", x);//11

    x = 3 + 4 % 5 - 6;
	printf("%d\n", x);//1

    x = -3 * 4 % -6 / 5;
	printf("%d\n", x);//0



	x = (7 + 6) % 5 / 2;
	printf("%d\n", x);//1


   int a = 0;

	if (-1 < a-- < 0)// if bloğu sequence point(yan etki nok) olduğu için if yanlış ama
					// a nın değeri bu noktaya gelince değeri azalmış.
		printf("if girdi %d\n", --a);
	else
		printf("else girdi %d\n", a);
		
        x = 1;

		if (++x > 2, 5)
			printf("%d\n", ++x);
		else
			printf("%d\n", x++);

/*
    Bu örnek çok kafa karıştırıcı

    öncelikle a ifden çıktıktan sonra azaltırlır
    c burada ilk olarak -1<0 a bakar buradan sonuç doğru olduğu için 1 döner
    artık soru (1<0) a döner bu da yanlış olduğundan else e girer.
    matematiksel düşünmemek lazım sıralılarda!!!


    ALTIN KURAL (EZBER)

    ❗ C’de <, >, <=, >= zincirlenmez

    matematiksel karşılaştırma yapmak istersen 
    if (-1 < a && a < 0) yapman lazım.

*/
    

/*1️⃣ Operatör önceliği

İlgili öncelik sırası:

!

< >

==*/
x = 0;
		y = 1;

		printf("%d\n", !!x == !!y > x + 1);//   !!x == ( (!!y) > (x + 1) )
		printf("%d\n", !!y > !y == !!x < !x);//  ( (!!y > !y) == (!!x < !x) )
		printf("%d\n", !x + !!x + y - !y - !!y);// 


        double d = 0.;
		int i;

		d = d + 0.1 + 0.1 + 0.1 + 0.1;
		d;
		if (d == 0.4)
			printf("d, 1. degerinde\n");
		else
			printf("d, 1. degerinde degil\n");
/*

		if(x % 2); // buradaki ; demek if ile arasında birşey olmadığı için
		{			// null statement olarak geçiyor.
			printf("yazi");
        
		}
        yani print in if le bir alakası yok if çalışır ; den dolayı hiçbir şey yapmadan biter.


*/

}
