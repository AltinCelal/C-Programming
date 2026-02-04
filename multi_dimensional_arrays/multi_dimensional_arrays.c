#include<stdio.h>
/*
C de aslında çok boyutlu diziler yoktur.
 
C de kavramsal olarak çok boyutlu diziler vardır ama tek boyutlu lineer bir 
bellek bloğu olarak tutulur.

int a[5][10]; Bu tanımlanabiliyor evet.
a dizisi elemaları 10 elemanlı int dizisi olan 5 elemanlı bir dizi.
Birinci parantez dizinin boyutu ikincisi ise a nın elemanları olan int dizisinin boyutu.

yani a[0] ile a[4] arasındakilerin hepsi 10 elemanlı bir dizi.

NOT: Bütün diziler bellekte tek bir blokta olmak zorundalar.

double d[3][8] -> Okunuş -> Elemanları 8 elemanlı double bir dizi olan 3 elemanlı bir dizi. 

ÇOK ÖNEMLİ

int a[3][10];
int* p = a; // C de yanlış, C++ ta sentaks hatası.

burada p nin a yı göstermesi için 1 artırdığımda, p nin değeri 10 elemanlı bir dizinin sizeof değeri kadar atlamalı.

ÖR:
 int a[10][4]; dizisinin elemanları arasında sizeof(int) * 4 kadar mesafe var. 
for (int i = 0; i < 3; i++)
{
	printf("%p   %p\n", &a[i], a + i); // 16 lık sistemde hesaplanırsa 16 kadar artmış her seferinde
}
yani bunu bir pointera atayınca, bu pointer 1 artırıldığında 16 byte artacak.Böyle bir pointer tanımlanacak.

ÖR:
int a[10][4];
Buna uygun bir ptr tanımlarsak.a nın türü int (*)[4];

int (*ptr)[4] = a;   // tür uyuşmazlığı uyarısıda vermedi.
burada ptr++ dersek sizeof(int) * 4 byte kadar ileri gider memoryde.

int a[10][4];
int(*p)[4] = a;

for (int i = 0; i < 10; i++)
{
	printf("%p   %p	   %p\n", &a[i], a + i,p); // 16 lık sistemde hesaplanırsa 16 kadar artmış her seferinde
	p++;
}
**p ile tutmak yanlıştır.C++ ta ise direkt sentaks hatası.
 
int a[10][4];

 A NIN İLK ELEMANININ ADRESİNİ TURMAK İÇİN 3 PRATİK YOL VAR.

 int *p1 = &a[0][0];
 int *p2 = a[0]; // a nın ilk elemanı da adres tutuyor çünkü.Array decay den a[0] ın da adresine dönüşüyor.
 int *p3 = (int *)a; // normalde uyarı mesajı veriyor ama cast ederek yapabiliriz.

-----------------------------------------------------

ÇOK BOYUTLU DİZİLERİN FONKSİYONLARA GÖNDERİLMESİ

A,B VE C için kullanılabilecek fonksiyonlara ihtiyacımız olabilir.
ama türleri farklı dizileri fonksiyona göndermek farklı türlerde oldukları için her birine özel
fonksiyon yazmak anlamına gelir.

Tanımlar aşağıdaki gibi olmalıdır.Türler farklı olduğu için farklı fonksiyonlar yazıldı.


void f1(int(*p)[20],size_t size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < 20; j++)
			p[i][j] = rand() % 100;
}

void f2(int(*p)[8],size_t size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < 8; j++)
			p[i][j] = rand() % 100;
}
void f3(int(*p)[6], size_t size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < 6; j++)
			p[i][j] = rand() % 100;
}

int main()
{

	int a[10][20];
	int b[5][8];
	int c[4][6];
	int d[5][6];// bu yukarıdaki ile aynı türden.yani aynı fonksiyona gönderilebilir.

	f1(a, 10);
	f2(b, 5);
	f3(c, 4); // alttaki ile aynı fonksiyon çağrısı ile olur çünkü array türleri aynı
	f3(c, 5);

}

-------------------------------------------------------------------
*/
int main()
{
    int a [5][10];
    for (int i = 0 ; i< 5 ; i++)
    {
        for (int j=  0 ; j<10 ; j++)
        {
            a[i][j]=rand()%100;
        }

    } 
    printf("Size of a : %zu",sizeof(a));//boyutu 200 = 5*10*int boyutu.
    int *ptr = &a[0][0];
    //int *ptr = &a yanlış.

    printf("\nvalue of *ptr:%d\n",*ptr);
    ptr++;
    printf("\nvalue of *ptr:%d\n",*ptr);

    --ptr;

    printf("\nvalue of *ptr:%d\n",*ptr);


}