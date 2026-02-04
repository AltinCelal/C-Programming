#include<stdio.h>
/*
    Bir sayının bitsel değili 1 fazlasının negatif halidir. 
    int x;
	int y;
	printf("bir sayi girin :");
	scanf("%d", &x); // 10 girildi
	y = -~x; // y = 11 oldu
	printf("%d", y);

    a<<b a nın bitlerini b kadar sola kaydır demek.

    11111111111 bu a olsun

    a << 3 demek
    11111111000 bununla eşdeğerdir.soldan 3 bit çıkar ve sağa 0 lar eklenir.



    ~(~0u >> 1);
    1️⃣ 0u NEDİR?
0u


0 → tüm bitleri 0

u → unsigned int

Varsayalım sistem 32-bit unsigned int (çoğu sistem):

0u = 00000000 00000000 00000000 00000000

2️⃣ ~0u (bitwise NOT)
~0u


Bitwise NOT:

0 → 1

1 → 0

~0u =
11111111 11111111 11111111 11111111


Bu değer:

UINT_MAX  (tüm bitler 1)

3️⃣ ~0u >> 1 (sağa kaydırma)
~0u >> 1


Unsigned olduğu için:

Logical right shift

Sol tarafa 0 girer

Önce:

11111111 11111111 11111111 11111111


Sağa 1 kaydır:

01111111 11111111 11111111 11111111


Yani:

En soldaki bit artık 0

Geri kalanlar 1

4️⃣ Son adım: ~(...)
~(01111111 11111111 11111111 11111111)


Bitwise NOT uygula:

10000000 00000000 00000000 00000000

5️⃣ SONUÇ NE?

Bu sayı:

Sadece en anlamlı bit (MSB) = 1

Diğer tüm bitler = 0

Hex olarak:

0x80000000


Decimal (32-bit):

2147483648

6️⃣ BU NEYİ TEMSİL EDİYOR?

Bu ifade şunu üretir:

👉 Unsigned int türünün en yüksek bit maskesi

Yani:

1u << (sizeof(unsigned int)*8 - 1)


ile aynı şey.
7️⃣ NEDEN BÖYLE YAZILIR?
Amaçlar:

MSB maskesi üretmek

Sign bit test etmek

Taşma kontrolü

Portable (bit sayısına bağlı değil)


!!!!!
INTEGRAL PROMOTION BURADA DA VAR.Sol taraf char sağ taraf int se.
sadece sol operant için var.

Bitsel & ve | u biliyorsun zaten tekrar yazmıyorum.

^ xor -> Bitler aynıysa 0 farklıysa 1 döndürür.


NOT:

X ^= Y;
X ^= Y;   X BURADA KENDİ DEĞERİNE TEKRAR GELİR.

================================================================
Bit tam sayının belirli bir bitini belirlemek istiyorum:
KURALI YAZARSAK
X BİR TAMSAYI DEĞİŞKEN, N BU TAMSAYININ SET EDİLECEK İNDEXİ OLMAK ÜZERE,
X İN N İNCİ BİTİNİ SET EDEN İFADE 
X | (1 << N) YAN ETKİ YOK
X |= (1 << N) YAN ETKİ VAR


Bir tam sayının belirli bir bitini 0 lamak istersem:
X & ~(1 < n)	yan etkisi yok
X &= ~(1 < n)	burada yan etki var

================================================================
Bir tam sayının belirli bir bitini tersine çevirmek için:

x ^(1<<N);
x ^=(1<<N);

================================================================
Bir tam sayının belirli bir bitinin 1  yada 0 olduğunu öğrenmek için:

Öğrenmek istediğimiz biti 1 ile ve(&) işlemine sokuyoruz.
eğer sonuç 1 ise o bit 1 
eğer sonuç 0 ise o bit sıfır

if(x & (1<<N))
    //if e girerse bit 1 demek

else
    //else e girerse bit 0 demek.


=====================================================================
ÖNEMLİ ÖRNEK
İKİ SAYININ ZIT İŞARETLİ OLDUĞUNU NASIL ANLARIZ.

X ^ Y YAPARIZ. XOR BİTLER FARKLI İSE 1 DEĞİLSE 0 ÇEVİRİR.
ZIT İŞARETLİ OLMASI İÇİN EN SOLDAKİ BİTLER, BİRİNDE 1 DİĞERİNDE 0 OLMALI.
1....
0....  XOR
-----------
1
BU İŞLEMİN SONUCUNDA DA EN SOL TARAF 1 ÇIKTI YANİ NEGATİF BİR TAMSAYI ÇIKTI.
BU DURUMDA

IF((X ^ Y) < 0)
    İSE TERS İŞARETLİDİR. :)
ELSE
	AYNIDIR

==========================================================================
Bir sayının tek mi çift mi olduğunu anlamak için prtaik yol: 
if (n & 1)
    // tek
else
    // çift


    🧪 Örnekler
Sayı	Binary	n & 1	Sonuç
6	    110	    0	    Çift
7	    111	    1	    Tek
10	    1010	0	    Çift
11	    1011	1	    Tek
*/

void print_binary(const int a)
{
    for (int i = sizeof(a)*8-1;i>=0 ; i--)
    {
        printf("%d",(a>>i)&1);
    } 

}
int main()
{
    
    int a =-1;
    a<<=1;
    print_binary(a);
    printf("\n%d",a);
    printf("\n");
    a>>=3;//soldan hep 1 geliyor signed olduğu için.
    print_binary(a);
    printf("\n%d",a);
    printf("\n");
    int x = (1 << 5);
    print_binary(x);



printf("\n\n\n\n\n");
    for(int i =0 ;i<10;i++;)
    {
        
        printf("%d\n",i);
        
    }
}