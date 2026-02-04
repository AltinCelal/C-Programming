#include<stdio.h>
/*
Adres tutarlar.
 int *ptr;
 int* ptr;
 int * ptr;
yukarıdaki üçüde aynı şey.

adres türlerinin hepsi aynı boyutta yer kaplar.
int *
double *
char * 
sizeof(int *) sizeof(double *) sizef(char *) sizeof(short *) hepsi aynı değeri verir.

Bir pointer global(dolayısıyla static) olabilir.
otomatik ömürlü local olabilir.
Statik ömürlü local olabilir.
fonksiyonun parametre değişkeni de olabilir.
.............


int *ptr = &x;
 kullanımı bu şekilde.

-------BURASI ÖNEMLİ-------
 şimdi int *ptr; diye bir tanımlama yaptık.
 burada ptr nin türü int* (int değil int* türünde)

 yani int *ptr;
 *ptr = &x; diyemeyiz.

 pointer operatörleri:

 & => adress off operator.
 * => dereferencing / indirection operator
[] => suscript/index operator
-> => member selection


C DE HER İFADE 2 ROLDEN BİRİNE GİRER.

l value = Bellekte bir yeri var, adersi alınabilir, atanabilir ve genelde solda yer alır.
int x = 10;
x = 20;    x bir l value.

r value = Geçici bir değerdir, bellekte bir yeri olmak zorunda değildir.Genelde sadece okunur.

10               // r-value
x + 5            // r-value
&x               // r-value (adres değeri)

NOT:C/C++ ta hayata gelmiş nesnelerin adreslerinin değişmesi gibi bir kavram yok.


int x = 10;
int *ptr = &x ;

&x -> x in adresidir.
ptr -> x in adresini tutuyor.
&ptr -> bu ptr nin adresi.



NOT: 
Bir dizinin ismi kullanıldığında , 2 case dışında bu isim dizinin ilk elemanının adresine dönüştürülüyor.
Buna Array decay yada array to pointer conversion deniliyor.

a nın array decay olarak kullanılmadığı bir yer var.
sizeof un içinde kullanıldığnda array decay olarak işlem görmüyor.
printf("sizeof(a) = %zu",sizeof(a));// bu dizinin tamamının tutulduğu alanı verir. 

yani a ile &a[0] aynı şey.



int a[5] = {0}
	int b[10] = {0}

	int *pa = a;
	int *pb = b;  pointera dizilerin ilk eleman adresleri verilmiş.
	bu tip örnekler çok



    *&x = 45; bu ifade doğru
    x = 45; ile aynı.

    int a [] = {7,24,45};
    *a = 44;
    a[0] = 44; ile aynı ifade. Array decaydan geliyor.

    int x = 10;
    int* p =&x;
    p = burası adres olmalı
    *p = burası x e atanabilen bir değer olmalı.
    
    C de eğer bir yerel değişkenin başka bir foksiyon tarafından değiştirilmesini 
    istiyorsak bu değişkenin kendisini fonksiyona göndermemiz gerekiyor.
    
    
    void func(int *ptr)
    {
        *ptr = 100;
    }

    int main()
    {
        int x = 20;
        func(&x);
        printf("x = %d",x);
    }
    burada x 100 görülür. Call by reference.



    ---------------------CONST--------------------------------------
    değerinin değişmemesini istediğimiz değişkenlerde kullanılır.
    int const a ile const int a aynıdır.


    eğer değişmemesi gereken bir veri varsa bunu const ile koruruz.


    int x = 10;
    int y = 20;
    int * const ptr = &x;
    const pointer to int şeklinde ifade ediliyor.
    Burada ptr nin değeri değişmez yani ptr hayatı boyunca hep x i işaret eder.
    *ptr değişebilir yani *ptr = 25; olabilir( yani x değişiyor) burada sorun yok.
    ama ptr = 0x123A..... hata.

    *ptr = y;//hata değil.    
    ptr = &y ;//hatadır.


    const int * ptr = &x; veya int const *ptr = &x; ikiside aynı.
    önemli olan * dan önce veya sonra olması.
    burada ptr nin tuttuğu deger değişebilir.
    ptr = &y; olabilir.
     ama *ptr yani gösterdiği adresdeki deger değişemez.
     *ptr = y; bu hatadır.



    const int * const ptr = &x; burada hiçbir şey değiştirilemez.


    void func (int *ptr) burada const olmadığı için bu bir set fonksiyonu.

    void fun( const int *ptr) burada const olduğu için bu bir get fonksiyonu. 



    -----------POİNTER ARİTMETİĞİ--------------------

    pointerlara sayı ekleyip çıkarabilirsin.
    byte byte değil tür tür ilerler.
    int *p;
    p = p+1; bu p tane ileri gitmez bir integer ileri gider.
    
    p + 1 = p + 1 *(sizeof(*p)) gibi düşün.
    dizilerde bu mantık var zaten hatırla diziler ilk elemanın adresini verirdi.
    p+1 == &a[1] demek aslında.
    yani
    *(p+2) == a[2];
    
    iki pointer çıkarılabilir.



    DİKKAT
    pointerlar çarpılamaz toplanamaz bölünemez!
    aşağıda pointerla alakalı örnek var takılırsan incele.(kod kısmında)
    


    Subscript operatörü []
    -> bir dizinin elemanına erişmek için kullanılır.
    arr[3] dizinin 3. indeksindeki eleman.
    a[b] = *(a+b) demek aslında
    arr[3] = *(arr+3);

    aslında 3[arr] de yazılabilir aynı sonucu verir ama tercih edilmez.

    fonksiyon parametrelerini başka bir fonksiyona arguman olarak göndermek mantıklı.

    void print_sum(int a, int b)
    {
        printf("Toplam = %d\n", a + b);
    }

    void foo(int x, int y)
    {
        // foo'nun parametrelerini başka fonksiyona gönderiyoruz
        print_sum(x, y);
    }

    int main()
    {
       foo(10, 20);
    }

    bir fonksiyonun parametrelerinin pointer olduğunu göstermenin 2 yolu var.
    birincisi * notasyonu
    Onrek: func(int *p)

    ikincisi [] notasyonu
    ornek: func(int p[])
    Buradaki p bir pointer bir dizi değil Dizi görüntüsünde ama değil.
    köşeli parantezin içine rakam girilmesi önemsiz.
    Ornek: func(int p[10]) burası anlamsız.Sentaks hatası değil ama 10 elemanlı 
    dizi anlamına da gelmiyor.


    func(int p[]) = func(int *p)
    tekrar söylüyorum p[] burada pointer olduğunu gösteriyor,dizi değil.


    ilk değer verilmemiş atama yapılmamış pointer değişken geçersizdir.



    ----------DANGLING POINTER-----------
    Artık geçerli bir nesneyi göstermeyen pointerdir.
    yani:
    Eskiden doğru bir adresi gösteriyordu
    Ama artık o nesne öldü/serbest bırakıldı/scope tan çıkarıldı
    pointer hala o eski adresi tutuyor.
    onu kullanırsak -> UB


    int* foo(void)
    {
        int x = 42;     // stack'te
        return &x;     // ❌ x ölünce pointer dangling olur
    }

    int main()
    {
        int *p = foo();   // p artık dangling
        printf("%d\n", *p);  // ❌ UB
    }

    int *p = malloc(sizeof(int));
    *p = 123;

    free(p);     // bellek serbest
    printf("%d\n", *p);   // ❌ UB → dangling pointer kullanımı


    Dereferencing: Bir pointerın gösterdiği adrese girip oradaki gerçek dereğeri okumak
    yada yazmak demektir.


    ---------------POINTERLAR VE KARSILASTIRMA ISLEMLERI-------------------
    int *p1;
    int *p2;

    p1 == p2
    p1 != p2

    p1 < p2
    p1 <= p2
    p1 > p2
    p1 >= p2
    --------------------------------------
    1- iki pointer da aynı nesneyi gösteriyorsa eşit

    int x = 10 ,y = 20; 
    int *p1 =&x;
    int *p2 = &y;

	if(p1 == p2)
	{
		printf("Evet Eşit\n");
	}
	else
		printf("eşit değil\n")   Eşit değil sonucu verecek.

	p1 = &y; yaparsak sonuç eşit çıkar.
	p1 = p2 işte aynı şey.



    2- İki pointerda aynı dizinin bittiği yerin adresini tutarsa yine eşittir.

	NOT: Bittiği yerin adresi önemli. Bittiği yerin adresinden bir sonrası geçersiz.
	Bu önemli.

	int x[10] = {0};
	int *p = x+9;
	int *q = x[10];
	
	bunlar eşit değil

	p++;

	artık eşitler. if p == q ile bakılarak bulunur.

    -----------Function return pointers----------------
    Fonksiyon geri dönüş degeri olarak adres verir.
    Burada kullanım şekli çok önemli!!Aman dikkat

    stacta oluşturulan bir pointer gönderilirse fonksiyondan çıktıktan sonra 
    pointerın gösterdiği deger serberst kalacağı için dönen adres artık geçersiz!!!
    Kullanımı UB.

        int* create_int(void)
    {
        int *p = malloc(sizeof(int));  // heap'te yer ayır
        if(p != NULL)
            *p = 42;

        return p;   // ✔ hâlâ hayatta olan adres
    }

    int main()
    {
        int *x = create_int();

        printf("%d\n", *x);  // 42

        free(x);   // unutma!
    }
    doğru örneklerden birisidir.Heapta oluşturuldu.Fonksiyon bitse bile bellekte duruyor.


    int* foo(void)
    {
        static int x = 100;  // static lifetime
        return &x;          // ✔ program bitene kadar yaşar
    }

    int main()
    {
        int *p = foo();
        printf("%d\n", *p);  // 100
    }

    Bu da doğru örneklerden birisi. Program bitene kadar fonksiyondan çıksa bile bellekte
    kalmaya devam eder.




    !!!!!!!!!!
    int* bad(void)
    {
        int x = 42;     // stack'te
        return &x;     // ❌ x ölünce pointer dangling olur
    }

    int main()
    {
        int *p = bad();
        printf("%d\n", *p);  // ❌ UB
    }

    Bu yanlış örnek. Program bitince pointerın gösterdiği adres de boşa düşer UB.


    C nin kuralları
     int * ---------> const int *a dönüşümü doğru kabul edilir sorun yok
     const int * -------> int * a dönüşümü c++ da sentaks hatası c de uyarı.Burada const u deldik.
     
     int x; 
     int y = 23;
     const int *p = &x; burada sorun yok cünkü x nesnesinin türü int * sadece sınırlama getiriyoruz.
     kopyaladığı nesne ise const int *



    NULL
    Null bir makrodur. Adres sabitidir.null pointer pointer değişkenlere ilk deger verme veya
    atama yapmak için kullanılır.Pointer olmayan değişkenlere NULL pointer ile atama yapmak
    yada ilk deger vermek yanlıştır yapılmamalıdır.
    int x = NULL; bu yanlıştır.Yapılmamalıdır.
		
		Ancak herhangibir türden pointer değişkene NULL pointer ile atama veya 
		ilk değer verme yapılabilir.

		int *ptr = NULL; Geçerli
		double *dptr;
		dptr = NULL; Geçerli

        Static ömürlü bir pointer değişkeni bir değer vermeden tanımlarsak bu değişken 
        hayata NULL pointer değerle başlar.


        null pointer a önce geçerli bir adres atanmalı ondan sonra değer atanmalı yoksa UB

        int *p = NULL;
        *p = 10;   // ❌ UB (null dereference)
        null pointer hiçbir nesneyi göstermez oraya yazmakta okumakta tanımsız davranış






        int *p = NULL;

        p = malloc(10 * sizeof(int));  // bellek ayırma deneniyor

        *p = 5;   // ❌ UB (malloc NULL döndürmüş olabilir)
        malloc başarısız olursa null döner bunu kontrol etmedem dereference etmemeli!



        int x = 42;
        int *p = NULL;

        p = &x;   // ✔ artık geçerli bir adres

        *p = 100; // ✔ x = 100
        Bu doğru bir kullanım. x hayatta p artık x i gösteriyor dereference güvenli. 

    
    

    int *p = NULL;

    p = malloc(10 * sizeof(int));
    if (p == NULL)
    {
        // bellek ayrılamadı
        return 1;
    }

    p[0] = 10;   // ✔ güvenli
    p[1] = 20;

    Bu kullanımda güvenli malloctan sonra kontrol edildi artık geçerli bir adres gösteriyor.




    int x = 5;

    int *foo(int *p)
    {
        return p;
    }

    int main(void)
    {
        int *ptr = NULL;

        ptr = foo(&x);   // ✔ x hayatta
        *ptr = 99;      // ✔ x = 99
}
    Bu da güvenli fonksiyondan bir adres alıyor daha sonra dereference ediyor.


    int *foo(void)
    {
        int x = 10;   // stack
        return &x;    // ❌ dangling
    }

    int main(void)
    {
        int *p = NULL;
        p = foo();    // ❌ p artık dangling

        *p = 5;       // ❌ UB
    }
    Bu hatalı çünkü dönen adres artık hayatta değil DANGLING 


    ------- one past the end---------
    Bir dizinin son elemanından 1 sonraki adresi gösteren pointer.
    Bu adres hesaplanabilir saklanabilir karşılaştırılabilri ama
    asla dereference edilemez.


    int arr[3] = {10, 20, 30};

    int *p0 = &arr[0];   // OK
    int *p1 = &arr[1];   // OK
    int *p2 = &arr[2];   // OK
    int *p3 = &arr[3];   // one-past-the-end ✔
    fakat 
    printf("%d\n", *p3);   // ❌ UB bu yasak

    C standartı der ki:
    Bir dizinin elemanlarını dolaşabilmek için dizinin hemen sonrasını gösteren pointer
    özel olarak izinlidir.
    int arr[3] = {1,2,3};
    int *p = &arr[3];      // one-past-the-end ✔

 
    DEREFERENCE : Bir adresin işaret ettiği nesneye erişmek.

    
    
    
    
    ------------------------------------30_11_2_2021------------------------------------------------
C de bir fonksiyon işini yapmazsa Null pointer return edebilir.
Malloc mesela başarılı olursa bir dinamik bellek adresi, başarısız oluesa NULL ptr döner.
ya da
f = fopen("ahmet.txt","r");
		if(f == NULL)
			printf("dosya acilamadi\n");
			return 1;


----------------------------- Typedef---------------------------
Var olan türe yeni bir isim vermek. Tür değişmez sadece ona başka bir ad kazandırır.
->Okunabilirlik
-> Taşınabilirlik
->karmaşık türleri basitleştirme.

typedef <mevcut tür> <yeni isim>;


typedef int Word;
artık Work kullandığımızda Word un int türünden bir eş ismi olarak görecek.
Word x; 
int x; ile aynı anlama gelir.

Word func(Word);
int main()
{
    Word x,y,z; Türü kullanabileceğim her yerde türdeş ismini de kullanabilirim.
}


typedef int * IPTR;
int main()
{
    IPTR p = NULL;
    int *p = NULL; bunların arasında hiç bir fark yok.
}

#define ile arasındaki fark: 

#define  IPTR   int *

IPTR p; -> int *p; demek tamam burası ok.

IPTR p1,p2; demek int *p1; int p2; ikisi de pointer değil !!!!!!!!!!!

typedef int* IPTR; 
IPTR p1,p2; demek int *p1; int *p2; demek ikisi de pointer.


KURAL!!!

		hangi türe eş isim vermek istiyorsak 3 aşamada yapacağız bunu

		1 - o türden bir değişken tanımla
			int x;

		2 - tanımlamanın başına typedef getir
			typedef int x;

		3 - Değişken ismini tür eş ismi olarak değiştir.
			typedef int Word;


		mesela
		int a[10];

		typedef int a[10]  ->   typedef int ARR[10];  

		ARR a,b,c; artık aynı şey. 
		int	a[10],b[10],c[10]; aynısı.

		ÖNEMLİ
		Mülakat sorusu bu.

		typedef int Word,*Ptr;
		typedef int word; ve typedef int *Ptr; ile aynı


*/
void func(int *ptr)
    {
        *ptr = 100;
    }
int main()
{
    int a[] = {5,3,7};
	int *ptr = a;

	//hepsi aynı çıktıyı verir
	printf("a   = %p\n",a);
	printf("&a[0]   = %p\n",&a[0]);
	printf("ptr   = %p\n",ptr);


    printf("\n\n\n\n\n\n");

    int x = 10;
    int *p = &x;
    printf("*p degeri : %d\n",*p);
    printf("p degeri : %p\n",p);
    // pointerı yazdırmak için %p ile yazdırılır.

    int z = 20;
    func(&z);
    printf("x degeri : = %d",z);

    int k = 15;

    *&k =45;
    printf("k degeri : %d",k);

    int arr[] = {10,20,30,40,50,60,70,80,90};

    int *prt_arr = arr;

    printf("\n *ptr_arr degeri :%d\n",*prt_arr);
    printf("arr adresi :%p\n",arr);
    printf("ptr_arr degeri : %p\n",prt_arr);


    /*
    prt_arr arr ın adresini tutar.
    *prt_arr o adresteki degeri tutar.
    */
    prt_arr ++;
    printf("\n *ptr_arr degeri(prt_arr ++;) :%d\n",*prt_arr);

}