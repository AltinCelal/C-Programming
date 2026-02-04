#include<stdio.h>
#include "string.h"
/*
=====================GENERIC FUNCTIONS========================
Farklı veri tipleriyle çalışan tek bir fonksiyon yazma fikri.

C dilinde C++ taki template gibi doğrudan generic yapı yoktur. 
ama bazı yollarla generic davranış elde ederiz.


1- void* ile her türlü adres tutulabilir.
void swap(void *a, void *b, size_t size) {
    char temp[size];

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

2-Makro ile (C preprocessor)

Makrolar ile tipe özel fonksiyon üretilebilir:

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
====================================================================================
EK BİLGİ : TYPEDEF İLE MAKRO FARKI:
1️⃣ typedef nedir?

Derleyici seviyesinde çalışır

Gerçek bir tür takma adı oluşturur

Tip güvenlidir

Debug sırasında gerçek türü görebilirsin

typedef int MyInt;

MyInt x = 10;   // int gibi davranır


2️⃣ #define nedir?

Preprocessor seviyesinde çalışır

Sadece metin değiştirme yapar

Tip kavramı yoktur

Debug zor, hataya açıktır

#define MyInt int

MyInt x = 10;   // derleme öncesi: int x = 10;


özetle typedef gerçek bir tür takma adıdır, #define ise sadece metin değiştirmedir.
Bu yüzden türler içğin her zaman typedef kullanılır.

====================================================================================

memset: Bir bellek bloğundaki her byte ı verilen bir değerle dolduran fonksiyondur.

void *memset(void *ptr, int value, size_t num);

🧩 Parametreler tek tek
Parametre	Açıklama
ptr	Doldurulacak bellek adresi
value	Yazılacak değer (sadece 1 byte’ı kullanılır!)
num	Kaç byte doldurulacağı


⚙️ Nasıl çalışır?

memset:

ptr adresinden başlayarak

num byte boyunca

her byte’a (unsigned char)value yazar.

Yani:

memset(ptr, 0xAB, 4);


Şu byte dizisini yazar:

AB AB AB AB

❗ ÇOK KRİTİK DETAY: value sadece 1 byte’tır

Bu en önemli tuzaklardan biridir.

int x;
memset(&x, 1, sizeof(x));


Bu, x = 1 yapmaz ❌
Gerçekte yazılan:

01 01 01 01   (4 byte int için)


Yani:

x = 0x01010101 = 16843009

✅ Doğru ve yaygın kullanım örnekleri
1️⃣ Sıfırlama (en yaygın)
int arr[10];
memset(arr, 0, sizeof(arr));


Tüm byte’lar 0 → tüm int’ler 0 olur
(Bu kullanım güvenlidir)

2️⃣ Struct sıfırlama
struct Person {
    int id;
    float salary;
    char name[20];
};

struct Person p;
memset(&p, 0, sizeof(p));


Tüm alanlar 0 olur.

3️⃣ Char dizisi doldurma
char buffer[100];
memset(buffer, 'A', 100);


Buffer:

AAAAA....AAAA

❌ Tehlikeli / yanlış kullanım örnekleri
1️⃣ int dizisini 1 yapmak ❌
int arr[5];
memset(arr, 1, sizeof(arr));


Beklenen:

1 1 1 1 1


Gerçek:

16843009 16843009 16843009 16843009 16843009

2️⃣ Pointer ile yanlış boyut
int *p = malloc(10 * sizeof(int));
memset(p, 0, sizeof(p));   // ❌ sadece pointer boyutu kadar sıfırlar


Doğrusu:

memset(p, 0, 10 * sizeof(int));

3️⃣ Struct’ı her zaman güvenle doldurur mu?
struct A {
    int x;
    char *p;
};

struct A a;
memset(&a, 0, sizeof(a));


Bu:

x = 0 yapar

p = NULL yapar (çoğu platformda)

Ama C standardı NULL = 0 garantisini pointer için vermez.
Yani teknik olarak portable değildir, ama pratikte yaygındır.

====================================================================================
memcpy: Bir bellek bloğundaki byteları başka bir bellek bloğuna kopyalayan fonksiyondur.

🔧 Fonksiyon prototipi
void *memcpy(void *dest, const void *src, size_t num);

🧩 Parametreler tek tek
Parametre	Açıklama
dest :	Kopyalamanın yapılacağı hedef bellek adresi
src  :  Kaynak bellek adresi
num  :	Kaç byte kopyalanacağı

✅ Doğru ve yaygın kullanım örnekleri
1️⃣ Dizi kopyalama
int a[5] = {1, 2, 3, 4, 5};
int b[5];

memcpy(b, a, sizeof(a));

2️⃣ Struct kopyalama
struct Person {
    int id;
    char name[20];
};

struct Person p1 = {1, "Ali"};
struct Person p2;

memcpy(&p2, &p1, sizeof(p1));

3️⃣ Char buffer kopyalama
char src[] = "Hello";
char dest[10];

memcpy(dest, src, strlen(src) + 1); // '\0' dahil

❌ Tehlikeli / yanlış kullanım örnekleri
1️⃣ Yanlış byte sayısı
int a[10];
int b[10];

memcpy(b, a, 10);   // ❌ sadece 10 byte kopyalar


Doğrusu:

memcpy(b, a, 10 * sizeof(int));

2️⃣ Pointer boyutunu kopyalamak
int *p = malloc(10 * sizeof(int));
int *q = malloc(10 * sizeof(int));

memcpy(q, p, sizeof(p));  // ❌ sadece 8 veya 4 byte


Doğrusu:

memcpy(q, p, 10 * sizeof(int));

3️⃣ Overlapping bellek
memcpy(arr + 1, arr, 5);  // ❌ tanımsız davranış


Bunun için:

memmove(arr + 1, arr, 5); // ✅

===============================================================================
memmove, bir bellek bloğundaki byte’ları başka bir bellek bloğuna kopyalar
ve bunu çakışan (overlapping) bellek bölgelerinde bile güvenli şekilde yapar.

📚 Hangi kütüphanede?
#include <string.h>


memmove, string.h içinde tanımlıdır.

🔧 Fonksiyon prototipi
void *memmove(void *dest, const void *src, size_t num);

🧩 Parametreler tek tek
Parametre	Açıklama
dest	Hedef bellek adresi
src	Kaynak bellek adresi
num	Kaç byte kopyalanacağı
⚙️ Nasıl çalışır?

memmove:

src → dest yönünde num byte kopyalar

Ama önce şunu kontrol eder:

Kaynak ve hedef bellek bölgeleri çakışıyor mu?

Eğer çakışma varsa:

Kopyalama yönünü değiştirir

Geçici bir tampon (veya ters yönde kopya) kullanır

Böylece veri ezilmez.

❗ En kritik fark: memcpy vs memmove
Özellik	memcpy	memmove
Overlapping bellek	❌ Tanımsız davranış	✅ Güvenli
Hız	Biraz daha hızlı	Biraz daha yavaş
Kullanım	Genel kopya	Çakışan bellek
✅ Doğru ve yaygın kullanım örnekleri
1️⃣ Overlapping bellek kopyalama
#include <stdio.h>
#include <string.h>

int main() {
    char buf[] = "abcdef";

    memmove(buf + 2, buf, 4);
    printf("%s\n", buf);  // ababcd

    return 0;
}


Burada:

src = buf

dest = buf + 2

Bölgeler çakışıyor

memcpy olsaydı sonuç tanımsız olurdu.

2️⃣ Dizi içi kaydırma
int arr[] = {1, 2, 3, 4, 5};

// Diziyi 1 sağa kaydır
memmove(arr + 1, arr, 4 * sizeof(int));


Sonuç:
arr = {1, 1, 2, 3, 4}


3️⃣ Güvenli buffer kopyalama
char buffer[20] = "HelloWorld";

// Aynı buffer içinde sola kaydırma
memmove(buffer, buffer + 5, 5);
buffer[5] = '\0';

printf("%s\n", buffer);  // World

❌ Yanlış / gereksiz kullanım
1️⃣ Overlap yokken memmove kullanmak
memmove(dest, src, size);  // çalışır ama yavaş


Overlap yoksa:

memcpy daha hızlıdır

Performans kritik kodda memcpy tercih edilir.

🧠 Ne zaman memmove kullanmalısın?
Senaryo	Doğru fonksiyon
Bellek bölgeleri çakışabilir	memmove
Overlap yok, saf kopya	memcpy
Aynı dizi içinde kaydırma	memmove
Güvenli genel kopya	memmove
==============================================================================0
memchr, bir bellek bloğu içinde belirli bir byte değerini arayan fonksiyondur.

String fonksiyonları gibi '\0' görünce durmaz.
Verilen byte sayısı kadar arar.

📚 Hangi kütüphanede?
#include <string.h>


memchr, string.h içinde tanımlıdır.

🔧 Fonksiyon prototipi
void *memchr(const void *ptr, int value, size_t num);

🧩 Parametreler tek tek
Parametre	Açıklama
ptr	Aranacak bellek bloğunun başlangıç adresi
value	Aranan byte değeri (sadece 1 byte kullanılır!)
num	Kaç byte içinde arama yapılacağı
⚙️ Nasıl çalışır?

memchr:

ptr adresinden başlar

num byte boyunca ilerler

Her byte’ı (unsigned char)value ile karşılaştırır

İlk eşleşmede durur

O byte’ın adresini döner

Bulamazsa:

return NULL;

❗ ÇOK KRİTİK DETAY: value sadece 1 byte’tır
int x = 0x12345678;

memchr(&x, 0x12345678, sizeof(x)); // ❌ anlamsız
memchr(&x, 0x78, sizeof(x));       // ✅ doğru


Çünkü sadece:

(unsigned char)value


kullanılır.

✅ Doğru ve yaygın kullanım örnekleri
1️⃣ Char dizisinde arama
#include <stdio.h>
#include <string.h>

int main() {
    char buf[] = "Hello World";

    char *p = memchr(buf, 'W', sizeof(buf));

    if (p != NULL) {
        printf("Bulundu: %c, index = %ld\n", *p, p - buf);
    }

    return 0;
}

2️⃣ Binary veride arama
unsigned char data[] = {0x10, 0x20, 0xFF, 0x30};

unsigned char *p = memchr(data, 0xFF, sizeof(data));

if (p != NULL) {
    printf("0xFF bulundu, index = %ld\n", p - data);
}

3️⃣ '\0' aramak
char buf[] = {'A', 'B', '\0', 'C', 'D'};

char *p = memchr(buf, '\0', sizeof(buf));

if (p != NULL) {
    printf("Null byte bulundu, index = %ld\n", p - buf);
}


strchr bunu yapamaz çünkü '\0'’dan sonra durur.

❌ Tehlikeli / yanlış kullanım örnekleri
1️⃣ Yanlış byte sayısı
char *p = memchr(buf, 'A', strlen(buf));  // ❌ '\0' aranmaz


Doğrusu:

char *p = memchr(buf, 'A', strlen(buf) + 1);

2️⃣ Struct içinde arama
struct S {
    int x;
    char c;
};

struct S s;

memchr(&s, 0, sizeof(s));  // ⚠️ padding byte’ları da arar


Struct’larda:

Padding byte’ları vardır

Sonuç beklenmedik olabilir
=========================================================================

📌 memcmp nedir?

memcmp, iki bellek bloğunu byte byte karşılaştıran fonksiyondur.

String fonksiyonları gibi '\0' görünce durmaz.
Verilen byte sayısı kadar karşılaştırır.

📚 Hangi kütüphanede?
#include <string.h>


memcmp, string.h içinde tanımlıdır.

🔧 Fonksiyon prototipi
int memcmp(const void *ptr1, const void *ptr2, size_t num);

🧩 Parametreler tek tek
Parametre	Açıklama
ptr1	1. bellek bloğunun başlangıç adresi
ptr2	2. bellek bloğunun başlangıç adresi
num	Kaç byte karşılaştırılacağı
⚙️ Nasıl çalışır?

memcmp:

ptr1 ve ptr2’den başlar

num byte boyunca ilerler

Her byte’ı (unsigned char) olarak karşılaştırır

İlk farklı byte’ta durur

Döndürdüğü değer:

< 0   → ptr1 < ptr2
= 0   → ptr1 == ptr2
> 0   → ptr1 > ptr2


Bu işaret, ilk farklı byte’ın farkına göredir.

❗ ÇOK KRİTİK DETAY: Sıralama garantisi yok

Birçok kişi şunu sanır:

"memcmp ile sayıları büyüklük/küçüklük olarak karşılaştırırım"

❌ Yanlış.

int a = 1;      // 01 00 00 00
int b = 256;    // 00 01 00 00

memcmp(&a, &b, sizeof(int)); // sonuca güvenme!


Endianness

İmzalı/unsigned

Byte sırası

yüzünden sonuç mantıksal büyüklüğü yansıtmayabilir.

✅ Doğru ve yaygın kullanım örnekleri
1️⃣ Byte dizisi karşılaştırma
unsigned char a[] = {0x10, 0x20, 0x30};
unsigned char b[] = {0x10, 0x20, 0x30};

if (memcmp(a, b, sizeof(a)) == 0) {
    printf("Aynı!\n");
}

2️⃣ Struct karşılaştırma (tehlikeli ama yaygın)
struct S {
    int x;
    char c;
};

struct S s1 = {10, 'A'};
struct S s2 = {10, 'A'};

if (memcmp(&s1, &s2, sizeof(s1)) == 0) {
    printf("Aynı!\n");
}


⚠️ Risk:

Padding byte’ları olabilir

Mantıksal olarak aynı ama byte olarak farklı olabilirler

3️⃣ String karşılaştırma (binary güvenli)
char a[] = {'A', 'B', '\0', 'C'};
char b[] = {'A', 'B', '\0', 'D'};

if (memcmp(a, b, 4) != 0) {
    printf("Farklı!\n");
}


strcmp burada durur, memcmp durmaz.

❌ Tehlikeli / yanlış kullanım örnekleri
1️⃣ Yanlış byte sayısı
memcmp(a, b, sizeof(a)); // a pointer ise ❌


Doğrusu:

memcmp(a, b, length);

2️⃣ Struct karşılaştırmasına güvenmek
memcmp(&s1, &s2, sizeof(s1)); // ⚠️ padding yüzünden yanlış sonuç

3️⃣ Sayıları karşılaştırmak
int a = 5, b = 10;
memcmp(&a, &b, sizeof(int));  // ❌ anlamsız karşılaştırma

🧠 memcmp ne zaman güvenlidir?
Senaryo	Güvenli mi?
Byte dizisi	✅
Binary veri	✅
Hash / imza karşılaştırma	✅
Struct (padding yoksa)	⚠️
Sayı büyüklüğü kıyaslama	❌

*/
int main()
{


}