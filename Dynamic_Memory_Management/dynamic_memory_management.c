#include<stdio.h>
#include<stdlib.h>
/*
Önce exit, atexit, abort fonksiyonunu göreceğiz.
Hepsi programı sonlandıran fonksiyon.

atexit exit ile kullanılan yardımcı bir fonksiyon.

void exit(int); -> programın hangi sebeple sonlandırılacağını ifade ediyor.
int yerine 0 verilirse program başarılı. işini yaptı.
nonzero ise başarısız.

Main içinde return statement derleyici tarafınfan exit çağrısına dönüştürülüyor.

exit(0)-> program işini yapmış başarılı şekilde sonlanmış, bu bilgiyi verir

exit(1) -> program başarısız, bu bilgiyi verir.

0 ve 1 yerine macro kullanılıyor.
stdlib.h de var bunlar.

#define         EXIT_SUCCESS        0
#define         EXIT_FAILURE        1

exit(0) -> exit(EXIT_SUCCESS)  aynı anlamda
exit(1) -> exit(EXIT_FAILURE)  aynı anlamda

void f3(void)
{
	printf("f3 cagrildi\n");
	exit(EXIT_FAILURE); // bu şekilde yapılınca buradan sonra process/program sonlandırılır.
        // bunu yapmanın 1-2 sebebi var.
        // 1. işini bitirmiştir ve bu yüzden sonlandırılır.EXIT_SUCCESS ile yapılır.
        // 2. başarısızlık durumunda çağrılır.
	printf("f3 Sona erdi\n");
}

void f2(void)
{
	printf("f2 cagrildi\n");
	f3();
	printf("f2 Sona erdi\n");
}
void f1(void)
{
	printf("f1 cagrildi\n");
	f2();
	printf("f1 Sona erdi\n");
}


program bilerek sonlandırılıyorsa 2 ayrı sonlandırma biçimi var.

1. normal termination = exit

2- abnormal termination = abort


exit in abort tan farkı abort hemen sonlandırır 
exit ise programı sonlandırmadan önce bazı işlemlerin yapılmasını garanti altına alınıyor.
mesela, yazma amaçlı kullanılan dosyaların bufferlarını flush edilmesi.

Dosya işlemlerinde dosyaya yazma işlemi yapan fonksiyon aslında dosyaya yazmıyor , bu dosya
için memory de ayrılmış bir buffer a yazıyor. Belirli bir event oluşunca bellek bloğundaki
byte ların hepsi dosyaya yazılıyor.
Buna bufferın flush edilmesi deniliyor.


int atexit(void (*fp)(void)); geri dönüş değeri olmayan parametresi olmayan fonksiyon adresi alıyor.
atexit bunu global bir fonksiyon pointerı dizisine yazıyor.
geri dönüş değeri başarı bilgisi.

exit çağrıldığında, atexit ile kaydedilmiş fonksiyonlar ters sırada çağrılacak.

Programın normal şekilde sonlandığında çalışacak fonksiyonları kaydeder.

çalışma koşulları:

1- main fonksiyonu return ile biterse 

2-program exit() ile sonlandırılırsa

!!!!!!
abort() ile program biterse çalışmaz 

program sinyal ile bitirilirse çalışmaz 

_exit() veya _Exit() ile sonlandırılırsa (low-level çıkışlardır.)

LIFO mnatığı ile çalışır yani 
atexit(f1);
atexit(f2);
atexit(f3);

ile çağrılırsa 
f3-> f2 -> f1 şeklinde çalışır.

parametre almaz fonksiyonun adresi gönderilir ve retun değeri olmaz. 

Bunların yapılma sebebi veri kaybını engeller.

db bağlantısı kapatılması, file ların flush edilmesi, hataya  ilişkin logların yazılması.
bunları unutabilirz ya da ihmal edebiliriz.Bunlar için kullanılıyor.

atexit, program normal şekilde sonlanırken çalıştırılacak fonksiyonları kaydeder.

main fonksiyonundan yapılan return, standart gereği exit(return_değeri) ile aynıdır.

C99’dan sonra main içinde return 0; yazmasan bile, derleyici bunu return 0; gibi kabul eder.

============================================================================
============================================================================

ABORT

void abort(void)
abnormal termination.

abort eğer programı sonlandırırsa kendisi uyarı mesajı veriyor.
Abort olduğu belli oluyor.

exit(EXIT_FAILURE) ; örneğini abort içinde yapabiliriz.

void asd(const int *p)
{
	if(p == NULL) // bu şekilde yazılan kodlara assertion denir. runtime de olunca bu kontrol dynamic assertion denir
	{				// çünkü NULL ptr dereference etmek UB oluşturur.bu hatayı alır almaz abort ile pat diye sonlandırması için.
		printf("hata\n"); // ileride görülecek assert macrosu kullanılacak. zaten geri planda o da abort u çağırıyor.
		abort();			// assert(p != NULL) ile kullanılır    1:01
	}
    while(*p)
	{
		++p;
	}

}

=======================================================================================================
=======================================================================================================


DİNAMİC BELLEK YÖNETİMİ
DYNAMİC MEMORY MANAGEMENT

STATIC -> BU ÇEVİRİ SÜRECİNE AİT DEMEKTİR.
DYNAMIC -> BU KAVRAM İSE PROGRAMIN ÇALIŞMA ZAMANINA AİT DEMEK.

STATIC ASSERTİON -> DOĞRULAMANIN COMPİLE TİME DA
DYNAMIC ASSERTİON -> DOĞRULAMANIN RUNTİME DA YAPILDIĞINI GÖSTERİR.

STATIC/DYNAMIC BINDING c++ ta kullanılır
fonksionun çağrılması durumunda hangi fonksiyonun çağrıldığı compile time da belirleniyorsa static,
runtime da belirleniyorsa dynamic binding denir.

STATIC/DYNAMIC TYPING
Verinin ne olduğu hangi formatta olduğu compile time çeviri sürecinde anlaşılıyorsa buna static tür kavramı C/C++,
verinin ne olduğu runtime da anlaşılıyorsa buna dynamic typing deniyor. ör : python powershell

------------------------------------------------------------------------------------------------

static memory managementta,değişkenlerin storage larını derleyici çeviri sürecinde ayarlıyor.
dynamic memory managementta, bir nesnenin bellek alanı/storage ı runtime da elde edilecek.
dynamic memory management çok çok daha maliyetli.Yani belirli temaların dışında kullanmamak lazım.

Ne zaman dynamic memory management kullanılıyor? 
	Mecbur olduğumuz zaman :D:D:D:D

C# JAVA GİBİ DİLLERDE TÜM NESNELER DİNAMİK ÖMÜRLÜ.HEPSİ DİNAMİK BELLEK YÖNETİMİ İLE ELDE EDİLİYOR.

dinamik ömür, hayata istenildiği zaman getirilip, istenildiği zaman silinebilen nesnelerdir.
bunlarında yerlerinin runtime da elde edilmesi gerekiyor.Dinamik bellek yönetimi de bu bellek
bloğunun elde edilmesi ve yönetilmesi işlemlerini yapıyor

mesela bir sınıfta 20 öğrenci var ve her öğrencinin notunu bir değişkende tutmak istiyoruz.
öğrenci sayısıda ileride değişecek. burada dinamik bellek yönetimi kullanmak gerekiyor.

aynı şekilde türün çalışma zamanında belli olma durumunda kullanılabilir.burada da gerekli.

tabi verim kritik bir uygulamada dinamik memory yönetimi ciddi fark yaratabilir.
static memory management daha hızlı çalışır ve daha kolaydır.

----------------------------------

STACK: Otomatik ömürlü değişkenler buradan alan kullanır.
Stack’te neler olur?

static olmayan local değişkenler

Fonksiyon parametreleri

Fonksiyonun return adresi

Geçici (temporary) değerler

void f(int x)
{
    int y;  // stack
}

Ömür (Lifetime)

Fonksiyon çağrılır → stack alanı ayrılır

Fonksiyon biter → stack otomatik temizlenir

📌 Bu yüzden “otomatik ömürlü” denir.

Büyüme yönü

Yüksek adresten düşüğe doğru büyür

✔ Çoğu sistemde doğru
⚠️ Standart bunu garanti etmez, ama pratikte böyledir.



HEAP: Dinamic memory management ile ayrılan alanlar

✅ Doğru

Heap’te neler olur?

malloc

calloc

realloc

C++’ta new

int *p = malloc(100 * sizeof(int));

Özellikler

Manuel yönetilir (free)

Ömrü sen belirlersin

Parçalanma (fragmentation) olabilir

C++’ta free store denir


BSS: Static ömürlü ama İLK DEĞERİ VERİLMEMİŞ değişkenler

Örnek:

int x;          // BSS
static int y;   // BSS


📌 BSS’teki değişkenler:

Program başlarken 0 ile doldurulur

Dosya boyutunu büyütmez

İlk değer verilmiş static ömürlü memory bloğu

✅ Doğru

DATA ikiye ayrılır:

🔹 Mutable data
int x = 10;
static int y = 5;

🔹 Immutable (read-only data)
const int c = 20;
char *s = "hello";


📌 String literal’lar read-only data’dadır.

5️⃣ TEXT SEGMENT (Sen yazmamışsın ama önemli)

Programın makine kodları

Genelde read-only

Paylaşılabilir

==================================================================================

malloc
heap ten memory allocate ediyor.Çöp değeri ile veriyor

calloc
bellek alanını allocate birde onu clear ediyor.

realloc 
var olan memory bloğunu büyütüp küçültmek için kullanılıyor.

free
dinamik olarak elde edilmiş bloğu memory havuzuna geri veriyor.



===============================================================================================================
Malloc:
void *malloc(size_t size);

    Kütüphane: <stdlib.h>

    Görevi:

        Heap (dynamic memory) üzerinde size byte bellek ayırır

    Dönüş değeri:

        Başarılı → ayrılan bloğun başlangıç adresi

        Başarısız → NULL

1️⃣ malloc NEREDE BELLEK AYIRIR?

📍 HEAP segmentinde

    Stack gibi otomatik değildir

    Ömrü sen free edene kadar devam eder

    Fonksiyon bitse bile bellek durur

2️⃣ malloc NE YAPMAZ?

❌ Belleği sıfırlamaz
❌ Tür bilmez
❌ Eleman sayısı bilmez

Sadece:

    “Bana X byte ver”

3️⃣ Tür neden void *?

void *p = malloc(100);

    malloc türden bağımsızdır → generic

    void * → her pointer türüne atanabilir

C’de cast gerekmez:

int *p = malloc(10 * sizeof(int)); // DOĞRU

⚠️ Cast:

    C++’ta zorunlu

    C’de hata gizler

4️⃣ sizeof NEDEN ŞART?

Yanlış:

int *p = malloc(10);  // ❌

Doğru:

int *p = malloc(10 * sizeof *p); // ✅ EN GÜVENLİ

📌 Neden?

    Platform bağımsız

    int boyutu değişebilir

5️⃣ Bellek yerleşimi (çok önemli)

int *p = malloc(5 * sizeof(int));

Heap’te:

[p][p+1][p+2][p+3][p+4]

    Contiguous (bitişik) bellek

    Dizi gibi kullanılabilir

p[3] = 10;   // OK
*(p + 3) = 10; // OK

6️⃣ malloc başarısız olabilir

int *p = malloc(100000000000);
if (!p)
{
    // bellek yok
}

📌 Sebepler:

    Bellek bitti

    Fragmentation

    OS limiti

7️⃣ free ZORUNLUDUR

free(p);
p = NULL;

Neden?

    Aksi halde memory leak

    Uzun çalışan programlarda ölümcül

8️⃣ SIK YAPILAN HATALAR (ÇOK ÖNEMLİ)
❌ sizeof(pointer) hatası

int *p = malloc(10 * sizeof(p)); // ❌

sizeof(p) → pointer boyutu (8 byte)
❌ Free sonrası kullanım (dangling pointer)

free(p);
*p = 5; // ❌ UB

❌ Double free

free(p);
free(p); // ❌ UB

❌ Free edilmeyen bellek

void f(void)
{
    int *p = malloc(10 * sizeof(int));
} // leak


calloc NEDİR?
void *calloc(size_t nmemb, size_t size);


Kütüphane: <stdlib.h>

Görevi:

Heap üzerinde nmemb × size byte bellek ayırır ve hepsini 0 yapar

Dönüş değeri:

Başarılı → bloğun başlangıç adresi

Başarısız → NULL

1️⃣ calloc neyi farklı yapar?

calloc iki iş yapar:

Belleği ayırır

Ayrılan her byte’ı 0 ile doldurur

📌 malloc SADECE ayırır, içerik çöptür

2️⃣ calloc neden iki parametre alır?
calloc(nmemb, size);


Anlamı:

nmemb adet eleman
her biri size byte


Örnek:

int *p = calloc(10, sizeof(int));


Heap’te:

[0][0][0][0][0][0][0][0][0][0]

3️⃣ calloc neden sıfırlar?

Sıfırlama:

int → 0

char → '\0'

pointer → NULL

float → 0.0

📌 Çünkü bit düzeyinde 0 atar.

4️⃣ calloc return tipi neden void *?

Aynı malloc gibi:

Tür bilmez

Generic’tir

Cast gerekmez

int *p = calloc(10, sizeof *p); // DOĞRU

5️⃣ calloc başarısız olabilir mi?

Evet.

int *p = calloc(1000000000, sizeof(int));
if (!p)
{
    // bellek yok
}


Sebep:

Bellek yetersiz

nmemb * size overflow

📌 calloc overflow’u kontrol edebilir, malloc edemez (implementation-dependent)

6️⃣ calloc vs malloc + memset
p = malloc(n * sizeof *p);
memset(p, 0, n * sizeof *p);


≈

p = calloc(n, sizeof *p);


Ama:

✔ calloc daha güvenli
✔ Bazı sistemlerde daha optimize
✔ Daha okunaklı

7️⃣ Performans farkı var mı?

malloc → hızlı

calloc → biraz daha yavaş (sıfırlama)

Ama modern OS’lerde:

Sayfa temelli sıfırlama

Lazy allocation

➡️ Fark genelde önemsiz

8️⃣ calloc kullanılması gereken yerler

✔ Struct dizileri
✔ Pointer dizileri
✔ Flag / state array
✔ NULL ile başlamak gereken durumlar

struct node *list = calloc(n, sizeof *list);

9️⃣ calloc ile yapılan klasik hatalar
❌ Yanlış sizeof
calloc(10, sizeof(int *)); // ❌

❌ free unutmak
int *p = calloc(10, sizeof *p);
// ...
// free(p); ❌

❌ Sıfır varsayımına güvenmek
if (p[3]) { ... }


✔ İlk kullanımda doğru
❌ Sonradan her zaman değil

🔟 calloc + realloc
p = realloc(p, new_count * sizeof *p);


⚠️ Yeni alan sıfırlanmaz

1️⃣1️⃣ Gerçek hayatta düşünme modeli

calloc = sıfırdan temiz dizi
===================================================================
realloc NEDİR?
void *realloc(void *ptr, size_t new_size);


Kütüphane: <stdlib.h>

Görevi:

Daha önce malloc / calloc / realloc ile ayrılmış bir bloğun boyutunu değiştirmek

Dönüş değeri:

Başarılı → yeni bloğun adresi

Başarısız → NULL (eski blok hâlâ geçerli)

1️⃣ realloc NE YAPAR?

realloc üç iş yapabilir:

Aynı bloğu genişletebilir

Aynı bloğu küçültebilir

Bloğu başka yere taşıyabilir

Ama her durumda:

Yeni dönen blok her zaman ARDIŞIKTIR

2️⃣ Olası senaryolar (ÇOK ÖNEMLİ)
🔹 Senaryo 1: Yerinde büyütme
p = realloc(p, 10 * sizeof(int));


Yanında boş yer vardır

Adres değişmez

Veri olduğu gibi kalır

🔹 Senaryo 2: Taşıma gerekir

Yanında yer yoktur

Heap’te yeni bir yer bulunur

Eski veri kopyalanır

Eski blok free edilir

Yeni adres döner

📌 Eski pointer’lar artık geçersizdir.

🔹 Senaryo 3: Başarısızlık

Bellek yok

NULL döner

Eski blok hâlâ senindir

3️⃣ En tehlikeli hata (ASLA YAPMA)

❌ Yanlış:

p = realloc(p, new_size);


Eğer başarısız olursa:

p = NULL

Eski bellek kaybolur (leak)

✅ Altın kural
int *tmp = realloc(p, new_size);
if (tmp)
    p = tmp;
else
{
    // p hâlâ geçerli
}

4️⃣ realloc + pointer aritmetiği

✔ Yeni p ile:

p[i]
*(p + i)


❌ Eski pointer’lar:

int *q = p + 3;
p = realloc(p, ...);
*q = 5;   // ❌ UB

5️⃣ Yeni alanın içeriği
p = realloc(p, bigger);


Eski alan → korunur

Yeni eklenen alan → ❗ tanımsız / çöp

📌 calloc gibi sıfırlamaz.

6️⃣ Küçültme davranışı
p = realloc(p, smaller);


İlk smaller byte korunur

Sonrası kaybolur

Adres değişebilir ya da değişmeyebilir

7️⃣ Özel durumlar (standart köşeleri)
🔹 realloc(NULL, size)
realloc(NULL, size) ≡ malloc(size)

🔹 realloc(ptr, 0)

Standarta göre:

ptr free edilir

NULL veya özel bir pointer dönebilir

📌 Portable kodda kullanma

8️⃣ realloc neden void * döndürür?

Generic

Tür bilmez

malloc ve calloc ile aynı mantık

9️⃣ Performans ve riskler

Kopyalama pahalı olabilir

Büyük bloklarda maliyet artar

Sık realloc → fragmentation

📌 Çözüm:

Kapasiteyi katlayarak büyütmek (vector mantığı)

🔟 Gerçek hayat örneği
size_t cap = 4;
size_t len = 0;
int *arr = malloc(cap * sizeof *arr);

while (data)
{
    if (len == cap)
    {
        cap *= 2;
        int *tmp = realloc(arr, cap * sizeof *arr);
        if (!tmp) break;
        arr = tmp;
    }
    arr[len++] = value;
}

🎯 EZBER ÖZET

realloc → boyut değiştirir

Taşıyabilir

Eski pointer’lar geçersiz

Başarısızlıkta eski blok durur

Yeni alan sıfırlı değildir


free NEDİR?
void free(void *ptr);


Kütüphane: <stdlib.h>

Görevi:

malloc, calloc veya realloc ile ayrılmış heap belleğini geri vermek

Dönüş değeri:

Yok (void)

1️⃣ free NE YAPAR?
free(ptr);


ptr’nin gösterdiği heap bloğunu

bellek yöneticisine iade eder

Program açısından:

O alan artık senin değildir

📌 free:

Belleği “silmez”

Sıfırlamaz

İçeriğe dokunmaz

Sadece sahipliği bırakır

2️⃣ free NE YAPMAZ?

❌ Pointer’ı NULL yapmaz
❌ Belleği temizlemez
❌ Stack / static belleği serbest bırakmaz

int x;
free(&x); // ❌ UB

3️⃣ free SONRASI DURUM (ÇOK ÖNEMLİ)
int *p = malloc(10 * sizeof *p);
free(p);


p hâlâ bir adres tutar

Ama bu adres:
❌ Artık geçersiz
❌ Dangling pointer

*p = 5; // ❌ UB

✅ Altın alışkanlık
free(p);
p = NULL;

4️⃣ Ne zaman free çağırabilirsin?

✔ Yalnızca şu fonksiyonlarla alınmış bellek:

malloc
calloc
realloc

❌ Yanlış free örnekleri
int a[10];
free(a); // ❌

static int x;
free(&x); // ❌

int *p;
free(p); // ❌ (uninitialized)

5️⃣ free(NULL) ne olur?
free(NULL);


✔ Güvenlidir
✔ Hiçbir şey yapmaz

📌 Bu yüzden:

free(p);
p = NULL;
free(p); // güvenli

6️⃣ Double free (en tehlikeli hata)
free(p);
free(p); // ❌ UB


📌 Heap bozulur
📌 Program çökebilir
📌 Güvenlik açığı

7️⃣ realloc ile ilişkisi
p = realloc(p, new_size);


Eğer yeni blok dönerse:

Eski blok otomatik free edilir

Başarısız olursa:

Eski blok hala senindir

8️⃣ free + lifetime (ömür)
Bellek türü	Kim temizler
Stack	Otomatik
Static	Program sonu
Heap	Sen (free)
9️⃣ Performans & fragmentation

Çok sık malloc/free:

Fragmentation

Yavaşlama

📌 Çözümler:

Pool allocator

Tek seferde büyük blok

🔟 Mini örnek (doğru yaşam döngüsü)
int *p = malloc(5 * sizeof *p);
if (!p) return;

p[0] = 10;

free(p);
p = NULL;

📌 HEADER ALANI NEDİR?

Header alanı, malloc / calloc / realloc ile ayrılan her heap bloğunun hemen başında,
bellek yöneticisinin kendi kullandığı gizli metadata alanıdır.

❗ Bu alan senin kullanımına açık değildir
❗ Programcı bu alanı göremez ve dokunmamalıdır

1️⃣ Bellek nasıl görünür?

Şöyle düşün:

int *p = malloc(5 * sizeof(int));


Gerçekte heap’te ayrılan alan şuna benzer:

[ HEADER ][ kullanıcı alanı (5 int) ]
          ↑
          p burayı gösterir


Yani:

p header’ı değil

kullanıcıya ayrılan alanın başlangıcını gösterir

2️⃣ Header alanında ne tutulur?

Implementasyona göre değişir ama genelde şunlar vardır:

Ayrılan bloğun boyutu

Bloğun dolu / boş bilgisi

Free list bağlantıları (next / prev)

Alignment bilgisi

Debug / guard bilgileri (bazı sistemlerde)

📌 Örnek (temsili):

struct header {
    size_t size;
    int is_free;
    struct header *next;
};

3️⃣ Header neden gerekli?

Çünkü:

✔ free(ptr) çağrıldığında:

Sadece ptr verilir

Boyut verilmez

📌 Bellek yöneticisi:

“Bu bloğun boyutu neydi?”
“Bitiği nerede?”
“Free list’e nasıl ekleyeceğim?”

➡️ Hepsini header’dan öğrenir

4️⃣ Header alanı neden gizlidir?

Çünkü:

Standart tanımlamaz

Implementasyona özeldir

Dokunursan:

Heap bozulur

Program çöker

Güvenlik açığı oluşur

((int*)p)[-1] = 100; // ❌ ÇOK TEHLİKELİ

5️⃣ Header boyutu sabit mi?

❌ Hayır

Platforma göre değişir

32-bit / 64-bit farkı

Debug / release farkı

Allocator türüne göre değişir

📌 Bu yüzden:

Header’ın boyutunu ASLA varsayma

6️⃣ sizeof neden header’ı içermez?
int *p = malloc(100);
sizeof(p); // ❌ header ile alakası yok


sizeof → compile-time

Header → runtime

7️⃣ Pointer aritmetiği neden sadece kullanıcı alanında güvenli?

Çünkü:

p + i


Sadece ayrılmış kullanıcı bloğu içinde tanımlıdır

Header’a taşmak → Undefined Behavior

8️⃣ realloc header’ı nasıl kullanır?

realloc:

Eski bloğun header’ından boyutu okur

Yeni alan bulur

Kopyalama miktarını hesaplar

Gerekirse header’ı günceller


ÇOK ÖNEMLİ

	malloc ile bellek alanları ayrılabilir.Bu dinamik memory metodu ile ayrılan
	blokları bir şekilde bir veri yapısında kaydı tutulmalı. Bu veri yapısı da 
	heapten alan harcar. 

	mesela 1500 byte lık alan allocate ettim. birde 24 byte lık bir veri yapısı 
	olsun. totalde 1524 byte yer kullanılmış oldu.

	Bu alana METABLOCK veya HEADER denir.
	burada ilgili blok ile ilgili bilgiler var.
	ne kadar çok ufak alanlar elde edilirse, o kadar da kendi veri yapısı
	için alan harcanıyor. Çok sayıda bellek alanı, az sayıda memory alanına
	göre daha fazla header alanı kaplıyor.

	bir pointer hatası yapılırsa, yani bana ait olmayan bir alana bir bloğa
	veri aktarılırsa, sistemin kullandığı header kısmına veri yazılmış olabiliriz.
	bu durumda dynamic memory management tamamen çöker.Corrupt olur, bozulur.

	Heap Alanının Fragmantation Durumu
	Heap ten çok fazla alan alındığında, ardışık olarak 50.000 byte olmayabilir 
	ama 50.000 byte toplamda yer olabilir. burada alan fragmante oluyor.

	Sisteme yer verilene kadar, o alanı başka birinin kullanması mümkün değil.
	bu geri verme işlemine free ya da deallocate deniyor.

	free edilmezse memory, memory leak oluşuyor.Yani bellek sızıntısı.
	bu oluşursa memory de işi yapabilmek için yer kalmıyor artık.

	Programın işi bitti kapandı ama alınmış alanları free etmedik diyelim.
	Program tekrar çalışırsa o bellek alanları sanki hiç alınmamış gibi 0 km olarak
	bize ait ve kullanılabilir. 

	FREE FUNCTION İLE İLGİLİ UNDEFINED BEHAVIOR DURUMLARI ve TİPİK HATALAR.

	1- free fonksiyonuna dinamik olarak elde dedilmemiş adres bloğu göndermek
		UNDEFINED BEHAVIOR
		
		int a[10];
		free(a); // UB

	2- free ile geri verilen bellek bloğunun adresi geçersiz/invalid bir adrestir.
		Böyle bir pointer değişkeni ona yeni atama yapmadan asla kullanmamalıyız.
		Artık buna dangling pointer deniyor.Bir nesneyi gösteriyordu ama artık
		o nesne öldü, bu sebeple bu bir dangling pointerdır
		free den sonra sonra pd geri verildi. adres aynı değişmedi ama artık
		geri verildi.Artık geçersiz bir pointer.
		Evde kiracısın ama kontrat bitmiş.başına ne gelir kim bilir :D
		print_array(pd,n); dereference et yada etme. Her durumda UNDEFINED BEHAVIOR.
	
		pd = (int *)checked_malloc(n * sizeof(int));
		int *p = pd;

		free(pd); -> burada hem pd hemde p dangling pointer haline geldi.
		hem p hemde pd yi kullanmak UNDEFINED BEHAVIOR.çünkü ikiside aynı adresi
		kullanıyor.
	
		Burada yapılan şey free edildikten sonra
		pd = NULL; yapılır. Dereference etmemek gerekir tabi.
		bu sayede dangling pointer olmaktan çıkarır.
		NULL hiçbiryeri göstermeyen geçerli pointer dangling ise geçersiz.
		pd = &x; yapılabilir. Bunu telegramda hocaya sordum.

	3- Dinamik bellek bloğunun adresi free den sonra geçersiz bir adres.
	bu adresi tekrar free etmek te geçersiz. UB

		pd = (int *)checked_malloc(n * sizeof(int));
		int *p = pd;

		free(p);
		//code
		free(p);  // buna double deletion deniyor.


	4- malloc ile elde edilen bellek bloğunu free işlemi ile küçültme girişimi.
		free(pd + n/2); burası kesinlikle UNDEFINED BEHAVIOR örneği


		int main()
		{
			int* pd;
			int n;

			printf("kac adet tamsayi: ");
			(void)scanf("%d", &n);

			if (!(pd = (int*)malloc(sizeof(int) * n)))
			{
				fprintf(stderr, "Yetersiz bellek alani!\n");
				return 1;
			}
			randomize();
			set_random_array(pd, n);
			print_array(pd, n);
			free(pd); // burada sorun yok ama bazıları 
			//free(pd + n/2); burası kesinlikle UNDEFINED BEHAVIOR
			// print_array(pd,n/2); burasıda UNDEFINED BAHAVIOR oluyor artık.
		}


	5- malloc ile elde edilen bellek bloğunu geri vermemek yanlış.(memory leak)
		Elde ettiğimiz dinamik bellek bloğunu programın sonuna kadar
		free etmemeniz memory leak değildir.Çünkü memory kalmadı artık program bitti :D

		a - kodu okuyanlar için
		b - test işlemleri için
		c - static kod analizi yapan programlar için
		d - dinamik kod analizi yapan programlar için
		
		Elde ettiğimiz tüm bellek bloklarını geri vermeliyiz.
		alışkanlık haline getirmek lazım.
		zaten program bitiminde free memory boşaltılıyor.
		Sorun oluşturabilecek durumlar oluşabilir bu sebeple free ile
		vermek gerekir.

		
		NOT: free function a NULL pointer geçilmesi tanımsız davranış değildir.
		Tanımlı davranıştır. Defined behavior.

		pd = NULL;
		free(pd); UB değil

		void my_free(void *vp)
		{
			if(vp == NULL)
				return ;
		}

		Eğer malloc fonksiyonuna 0 değeri ile çağrı yapılırsa
		malloc(0) -> UB DEĞİL ama ne olacağı UNSPECIFIED BEHAVIOR

		a- Derleyici NULL döndürtebilir 
		b- Bir adresi döndürtebilir.
		
		Dereference edilmemelidir.
		Free ye göndermek UB değildir.

			pd = NULL;
		free(pd); UB değil

		void my_free(void *vp)
		{
			if(vp == NULL)
				return ;
		}
		free(vp); //UB değil.
Fabrika fonksiyonu,

Bir nesneyi / yapıyı oluşturan, başlatan ve hazır halde döndüren fonksiyondur.

Yani:

Nesnenin nasıl oluşturulduğunu gizler

Kullanıcıya hazır bir şey verir

=========================================================================================
TEKRAR:

void * malloc(size_t name);

Runtime da dynamic bellek bloğu ayırıp nunmun adresini return ediyor.
Kesin verecek diye bir şart yok.Size büyükse vermeyebilir.
Bu durumda NULL pointer döndürür.Bu yüzden geri dönüş değeri test edilmeli.
Null mü değil mi diye!!!

c de malloc ile ayırlan bellek alanına heap denir 
C++ da buna Free Store ismi verilir.

Malloc bellek bloğunu garbage value lar ile verir daha sonra
memset ile 0 lana bilir.

yada calloc kullanılabilir.

===================================================================================================

Realloc için güzel örnekler: 
Alanı büyütme: 
size_t n;
	size_t n_add;
	int* pd;

	printf("kac tamsayi \n");
	scanf("%zu", &n);
	// static kod analizi yapan programlar var. Bunlar kod kalitesi için analiz
	// yapıyor. Microsoftun da kendi analiz programı var. Bu herşeye uyarı verebilir.
	//kapatmak mantıklı olabilir.

	pd = (int*)malloc(n * sizeof(int));
	if (!pd)
	{
		fprintf(stderr, "bellek uyarisi\n");
		return 1;
	}

	printf("ilk elde edilen bellek blogunun adresi : %p\n",pd);
	printf("kac eleman eklenecek\n");
	scanf("%zu", &n_add); // küçük ve büyük alan ekleyerek dene.

	pd = (int*)realloc(pd, (n + n_add) * sizeof(int));
	if (!pd)
	{
		fprintf(stderr, "Bellek Uyarisi\n");
		return 1;
	}

	printf("ilk elde edilen bellek blogunun adresi : %p\n", pd);

	free(pd);


	alan küçültme: 
	size_t n;
		size_t new_size;
		int* pd;

		printf("kac tamsayi \n");
		scanf("%zu", &n);
		// static kod analizi yapan programlar var. Bunlar kod kalitesi için analiz
		// yapıyor. Microsoftun da kendi analiz programı var. Bu herşeye uyarı verebilir.
		//kapatmak mantıklı olabilir.

		pd = (int*)malloc(n * sizeof(int));
		if (!pd)
		{
			fprintf(stderr, "bellek uyarisi\n");
			return 1;
		}

		randomize();
		set_random_array(pd, n);
		print_array(pd, n);
		printf("ilk elde edilen bellek blogunun adresi : %p\n",pd);

		printf("Son halde kac eleman olacak\n");
		scanf("%zu", &new_size);
		pd = (int*)realloc(pd,new_size * sizeof(int));
		if (!pd)
		{
			fprintf(stderr, "Bellek Uyarisi\n");
			return 1;
		}


		set_random_array(pd, new_size);
		print_array(pd, new_size);
		printf("ilk elde edilen bellek blogunun adresi : %p\n", pd);
		free(pd);


		Tipik hatalar
	
	1- Dinamik bellek bloğunu geri vermemek.memory leak
	2- Dinamik bellek bloğu free edildi.sonrada bu ptr nin gösteridği nesneye erişilmeye çalışıldı.
	Dereference etmek. UNDEFINED BEHAVIOR
	3- Dİnamik bellek bloğunun adresini başka fonksionlara kopyaladık, free ettik ama diğer kodların 
	bundan haberleri yokken 
		a - invalid pointerı kullandılar. UB
		b - onlarda free etti.	UB
	4- Dinamik bellek bloğunu realloc ile büyütmeye çalıştık, sanki aynı yerde büyüyecek gibi yazdık kodu,
	ama dizi başka bir yere taşınınca UB oluştu.
	5- Dinamik olmayan bellek bloğunu realloc ile büyütmeye çalışmak UB.

	Bazı programlarda heapten alınarak kullanmış bir alan olsun, free ile geri versek bile oradaki byte lar
	orada duruyor olabilir.Bu da güvenlik açığı oluşturabilir. bu memory bloğunun free etmeden önce clear
	edilmesi(memset(pd,0,size * sizeof(int))) gerekir, sonra free edilir.



	===============================================================================
	Storage Class Specifiers vs Type Modifiers

Storage class specifiers

➡️ Bir nesnenin

Ömrünü (lifetime)

Görünürlüğünü (linkage)

Nerede tutulacağını (storage duration)

belirler.

auto
register
static
extern

🔹 Type modifiers

➡️ Türün nasıl davranacağını belirler.

const
restrict
volatile


auto (C’de neden anlamsız?)
C’de auto ne demekti?

Otomatik ömürlü değişken

Ama:

int x = 10;


ZATEN:

Yerel

Otomatik ömürlü

Yani:

auto int x = 10;
int x = 10;   // AYNI


📌 Bu yüzden:

C’de işlevsiz

C99 sonrası kullanımdan düştü

❌ Global scope’ta auto
auto int g = 10; // ❌ sentaks hatası


Sebep:

Global değişkenler otomatik olamaz

Static ömürlüdür

❌ Parametrelerde auto
int func(auto int x) // anlamsız


Parametreler:

ZATEN otomatik ömürlü

C++ farkı

C++’ta:

auto x = 10; // tür çıkarımı


➡️ Bambaşka bir anlam

2️⃣ register (neden öldü?)
register neydi?

“Derleyiciye rica: bunu CPU register’ında tut”

register int x = 10;


📌 Bu bir rica, emir değil.

Neden performans için düşünülüyordu?

CPU işlemleri register’da yapar

Memory → register taşıma pahalıdır

Eğer değişken zaten register’da ise:

Ek yük yok

Ama neden artık kullanılmıyor?

Çünkü:

Compiler senden kat kat daha iyi optimize eder

Modern compiler:

Loop invariant çıkarır

Register allocation yapar

Instruction scheduling yapar

📌 Senin yazdığın:

register int i;


➡️ Compiler için gereksiz ve hatta komik 😄

register ile ilgili KURALLAR

❌ Adresi alınamaz:

register int x;
int *p = &x; // ❌ sentaks hatası


Sebep:

Register adreslenebilir bir bellek değildir

❌ Global değişken olamaz:

register int g; // ❌

C++’ta durum

register resmen dilden kaldırıldı

Compiler tamamen yok sayıyor

3️⃣ static (en önemli, overload edilmiş keyword)

static tek kelime ama 3 farklı anlam.

🔹 1. Global scope’ta static
static int g = 10;


➡️ Internal linkage

Sadece aynı source file

Dışarıdan görünmez

“Private global” gibi

📌 Header’da kullanılırsa:

Her .c dosyasına ayrı kopya

🔹 2. Local scope’ta static
void f(void)
{
    static int x = 0;
    x++;
}


Static ömürlü

Program başında oluşturulur

Program sonunda yok edilir

Fonksiyon çağrıları arasında değer korunur

📌 Stack’te değil
📌 BSS / DATA segmentinde

🔹 3. Fonksiyonlarda static
static void helper(void)
{
}


Sadece aynı dosyadan çağrılabilir

Modül içi yardımcı fonksiyon



1️⃣ Neden extern / static diye bir şey var?

Çünkü:

C/C++ programları TEK dosya değildir.

Gerçekte:

ali.c
veli.c
hasan.c
omer.c


Hepsi ayrı ayrı derlenir

Sonra linker bunları birleştirir

📌 Soru:

Bir dosyada tanımlanan isim (değişken / fonksiyon)
diğer dosyalardan görülebilir mi?

2️⃣ Linkage (Bağlantı) kavramı

Linkage =

Aynı isim, farklı kaynak dosyalarda aynı varlığa mı işaret ediyor?

🔹 External Linkage (Dış bağlantı)

Aynı isim

Aynı varlık

Tüm proje genelinde tek

int x = 10;
void foo(void) {}


➡️ Default olarak external linkage

📌 Bu şu demek:

Başka .c dosyaları da bunu kullanabilir

🔹 Internal Linkage (İç bağlantı)

Aynı isim

Farklı dosyalarda farklı varlık

Dosya dışından görünmez

static int y = 56;
static void helper(void) {}


📌 static = bu dosyaya özel

🔹 No Linkage

Sadece bulunduğu scope’ta geçerli

Dışarıdan görünmez

void f(void)
{
    int x = 10;  // no linkage
}

3️⃣ Default davranış (çok önemli)
Nerede	static yoksa
Global değişken	external linkage
Global fonksiyon	external linkage

📌 Bu yüzden:

int x = 10;


Tüm projeye açılmış olur.

4️⃣ extern ne yapar?
extern int x;


Bu TANIM DEĞİL, sadece bildirim:

“Bu isim başka bir dosyada tanımlı, yer ayırma”

📌 Bellek ayırmaz
📌 Linker’a bilgi verir

5️⃣ Doğru header / source düzeni
✔ DOĞRU KULLANIM
ali.h
extern int x;
extern int a[];
void func(int);

ali.c
int x = 10;
int a[20] = {0};
void func(int x) {}


📌 Fonksiyonlar için extern yazsan da yazmasan da extern kabul edilir

6️⃣ Sadece dosya içi kullanım (private)
ali.c
static int g = 20;
static void helper(void) {}

ali.h
// HİÇBİR ŞEY YOK


📌 Dış dünyadan erişim yok
📌 Tam modül gizliliği

7️⃣ “static koymasak ama header’da da bildirmesek olmaz mı?”

❌ OLMAZ

Neden?

// file1.c
int x = 10;

// file2.c
int x = 20;


➡️ Multiple definition
➡️ Linker hatası
➡️ Ya da UB

📌 Çünkü:

External linkage’lı isimler tüm projede TEK OLMALI

8️⃣ Fonksiyon çakışması örneği (çok kritik)
// utility.c
void print_array(int *p, int n) {}

// main.c
void print_array(int *p, int n) {}


➡️ İKİSİ DE external linkage
➡️ Aynı isim
➡️ Linker error veya UB

9️⃣ Header’da static NEDEN YANLIŞ?
// utility.h
static void helper(void);


Bu ne demek?

Header her .c dosyasına kopyalanır

Her dosyada AYRI fonksiyon oluşur

📌 Bu:

Kod şişmesi

Anlamsız

Yanlış tasarım

❗ Header’da static TANIM / BİLDİRİM YAPMA

🔥 ALTIN KURAL (EZBER)

Dışarıya açık isim → header’da extern bildirim
Sadece dosya içi → .c dosyasında static tanım

10️⃣ Global namespace pollution (isim kirliliği)

Problem:

External linkage isimler global

Çakışma riski yüksek

Çözüm (C’de):

net_socket_init()
net_socket_send()
net_socket_close()


📌 Prefix kullanılır

11️⃣ C++ farkı

C++’ta:

namespace net {
    void send();
}


➡️ İsim çakışması yok
➡️ Temiz çözüm

12️⃣ Büyük resmi gör

static = gizlilik

extern = paylaşım

Linkage = linker seviyesinde kim kimi görüyor

Bu OOP’teki:

private

public

mantığının C karşılığıdır




VOLATILE
--------

değişkenler 2 farklı yapıda oluyor.
program dışı kaynakları tarafından değiştirilen nesneler.
mesela bir kod var ve dışarıdan bir aygıtın bu bellek alanını set edebileceğini biliyoruz.
burada volatile kullanılır.

dış kaynaklar tarafından değiştirilebilen varlıklar,
memory mapped file olabilir.
birtakım cihazların registerları olabilir.
interruptlarla ilgili olabilir ...

bu tip örnekler ile ilgili derleyicinin optimizasyon problemi var.

DİKKAT!!!!
Aşağıda compiler g yi registerlara alır.registerlara almasının sebebi, memory den erişim maliyeti
registerlardan erişime göre çok fazla.g nin de değişmediğini görünce her seferinde registerlardan
veriyi işleme sokar.çünkü daha maliyetsiz.
AMA
Dış dünyadan başka bir cihaz, g nin değerini değiştirirse bunu anlayamadan tekrar cpu registerdan
değeri okuyup işlemlere soktuğu zaman hata ile karşılaşma şansımız çok yüksek.
Aşağıda bunun örneği var

int g = 20;

int main()
{
	if(g == 20)
	{
		
	}
}

(NOT: g++; olsaydı değiştiğini anlayacaktı. ama değişmemiş zannedip buna göre optimizasyon yapıyor.
volatile ile bu optimizasyonu iptal ediyoruz.yine memory den her durumda değeri çekiyor.)

Bunu engellemek için volatile keyword kullanılır.
volatile her seferinde veriyi memory den oku demektir.
Değiştirilirse de oradan okuduğunda anlayacak.
Burada bir optimizasyon yapmaktan kaçacak compiler.

yani volatile ile nitelenen değişken her zaman memory den okunacak, registerdan değil.
Optimizasyonu iptal ediyor.

örnek:

int flag = 1;

int main()
{
	while(flag)		// bir interrupt gelip flagi 0 yapıyor ama döngü halen dönmeye devam ediyor.
	{				// çünkü optimizasyon açıkregisterdan okundu değer.
					// volatile int flag = 1 ile tanımlanmalıydı.
	// code
	// code
	}
}

doğru olan

volatile int flag = 1;

int main()
{
	while(flag)		
	{				
		// code
		// code
	}
}

-----------------------

--------------------------------------------------------------------|
																	|
NOT!!!!!! DÖKÜMANTASYONDAN ALDIM									|
Volatile değişkeni,volatile olmayan bir lvalue değişken ile			|
read/write yapmak UNDEFINED BAHAVIOR.								|
																	|
volatile int n = 1; // object of volatile-qualified type			|
int* p = (int*)&n;													|
int val = *p; // undefined behavior.								|
																	|
--------------------------------------------------------------------|


-----------------------


volatile int x = 123;

int main()
{
	volatile int *ptr = &x;
	*ptr;		// bu her çağırıldığında memory den tekrar okur değerini.Registerdan değil. 

	Eğer
	int * volatile ptr; // dersek bu seferde ptr ye her eriştiğimde optimizs. yapmayacak. Memoryden okuyacak.

	
	volatile int * volatile ptr = &x; // dersek *ptr ve ptr volatile oldu.
}

--------------------------------

#define		XREG		(int)0x1ac4

int main()
{
	volatile int *ptr = XREG; derleyici her seferinde bu adresi memory den dereference etmek zorunda.
}

---------------------------------

diğer keyworklerle kullnılabilir.

const volatile int t = 10;
volatile int z = 20;
const int a = 30;


ÇOK ÖNEMLİ !!!!!!!
const volatile int t = 10;  
t nin değeri değişmeyecek ama program dışı varlıklar const a rağmen t yi değiştirebilir.
const program içi kaynaklar tarafından değeri değişmeyecek demek.

--------------------------------
--------------------------------

AŞIRI GARİP BİR ÖRNEK.
BURADAKİ HATA TUHAF

int main()
{
	int a[10] = {0};
	volatile int i;
	
	for(i = 0; i <= 10; i++) // burada UB var ama olan olay şu.
		a[i] = 0;			// dizinin memory deki yeri bittikten hemen sonra, 
							// i nin değeri gelebiliyor.Yani a[9] son eleman, a[10] ise 
							// ub ama compiler a[10] adresini i nin adresi olarak atayabiliyor.
							// o zamanda a[10] = 0; demek i = 0; demek oluyor.
							// infinite loop :D:D:D:D:D
							// bunu volatile yapıyor her seferinde memory den okuduğu için :D:D
							// birçok derleyicide sonsuz göndüye girebiliyor.Garantisi yok.
}





=============================================================
Restrict
--------
Benim gösterdiğim nesneyi bir başkası gösteremesin demek.C99 da eklendi.
C++ ta restrict yok.

kullanımı asteriskten sonra gelir. öncesinde olması sentaks hatası
int * restrict ptr;

ÖR:
void func(int* px, int* py, int* restrict pz)
{
}

burada px ve py nin pz nin gösterdiği nesneyi gösterme ihtimali yok.bunu sağlıyor.
bu derleyicinin daha iyi optimizasyon yapmasını sağlıyor.

eğer 
px = pz; yapılırsa bu bir UNDEFINED BAHAVIOR

----------



*/  

