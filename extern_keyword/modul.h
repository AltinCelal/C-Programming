
#ifndef MODUL_H

#define MODUL_H

extern int counter;/*static yazmazsan birden fazla dosyada aynı isimle tanımlı 
olduğu için hata!!multiple definition of `counter' hatası

static yazarsan eğer include edilmiş her source kodunda ayrı bir static int counter
oluşur adresleri ve değerleri hepsinde kendisine özeldir.

exter yazarsan başına ortak kullanılır.
Adresler ve değerler hepsinde aynı.
!!! ama bir tane source kodunda global şekilde int counter; diye bir tanımlama yapılmalı.!!!


*/
void artir1();
void feed();
/*
fonksiyonlar otomatik olarak extern şekilde gelir C de.
*/

#endif