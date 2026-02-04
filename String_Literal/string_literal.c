#include<stdio.h>
/*
String literalleri derleyicilerin oluşturduğu char ve static ömürlü dizilerdir.
Salt okuma amacıyla kullanılmalıdır.

String literalini asla değiştirme.C ve C++ da fark var.
C++ da bu bir const char dizisi C de ise char dizisi ama değiştirilmiyor.
C de de string literalini const char ile tanımlamak mantıklı
char *p ="Umut"; c++ da sentaks hatası C de geçerli ama değiştirmek UB.
C de de 
const char *p = "Umut"; mantıklı.


Statik ömürlü dizilerdir Programın başından sonuna kadar hayatta kalır.

1 - char str[] = "Burak";
2 - char *p = "Adnan";


1. olan diziye değer atama sentaksı.Her elemana değer atıyor. 
Dizi boyutu 6 string boyutu 5 ve elemanlar değişebilir.

2. burada "Adnan" string literalin indeksini p pointerına atıyoruz.
karakteri değiştimek UB.


*/
int main()
{


}