void f3(void)
{
	printf("f3 cagrildi\n");
	exit(EXIT_FAILURE); // bu şekilde yapılınca buradan sonra process/program sonlandırılır.
        // bunu yapmanın 1-2 sebebi var.
        // 1. işini bitirmiştir ve bu yüzden sonlandırılır.EXIT_SUCCESS ile yapılır.
        // 2. başarısızlık durumunda çağrılır.
	printf("f3 Sona erdi\n");
}

void f2(void)
{
	printf("f2 cagrildi\n");
	f3();
	printf("f2 Sona erdi\n");
}
void f1(void)
{
	printf("f1 cagrildi\n");
    exit(EXIT_FAILURE);
	f2();
	printf("f1 Sona erdi\n");
}
void handler1(void)
{
	printf("handler1 cagrildi\n");
}

void handler2(void)
{
	printf("handler2 cagrildi\n");
}

void handler3(void)
{
	printf("handler3 cagrildi\n");
}


int main()
{
    /*printf("main cagrildi\n");
	f1();
	printf("main sona erdi\n");
*/

/*printf("main basladi\n");
	atexit(handler1);
	atexit(handler2);
	atexit(handler3);

	exit(EXIT_FAILURE);  //ters sırada çağırıyor,handler 3, 2, 1 şeklinde çağrılıyor.
	printf("main sona erdi\n");*/
	
	int* pd;
	int n;

	printf("kac adet tamsayi: ");
	(void)scanf("%d", &n);

	if (!(pd = (int*)malloc(sizeof(int) * n)))
	{
		fprintf(stderr, "Yetersiz bellek alani!\n");
		exit(EXIT_FAILURE);

	}

	(void)memset(pd, 0, n*sizeof(int)); // memset yapılmazsa garbage value görülür.
	free(pd);
	pd = NULL;

	
}