#include<stdio.h>
/*
Endianness,
çok byte’lı bir verinin (int, long, double vs.) bellekte hangi sırayla saklandığını tanımlar.

👉 CPU byte sırasını nasıl yerleştiriyor?

2️⃣ NEDEN GEREKLİ?

Çünkü:

Bellek byte adreslidir

Ama:

int → 4 byte

long → 4 / 8 byte

double → 8 byte

👉 Bu byte’ların hangi sırayla dizileceği bir tercihtir.

3️⃣ ÖRNEK SAYI
int x = 0x12345678;


Bu sayı 4 byte:

Byte	Değer
En anlamlı byte (MSB)(most significant byte)	0x12
	0x34
	0x56
En anlamsız byte (LSB)	0x78

4️⃣ BIG ENDIAN

Mantıksal okunuş sırası ile bellekteki sıra AYNI

📌 MSB (en anlamlı byte) düşük adreste

Bellek görünümü:
Adres →   +0    +1    +2    +3
Değer →  0x12  0x34  0x56  0x78

Avantaj:

İnsan gibi okunur

Ağ protokolleri (network byte order) → BIG ENDIAN

5️⃣ LITTLE ENDIAN (EN YAYGIN)

📌 LSB (en anlamsız byte) düşük adreste

Bellek görünümü:
Adres →   +0    +1    +2    +3
Değer →  0x78  0x56  0x34  0x12

Neden böyle?

CPU aritmetiği daha hızlı

Intel, AMD, ARM (çoğu) → Little endian

1️⃣ LSB ve MSB NEDİR?

Bir sayının bit düzeyindeki önem sırasını anlatır.

🔹 LSB — Least Significant Bit / Byte

En az değer katkısı yapan bit / byte

Sayıyı 1 artıran bit

2⁰ ağırlığında

🔹 MSB — Most Significant Bit / Byte

En fazla değer katkısı yapan bit / byte

Sayının büyüklüğünü belirleyen taraf

En yüksek 2ⁿ ağırlığında

2️⃣ BİT DÜZEYİNDE ÖRNEK
Sayı: 13 (decimal)

Binary: 1101
         ↑  ↑
         |  |
        MSB LSB

Bit	Ağırlık
En sağ bit	2⁰ = 1 → LSB
En sol bit	2³ = 8 → MSB
3️⃣ BYTE DÜZEYİNDE (ÇOK ÖNEMLİ)
int x = 0x12345678;


Hex’i byte byte ayıralım:

0x12 | 0x34 | 0x56 | 0x78
 ↑                 ↑
 MSB               LSB

Byte	Anlam
0x12	MSB
0x78	LSB

👉 Bu sayının matematiksel değeriyle belirlenir
👉 Bellek yerleşimiyle değil

4️⃣ "NEYE GÖRE BELİRLENİR?"

📌 LSB / MSB, CPU’ya veya endianness’a göre değişmez

Kural:

Bir sayının sayısal değerine en az katkı yapan → LSB
En çok katkı yapan → MSB

5️⃣ ENDIANNESS BURADA DEVREYE GİRER

Endianness şunu sorar:

LSB mi önce belleğe yazılacak, MSB mi?

LITTLE ENDIAN
Adres:   +0    +1    +2    +3
Değer:  0x78  0x56  0x34  0x12
        ↑
       LSB

BIG ENDIAN
Adres:   +0    +1    +2    +3
Değer:  0x12  0x34  0x56  0x78
        ↑
       MSB

*/

void print_binary(const int x)
{
    for(int i = sizeof(x)*8-1; i>=0;i--)
    {
        printf("%d",(x>>i) & 1);
    }
    printf("\n");
}
int main()
{

    /*unsigned int x = 305419896; // 0x12345678

    printf("Decimal      : %u\n", x);
    printf("Hexadecimal  : %X\n", x);
    printf("Hex (lower)  : %x\n", x);

    return 0;
    int i = 1;

    char * c = (char*)&i;

    printf("%d\n",*c);*/

    char a='0';
    print_binary(a);
    /*
    burada implicit olarak bir dönüşüm gerçekleşti dar türler int e implicit olarak döner.
    */

    return 0;
}