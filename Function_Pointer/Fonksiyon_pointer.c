#include<stdio.h>
/*
C dilinde adresler iki ayrı kategoriye ayrılır:
Nesne adresleri(Object pointers)
Fonksiyon adresleri(Function pointers)

Bir fonksiyonun adresi o fonksiyonun makine kodlarının yerleştiği bellek bloğunun adresi
olarak görülebilir. C dilinde bir fonksiyonun adresi fonksiyon göstericisi(fonksiyon pointer)
denen özel bir gösterici değişkende saklanabilir.

Bir fonksiyonun adresi başka bir fonksiyona argüman olarak gönderilebilir.

Bir fonksiyonun geri dönüş değeri bir fonksiyonun adresi olabilir.

Elemanları fonksiyon adresleri olan diziler oluşturulabilir.

Fonksiyon adresleri C ve C++ dillerinde en çok kullanılan araçlardan birisidir.


Bir fonksiyonun adresi:
&func veya func diye yazılabilir.

func -> function to pointer conversion yaparak implicit olarak fonksiyon adresine dönüştürür.

Bütün fonksiyon adresleri aynı değil.
türü, parametrik yapısı ..... her şey önemli.


int (*fp)(int, int);

Anlamı:

    fp → bir pointer

    Gösterdiği şey → parametreleri (int, int) olan

    Geri dönüş tipi → int olan bir fonksiyon

🔹 Atama

fp = topla;

veya

fp = &topla;

İkisi de aynıdır.


Fonksiyon pointer değişkenleri memory de aynı miktarda yer kaplar.

void (*fp)(void) = f1;
*fp demeke fp nin gösterdiği fonksiyon demektir bu. diğer pointer işlemleri gibi
(*fp)() fonksiyon bu şekilde de çağrılır.fonksiyon pointerı olduğu vurgusu için bu şekilde yapılabilir.
fp() bu şekilde de çağrılır.


🔹 Çağırma
int sonuc = fp(3, 4);


veya

int sonuc = (*fp)(3, 4);


Fonksiyon adresi argüman olarak gönderilebilir”

Bu çok çok önemli bir özellik.

Örnek: Hesaplama fonksiyonu
int topla(int a, int b) { return a + b; }
int carp(int a, int b) { return a * b; }

int hesapla(int (*f)(int, int), int x, int y) {
    return f(x, y);
}

int main() {
    printf("%d\n", hesapla(topla, 3, 4));
    printf("%d\n", hesapla(carp, 3, 4));
}


👉 Aynı fonksiyon (hesapla)
👉 Farklı davranış (topla / çarp)
=============================================================================


            Foksiyon Pointer Nasıl Tanımlanır?


geri_dönüş_tipi(*pointer adı)(parametreler);

orn: int (*fp)(int, int);
Anlamı:

fp → pointer

Gösterdiği şey → (int, int) parametreli

Geri dönüş tipi → int olan fonksiyon

📌 Parantez çok önemli
Bunu yazarsan ❌:

int *fp(int, int);  // bu fonksiyon bildirimi olur

🔹 4. Fonksiyon pointer’a NASIL ATANIR?
fp = topla;


veya

fp = &topla;


👉 İkisi tamamen aynıdır

🔹 5. Fonksiyon pointer NASIL KULLANILIR?
Çağırma 1 (önerilen)
int sonuc = fp(3, 4);

Çağırma 2 (daha açık)
int sonuc = (*fp)(3, 4);


İkisi de aynı.

🔹 6. Tam örnek (tanım + atama + kullanım)
#include <stdio.h>

int topla(int a, int b) {
    return a + b;
}

int main() {
    int (*fp)(int, int);

    fp = topla;

    printf("%d\n", fp(5, 7));  // 12
    return 0;
}

🔹 7. Birden fazla fonksiyonla kullanma
int topla(int a, int b) { return a + b; }
int carp(int a, int b)  { return a * b; }

int main() {
    int (*fp)(int, int);

    fp = topla;
    printf("%d\n", fp(2, 3));  // 5

    fp = carp;
    printf("%d\n", fp(2, 3));  // 6
}


👉 Aynı pointer
👉 Farklı davranış

🔹 8. Fonksiyon pointer’ı parametre olarak gönderme (ÇOK ÖNEMLİ)
int hesapla(int (*f)(int, int), int x, int y) {
    return f(x, y);
}


Kullanım:

hesapla(topla, 3, 4);
hesapla(carp, 3, 4);


👉 Buna callback denir.

🔹 9. typedef ile okunabilir hale getirme (hayat kurtarır)
typedef int (*Islem)(int, int);

int hesapla(Islem f, int x, int y) {
    return f(x, y);
}


Artık karmaşa yok 👌

🔹 10. Fonksiyon pointer DİZİSİ
void f1() { printf("F1\n"); }
void f2() { printf("F2\n"); }
void f3() { printf("F3\n"); }

int main() {
    void (*funcs[])(void) = { f1, f2, f3 };

    funcs[0]();
    funcs[1]();
    funcs[2]();
}


👉 Menü
👉 State machine
👉 Oyun logic

🔹 11. Fonksiyon pointer döndüren fonksiyon
int topla(int a, int b) { return a + b; }
int carp(int a, int b)  { return a * b; }

typedef int (*Op)(int, int);

Op sec(int secim) {
    if (secim == 0)
        return topla;
    return carp;
}

🔹 12. Yaygın hatalar 🚨
❌ Parantez unutmak
int *f(int, int); // yanlış

❌ Yanlış imza
void (*f)(int);
f = topla; // uymaz

❌ Pointer sanıp fonksiyon çağırmamak
fp; // hiçbir şey yapmaz

*/

