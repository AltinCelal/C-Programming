#include <stdio.h>

/*
    dizinin boyutunu belirtlen ifade sabit olmalı.
    (The expression that specifies the array size must be a constant.)

    bir fonksiyonun parametre değişkeni dizi olamaz.
    Dizi beslediğimizde aslında o dizinin ilk elemanının adresini göndermişizdir.
    (A function parameter cannot be an array.
    When we pass an array, we are actually passing the address of its first element.)


    bir fonksiyonun geri dönüş değeri array olamaz
    (A function’s return value cannot be an array.)
    
    otomatik ömürlü dizileri okumak hata UB
    int x[4]; burada başlatılmadığı için ilk değer yok

    static int X[4] bu program başlatılmadan oluşturulur ve otomatik 0 ile doldurulur.

    int X[4]={0}; tüm elemanlar 0 ile başlatılır.
    int x[4] = {1, 2, 3, 4}; şeklinde de başlatılabilir.
    
    #define SIZE 23
    int dizi[SIZE] -> geçerli.


    //int a[]; hata

    //int a[4]; bu da UB şans eseri 0 ile dolduruyor.otomatik ömürlü olduğu için.C 0 olacağını garanti etmez.

    //int a[4]; global olsaydı 0 ile dolduracaktı.

    //static int a[4]; bunun da 0 ile doldurulacağını garanti eder.

    int a[]={1,2,3,4};//geçerli



    --------------------------------------------------------------------------------------

    char c[10]; 10 tane char - bellekte ardışık 10 byte - her eleman 1 byte.

    c de string diye özel bir tür yok. string sonu '\0' ile biten char dizisi.


    char s[6] = "hello";
    Bellek:
    'h' 'e' 'l' 'l' 'o' '\0'

    char s[] = "merhaba";
    Derleyici:
    Boyutu otomatik hesaplar
    '\0' ekler

    char s1[] = "abc";
    değiştirilebilir.
    s1[0]='A'; yazılabilir

    char *s2  = "abc";
    değiştirlemez - read only
    s2[0]='A'; yazılamaz 

    char a[SIZE]; -> burada yazının sonundaki null character görmeden yazı uzunluğunu bilme şansı yok
    
    static char s[SIZE] = "Ali ata bak";
		puts(s); // dizinin tuttuğu yazıyı stdout a yazdırıyor.

    

    char türden diziye ilk değer verilebilir ama atama yapılamaz.

    char s[100] = "ali veli"; bu olur
    s = "burada yazi var"; burası sentaks hatası.
    

    char str[5] = "EMRAH"; bu UB bu örnek string literal sonuna otomatik '\0' ekler
    o yüzden boyutu 6 olmalı

    biz kendimiz char array oluşturacaksak sonuna kendimiz '\0' eklemeliyiz yoksa UB.
    */
   #define SIZE 15
int main()
{
    int a[4];
    
    for (int i = 0; i < 4; i++)
        printf("%d\n", a[i]);
    char s[] = "merhaba";
    printf("%zu",sizeof(s));

    static char k[SIZE] = "Ali ata bak";
		puts(k); // dizinin tuttuğu yazıyı stdout a yazdırıyor.



#include <errno.h>


    FILE *file = fopen("nonexistent_file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    fclose(file);
    return 0;


}