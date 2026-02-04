#include<stdio.h>
#define DEBUG 1
#define MODE 2
int main()
{
    //Macros run before compilation (in the preprocessor).
    //Functions run at runtime. They have a call mechanism.
    //Macros are generic / type-independent, while functions are type-dependent.

//Macros operate on source code; therefore, they tend to increase the size of the resulting machine/executable code.
//Macrolar source kodu, dolayısıyla oluşan makina/exe kodu büyütme eğiliminde.

    //Functions are well supported by debuggers, while macros generally are not.

    //Macros are not safe; incorrect usage carries a very high risk of errors.
    //We cannot use macros where a function pointer is required, because macros do not have an address. Macros simply perform textual substitution.

    //We cannot use macros where a function pointer is required, because macros do not have an address. Macros simply perform textual substitution.
    //Function pointer gereken yerde macro kullanamayız.Çünkü macroların adresi yok. Macrolar yer değiştirme işi yapıyor zaten.


    /*
                                        CONDITIONAL COMPILATION
        “#if, #elif, #else, and #endif include code based on a condition
    

    */
   

#if DEBUG
    printf("Debug modu aktif\n");
#endif
//if debug is 1, the cod is compiled. 


#ifdef LOG
    printf("Loglama açık\n");
#endif
//The code is compiled when LOG macro is defined.

#ifndef RELEASE
    printf("Debug bilgileri\n");
#endif
//The code is compiled when a macro is undefined.



#if MODE == 1
    printf("Mod 1\n");
#elif MODE == 2
    printf("Mod 2\n");
#else
    printf("Bilinmeyen mod\n");
#endif

#ifdef _WIN32
    printf("Windows\n");
#elif __linux__
    printf("Linux\n");
#endif

printf("%d",__LINE__);


/*
#define komutu olmayan makrolar:
__LINE__	kodun hangi satırda oluduğunu verir
__FILE__	file adını
__DATE__	tarih
__TIME__	saati verir.
__func__   c99 da geldi. Bu tip daha macro var. fonksiyonun adını verir.
__STDC__	eğer derleyicinin eklentileri kapalıysa bu macro tanımlı kabul ediliyor.

*/
}