/*

Biz burada fonksiyon pointer ı oluşturduk çünkü topla ve carp fonksiyonlarının adreslerini
hesapla adresine parametre olarak vermek istiyoruz. Bu sayede 1 fonksiyon birden fazla
islemi yapabilir.



FUNCTION POINTER ARRAYS
	-----------------------

	int *p[10] demek int *ptr den 10 tane var demek.

	Bunu uyarlarsak

	int (*fptr[10])(int);  typedef ile de tanımlanabilir bu daha kısa olur hatta.

	#define		SIZE		100


	int f1(int x)
	{
		printf("f1 cagrildi x = %d\n", x);
		return x * x;
	}

	int f2(int x)
	{
		printf("f1 cagrildi x = %d\n", x);
		return x * x;
	}

	int f3(int x)
	{
		printf("f1 cagrildi x = %d\n", x);
		return x * x;
	}


	int main()
	{

		int (*fpa[3])(int) = { &f1,&f2,&f3 }; // {f1,f2,f3}; şeklinde de yazılabilir.
	
		for (int i = 0; i < 3; i++)
		{
			int val = fpa[i](i);
			printf("val = %d\n",val);
		}

	}


*/
int hesapla(int (*f)(int , int),int x, int y)
{
    return f(x,y);

}
int topla(int a, int b) {
    return a + b;
}
int carp(int a, int b)
{
    return a*b;
}
int main()
{
    //printf("%p",topla);

    int (*pfunc)(int , int)= topla; /*
    int (*pfunc)(int , int)= &topla; 
    bu şekilde de kullanılabilir.

    bu şekilde kullanımda *func fonksiyonu artık her cağrıldığında aslında topla 
    fonksiyonunu adresini döndürecek.
    */

    int a = hesapla(*pfunc,3,5);
    /*
        int a = hesapla(*pfunc,3,5);
        int a = hesapla(pfunc,3,5);
        int a = hesapla(topla,3,5);
        int a = hesapla(carp,3,5);
        bu 4 şekilde de kullanılabilir.
    */
    printf("a degeri : %d\n",a);

    int b =hesapla(*pfunc,3,5);
    printf("b degeri : %d\n",b);


}