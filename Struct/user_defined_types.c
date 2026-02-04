#include<stdio.h>
#include<time.h>
/*
Types 2 ye ayrılır
Basic types ve User defined types.

structures - yapılar				
unions - birlikler					
enumerations - numaralandırmalar

structures, class ların çok primitiv hali.
C nin nesne yönelimli programlama paradigmasına en çok yaklaştığı yerdeyiz.
C nin C++ a en çok yaklaştığı alan.

1 - structure decleration
struct ile başlıyor ve isimle devam ediyor ve tamamına deniyor.

2 - bu isme structure tag deniyor
structure tag opsiyoneldir.

3 - struct içindeki elemanlara member deniyor.
C++ ta boş yapı olabilir ama C de elemanlara ihtiyaç var.

struct Data{
	int x, y;
	double dval;
};

Derleyici bu nesne için elemanların toplamı kadar byte yer ayırıyor. Ama padding hizalama
konusunda görülecek daha fazla yer ayırdığıda görülebilir.İleride görülecek.

KULLANIM

struct Data{
	int x, y;
	double dval;
};

int main()
{
	struct Data mydata; // struct data türünden bir nesne yaratıldı.
}

sizeof(struct Data) ile boyutu görülebilir. 3 elemanın toplamı 16 yı verir.

Derleyici bu türden bir değişken tanımlanırsa yer ayırır.

STRUCT ELEMANLARI
Değişken, dizi, pointer, multi-dim dizi, fonksiyon ptr ... olabilir.
AMA FONKSİYONLAR direkt olarak member olamaz. FONKSİYON POİNTERLAR member olabilir.
Struct nesnesinin elemanı yine bir struct olabilir.örneği aşağıda.

struct Point{
	int x, y, z;
};

struct Rectangle{
	struct Point a,b,c,d;	
};

Struct Point mydata;
Struct Point a[10];
Struct Point *p = &mydata;  bunların hepsi geçerli.
diğer türler gibi hepsi geçerli.

burada typedef ile tanımlama kısaltılabilir.

typedef struct Point s1; dersek s1 dediğim zaman struct Point türünü belirtmiş oluyorum.


Aynı zamanda
struct Rectangle{
	struct Point a,b,c,d;
}R1;   

dersek, struct rectangle türünden R1 isimli değişken tanımlamış olduk.

typedef struct Rectangle{
	struct Point a,b,c,d;
}R1;
dersek, struct Rectangle türünün eş ismi R1 oldu.
R1 mydata; denebilir artık. İLERİDE GÖRÜLECEK.

C de empty struct yok. C++ ta var.

struct Rectangle türünden local- global değişkenler/nesneler olabilir.
static struct Rectangle ile tanımlanabilir.
const struct Rectangle ile tanımlanabilir.
extern, volatile... hepsi geçerli structlarda

global olarak tanımlanırsa içindeki değerlere ilk değer verilmezse, 
ayrıca static ömürlü olacağından elemanları 0 olur.

local scope ta ise içindeki elemanlar  garbage/indetermined value olarak başlar.
static local olursa elemanlar bu sefer 0 olarak başlar hayata. diğer türlerde olduğu gibi.

global blokta static ile tanımlanırsa private gibi olur.
sadece bu kaynak dosyadan erişilir. internal linkage a ait olur
direkt tanımlanırsa external linkage a ait olur.

struct Data{
	int x, y;
	double dval;
};

memorydeki yerleşimleride sırasıyla oluyor. sırayla x, y ve dval gelir.
Yapı nesnesinin en başındaki adres, yapı nesnesinin ilk adresidir. 

API NESNESİNİN ELEMANLARINA ERİŞİM

member selection operators

1  ()   []  .  -> 

.  ->   bunlara member selection deniyor ama insanlar nokta veya ok operatörü diyor.

dot operator ----  nokta operatörü
arrow operator ----  ok operatörü


NOT !!!!!!!!!!!!!!!!!!!!!
. operatörü struct nesnesinin kendisi yoluyla elemana erişiyor
-> operatörü struct nesnesinin adresi yoluyla elemana erişiyor

. operatörü binari infixtir.
x.y ==> derleyici böyle bir ifade görürse, sol operandı bir yapı / struct türünden nesne mi diye bakar.
çünkü böyle olmak zorunda. nokta operatörünün sağ operandı olan isim ise, sol operandının memberlarından
birisi olması gerekiyor.

struct Data {
	int x, y;
	double dval;
};

main
struct Data mydata;
mydata.x;
&mydata.x;
++mydata.x;
hepsi ok. öncelik sırası önemli. dot operator zaten 1. sırada.

yani 
int x = 10; burada x ile ilgili ne yapılıyorsa mydata.x ile de aynı şeyler yapılabilir.

Struct elemanı dizi olsaydı

struct Data {
	int x, y;
	double a[10];
};

int p* = mydata.a; yapılabilir. yani array decay geçerli.
--------------------------------------------------------------------------
--------------------------------------------------------------------------

STRUCT MEMBERLARA DEĞER VERMEK
NOT: 
YAPI ELEMANLARINA SAKIN TÜRKÇE İSİM VERME!!!

struct Data {
	int x, y;
	double dval;
};

struct Data mydata;
mydata.x = 10;
mydata.y = 10;
mydata.dval = 2.3;


struct Employee {  // hoca m_ konvensiyonunu kullanıyor.
	int m_id;
	char m_name[10];
	char m_surname[10];
	double m_wage;
};


struct Employee emp; // burada m_ yi kullanmadım.test ederken düzelt.
emp.id = 9874;
strcpy(emp.name, "Umut");
strcpy(emp.surname, "Kotankiran");
emp.wage = 120.56;

------------------------------------------------------
------------------------------------------------------

	// dinamik bellek bloğuna struct yerleştirmek
	struct Employee* pe = (struct Employee*)malloc(sizeof(struct Employee));
	(*pe).id;
	pe->id;

------------------------------------------------------
------------------------------------------------------
------------------------------------------------------
------------------------------------------------------

YAPI NESNELERİNİ INITIALIZE ETMEK / İLK DEĞER VERMEK

Dizilere ilk değer verme sentaksına benziyor.

1:20 GÜZEL BİR NASİHAT!!!

struct Data {
	int x, y;
	double dx,dy;
};

// struct Data mydata; // ilk değer verilmeden tanımlanırsa,
						// local scope ta garbage valuelar ile yaratılır.

// ilk değer verilirse
struct Data mydata = { 10,20,2.3,5.6 }; // ilk değer verildi artık.

eğer eleman sayısından fazla veri girilirse, sentaks hatası.
daha az verilirse değer verilmeyen memberlar 0 ile hayata başlar.
struct Data mydata = { 10,};  burada x 10 iken diğerleri 0 olarak hayata başlar
virgüle de trailing comma deniyor.

	
struct Data {
	int x, y;
	int a[5];
	double dx,dy;
};

	struct Data mydata = { 10,20,{1,3,},2.3,5.6 }; 

	printf("%d\n", mydata.x);
	printf("%d\n", mydata.y);
	printf("%f\n", mydata.dx);
	printf("%f\n", mydata.dy);

	print_array(mydata.a, sizeof mydata.a / sizeof * mydata.a);

	//aşağıdaki gibi olsaydı 
	struct Data mydata = { 10,20,{1,3,},2.3,5.6 };
	dizinin değer atanmamış elemanlarına 0 değeri yazılacaktı.
	struct Data mydata = { 10,20,{0,},2.3,5.6 }; dizinin elemaları tamamen 0 olurdu

	AMA
	struct Data mydata = { 10,20,1,2.3,5.6 }; burada sıra diziye geldiğinde elemanlar diziye 
												yazılacak.yani a ya 3 elemanı tamsayı olarak yazar 
												diğer iki elemana 0 yazar. sonraki dx ve dy yede 0 yazar.

	çıktı
	10
	20
	1   2   5   0   0
	0.000000
	0.000000
  
------------------------------------------------
ELEMANLAR CHAR OLSAYDI

  struct Data {
	int x, y;
	char a[20];
	double dx,dy;
};

struct Data mydata = {2,5,"Tugrul Kekec",2.3,4.5};

--------------------------------------------------------
--------------------------------------------------------

MULTIDIMENSION DIZI OLSAYDI

  struct Data {
	int x, y;
	char a[3][4];
	double dx,dy;
};

struct Data mydata = {2,5 ,{ {1,1,1,1}, {2,2,2,2}, {3,3,3,3} },2.3,4.5};

------------------------------------------------------

TEK ELEMANLI DİZİ OLSA BİLE CURLY BRACES KULLANMAK GEREKİYOR


  struct Data {
	int x;
	};

	struct Data mydata = {2}; parantez koymak şart ve içinede birşey girmek gerekiyor.
							  parantez konulduysa içide boş bırakılamıyor.


-------------------------------------------------------

DESIGNATED INITIALIZER 

int a[100] = {[5] = 12, [27] = 55}; 
bunu structlarda da kullanabiliyoruz.

struct Employee {
	int x, y;
	char name[20];
	char surname[20];
	int grades;
	int dept;
	double wage;
};


int main()
{
	struct Employee emp = { .x = 10, .y = 20,
							.name = "Ali", .surname = "atabak",
							.grades = 25, .dept = 35, .wage = 65.75};

	printf("%d\n", emp.x);
	printf("%d\n", emp.y);
	printf("%s\n", emp.name);
	printf("%s\n", emp.surname);
	printf("%d\n", emp.grades);
	printf("%d\n", emp.dept);
	printf("%f\n", emp.wage);
}

hepsi yazdırılır.

-------------------------------------------------------------------
-------------------------------------------------------------------
-------------------------------------------------------------------

MEMBERLAR GÖRÜLDÜ AMA STRUCT IN KENDİSİ NASIL KULLANILIR?

	struct Employee mydata;

	//burada mydata sadece 4 operatörün operandı yapılabilir.
	// 1. nokta operatörü . member selection operator
	// 2. sizeof operatörü (sizeof compile time sabitidir. ürettiği değer size_t türünden)
	// 3. & operatörünün operandı olabilir.
	// 4. atama operatörü = . Aynı türden yapı nesneleri arasında atama işlemleri olur.

	Farklı türden yapı nesneleri arasında atama yapılamaz.
	Farklı türden yapılar/structlar arasında tür dönüşümü yok


	struct Data mydata;
	//mydata = 5; geçersiz

	struct Nec necdata;
	//necdata = mydata; yine geçersiz çünkü türleri farklı. biri struct Nec, diğeri struct Employee

	//Tür değiştirme operatörünün operandı bir struct olamaz
	// (struct Nec)mydata; struct Nec burada hata verir.
	// bir yapı türünden diğerine ne explicit ne de implicit dönüşüm var.

	struct  Nec nx = { 12,14,4.5 };
	struct  Nec ny = { 22,44,16.5 };

	ny = nx; // TAMAMEN LEGAL. printf ile bakılabilir değerlerine.

	//bunu elemanları tek tek te kopyalayabiliriz.
	ny.x = nx.x;
	ny.y = nx.y;
	...
	//hepsi yapılabilir.

	HATTA MEMCPY ile de bu kopyalama yapılabilir.
	memcpy(&ny, &nx, sizeof(struct Data));

	sizeof büyüdükçe bu işlemde maliyetlenir.
	döngüler içinde sıksık bu işlem ciddi bir yavaşlama getirir.
	
	struct Data {
	int x, y;
	double a[20][15];
	};  2000 küsür byte eder.

	struct Data mydata1,mydata2;
	printf("%zu", sizeof mydata1);

	mydata2 = mydata1; // burada 2000 küsür bytelık bir kopyalama yapıyor.
						// bu büyük bir maliyet. atamak kolay ama çok maliyetli olabilen durumlar var.

	
	İKİ STRUCT ARASINDA İLK DEĞER VERME VEYA ATAMA YAPILABİLİR
	struct Employee ex = { 12,"alican","yilmaz", {0},54.70 };
	struct Employee ez = ex; // burasıda legal
	veya
	ez = ex; legal

	-----------------------------------------------------------

	İKİ OPERATÖR DİREKT OLARAK KARŞILAŞTIRILAMAZ

	struct Point {
	int mx, my, mz;
	};

	struct Point px = { 12,24,36 };
	struct Point py = { 12,24,36 };

	if(px == py) // BU KARŞILAŞTIRMA GEÇERSİZ !!!
				// tüm elemanları tek tek kıyaslayabilirdik
			// if(px.mx == py.mx && px.my == py.my && px.mz == py.mz) GEÇERLİ

-------------------------------
	struct nec {
	int nec;
	};

	int main()
	{
		struct nec nec; // geçerli ama tavsiye edilmez
	}


	----------------------------------------------

	İKİ STRUCTI EŞİTLEME
	struct Ar {
	int a[10];
	};

	int main()
	{
		struct Ar a;
		struct Ar b;
		b = a; //şeklinde bir atama yapılırsa aslında a dizisini direkt olarak b dizisine atamış oluyoruz
	}			//a.a dediğimde diziye ulaşırım. b.a ilede ulaşırım.
				// bunlar direkt dizi olsaydı b = a olamazdı çünkü dizi lvalue expression değildir.
	
	Bu sayede structlar yardımıyla dizileri birbirine atamış olduk.

	----------------------------------------------------------------
	----------------------------------------------------------------
struct {
	int a, b, c;
}x,y,z;

x y ve z bu türden global değişkenler.
ama bu türün ismi gizlendiği için, başka bir kod alanında bu türden değişken tanımlanamaz.

----------------------------------------------------------------

ptr değişkende tanımlanır.
struct {
	int a, b, c;
}x,*ptr = &x;



ptr değişkende tanımlanır.
struct {
	int a, b, c;
}x,*ptr = &x;

-------------------------------------------------
-------------------------------------------------
=================================================
=================================================
=================================================
=================================================

YAPILAR VE TYPEDEF BİLDİRİMLERİ.
--------------------------------

Daha pratik bir kullanım için bir isim verilebilir.
Birinci kullanım teması bu.
C++ ta typedef kullanımına gerekte kalmıyor.

struct Neco {
	int a, b, c;
};

typedef struct Neco Neco; // etiket ismi ile verilen typedef ismi aynı olabilir
							// hiçbir sorun yok.

// artık bunu belirttikten sonra

struct Neco nec; // burada struct türünü kullandık
Neco necx;		// burada ise struct türünün typedef ismini kullandık.
				// ikiside aynı olduğu için kafa karıştırabilir.

//Daha açık hali
typedef struct Neco N;

struct Neco struct1; // struct neco yine türü
N struct1x;			// burada ise N, struct Neco türünün typedef ismi.

---------------------------------------------------------------------

struct Neco {
	int a, b, c;
};

typedef struct Neco* NecPtr;

struct Nec {
	int a, b, c;
};

typedef struct Nec Nec; // ilk önce Nec olarak typedef edildi.
typedef Nec* NecPtr;	// sonrada Nec*, NecPtr olarak typedef edildi.


------------------------------------------------------------------------

ALTERNARİF YOLLARIDA VAR.

struct Nec {
	int a, b, c;
}nec; // bu tanımlama struct Nec türünden global bir nec tanımlaması yapıyor.

//başına typedef getirirsek nec bu türün typedef ismi olur.
typedef struct Nec {
	int a, b, c;
}nec;
nec X;

-------------------------------------------
-------------------------------------------

// aşağısı güzel örnek.
//hata birden fazla tanımlama yapılabilir.
typedef struct tagNec {
	int a, b, c;
}Nec,*NecPtr;

int main()
{
	Nec mynec;
	NecPtr ptr = &mynec;
	mynec.a = 10; // bu ve aşağısı aynı.
	ptr->a = 20;
}

---------------------------------------------------------------------------
---------------------------------------------------------------------------

//güzel örnek yine

//aşağıdaki tanım legaldi. dışarıya kullanımı kısıtlıyordu hatırlarsak
struct {
	int a, b, c;
}Nec;

//bunun başına bir typedef koyarsak artık bu türün eş ismi Nec haline geliyor.
// tag koymayınca compler bir id veriyordu hatırlarsak.

typedef struct {
	int a, b, c;
}Nec;

int main()
{
	Nec x = {10,20,30};
}


// buda kullanılan bir tema.hem struct ile kullanamam hemde struct olmadan kullanamam.
// NecPtr yazı türünün eş ismi değil. yazı türünden nesne adresinin eş ismi.
//ÖNEMLİ

//BU STRUCT TÜRÜNDEN SADECE DİNAMİK ÖMÜRLÜ NESNE OLUŞTURMA OLANAĞI VAR.

typedef struct {
	int a, b, c;
}*NecPtr;


int main()
{
	NecPtr pd = (NecPtr)malloc(sizeof(*pd));
}

---------------------------------------------------------
---------------------------------------------------------

//Amaç buradaki createobject kodunu kullanarak bir struct tanımlamak.
bunun dışında bir kullanım yok.
Handle tekniğinde daha iyi açıklanacak.

typedef struct {
	int a, b, c;
}*NecPtr;

NecPtr createObject(void)
{
	NecPtr pd = (NecPtr)malloc(sizeof(*pd));
	if (!pd)
		return pd;
	pd->a = 20;
	pd->b = 30;
	pd->c = 50;
}


int main()
{
	NecPtr pd = (NecPtr)malloc(sizeof(*pd));
}

==============================================================
==============================================================
==============================================================

YAPI NESNELERİ ADRESLERİ VE OK OPERATÖRLERİ
MEMBER SELECTİON
BUNLARA DOT OPERATOR YADA ARROW OPERATOR DENİR.

------------------------------------
1	()	[]	.	->                    soldan sağa, left associative
------------------------------------

a.b    bu yapı nesnesi yoluyla nesneye erişir.
ama eğer yapı nesnesi adresi varsa burada ok operatörü kullanılır.

----------------
Ör

struct Data {
	int x, y;
	char name[20];
};

int main()
{
	struct Data mydata = { 10,20,"Kaya" };
	struct Data* p = &mydata;

	struct Data your_data;
	your_data = *p; // aynı türden. Atama yapılabilir.

	//Elemanlara erişmek için
	(*p).x = 10; // operatör önceliğinden ötürü öncelik parantezine alındı.
	//veya
	p->x = 20;

	// ok operandının sol operandı struct türünden bir adres olmalı.
	// sağ operandı ise struct ın elemanlarından biri olmalı.

	strcpy((*p).name, "Can");
	strcpy(p->name, "mehmet");
	//(&mydata)->x = 30; da denebilir

	--------------------------------------------------------------
	--------------------------------------------------------------

	struct Data a[10];
	// code

	a[0].x = 5; // a nın struct olan birinci elemanının x elemanına 5 atadı.
	a->x = 5; // yukarıdaki ile aynı ifade çünkü array decay var.ilk elemanın adresi.
	// a[4].y = 34; yazmak ile (a+4)->y = 34; aynı şey.


	EN ÇOK KULLANILDIĞI YERLER FONKSİYON PARAMETRELERİ VE GERİ DÖNÜŞ DEĞERLERİ
	STRUCT OLAN FONKSİYONLAR.

	----------------------------------------------------------
	----------------------------------------------------------

	Ben bir soru sormuştum bildirimlerle ilgili.
	onu açıkladı


	typedef struct {
		int x, y;
		char name[20];
	}Data;

	typedef Data* DataPtr;

	int main()
	{
		Data mydata = { 10,20,"Umut" };
		DataPtr p = &mydata;
		DataPtr* pp = &p;
	}

	-----------------------------------------
	2. açıklama
	typedef struct Data{
		int x, y;
		char name[20];
	}Data;

	typedef Data* DataPtr;

	int main()
	{
		//burası ile aşağıdaki kısım aynı anlamda
		struct Data mydata;
		struct Data *p = &mydata;

		//aynı anlamdalar
		Data mydata;
		DataPtr p = &mydata;
	}


	------------------------------------------------------
	------------------------------------------------------

	typedef struct Data{
		int x, y;
		char name[20];
	}Data;f

	typedef Data* DataPtr;

	int main()
	{
		//burası ile aşağıdaki kısım aynı anlamda
		struct Data mydata;
		struct Data *p = &mydata;

		//aynı anlamdalar
		Data mydata;
		DataPtr p = &mydata;

		// dizide tanımlanabilir
		struct Data a[10];
		struct Data *p = a;
		int n = 10;

		while(n--)
		{
			*p; // burada *p dizinin elemanlarından herseferinde biri olur.
			p++;
		}

		//veya
		}while(n--)
		{
			p->x = 0; // Her dizi elemanının x nesnesinin değerini 0 yaptı kısaca.
			p++;
		}

	}

	---------------------------------------------------
	---------------------------------------------------
	---------------------------------------------------
	Struct türden dizi tanımlamak

	typedef struct Data{
		int x, y;
		char name[20];
	}Data;

	int main()
	{
		Data a[10] = { 0 };
		Data* p = a;
		printf("sizeof(Data) = %zu", sizeof(Data));

		for (int i = 0; i < 10; i++)
			printf("%p  %p %p\n", &a[i], (a + i),p++);
	}

	==========================================================
	==========================================================
	==========================================================

	Yapı Türden Nesnelerin Fonksiyona Gönderilmesi

	Özellikle sistem programlamada fonksiyona yapı türden ve ya yapı adresi türden
	nesneler göndermek veya geri dönüş değeri olarak kullanmak çok fazla kullanılıyor.

	1 - Bir fonksiyonun parametresi yapı türünden olabilir.

	call by value biçiminde yapılmış.
	ÖR:
	typedef struct {
		int a, b, c;
		char name[40];
	}Data;
	
	void func(Data x)
	{
		printf("%d %d %d %s\n", x.a, x.b, x.c, x.name);
	}

	int main()
	{
		Data mydata = { 1,2,3,"NECO" };
		func(mydata);
	}

	Ama burası call by value. burada struct elemanları herhangibir şekilde 
	değiştirilemez.Bu zaten çok maliyetli.
	struct türünün sizeof u büyüdükçe bu işlem çok maliyetli olur.
	fonksiyon local değişkenlere veri kopyalanacak, return yazılacak temp
	bir değişkene daha bu değer kopyalanacak, bunlar stack ten yer yiyor zaten.

	Daha mantıklı olan call by reference
	adres göndermek 4 byte, burası ise 28 byte. 100.000 byte ta olabilirdi daha fazlada.


	2 - Call by Reference ile read only
	void print_data(const Data* x); tipinde


	typedef struct {
		int a, b, c;
		char name[40];
	}Data;

	void print_data(const Data* x)
	{
		printf("%d %d %d %s\n", x->a, x->b, x->c, x->name);
	}

	int main()
	{
		Data mydata = { 1,2,3,"NECO" };
		print_data(&mydata);
	}

	-----------------------------------------------------------------
	
	3 - call by reference ile doğrudan dataya erişim için

	void modify_data(Data* x)

	typedef struct {
		int a, b, c;
		char name[40];
	}Data;

	void print_data(const Data* x)
	{
		printf("%d %d %d %s\n", x->a, x->b, x->c, x->name);
	}

	void modify_data(Data* p)
	{
		p->a *= 2;
		p->b *= 3;
		p->c *= 5;

		strcat(p->name, "Can");
	}

	int main()
	{
		Data mydata = { 1,2,3,"NECO" };
		print_data(&mydata);
		modify_data(&mydata);
		print_data(&mydata);
	}


	-------------------------------------------------------
	-------------------------------------------------------
	-------------------------------------------------------

	void f1(Data x);
	void f2(const Data *x); // input parameter. değerleri okuma amaçlı kullanıyor
	void f3(Data *x); //output parameter. parametreleri yazma amaçlı kullanıyor
	void f4(Data *p); // Hem okuma hem yazma amaçlı.in-out parameter

	--------------------------------------------------------
	--------------------------------------------------------

	Data f5(void);

	Data mydata;

	mydata = f5(); // 2 defa blok copy olarak. hem fonk return değerinin yazılacağı temp
					// hemde hemde mydata ya copy var.

	GERİDÖNÜŞ DEĞERİ STRUCT TÜRÜNDENSE 
	maliyet çok artıyor.Çok tercih edilen bir durum değil.

	GERİDÖNÜŞ DEĞERİ STRUCT * TÜRÜNDEN İSE
	tercih ediliyor.maliyeti çok daha düşük. pointer sizeof u kadar

	Data *p;
	p = f6();

	-------------------
	
	DİKKAT!

	Data *func(void)
	{
		Data mydata = {1,2,3,"Ali"};
		return &mydata;		//UNDEFİNED BEHAVİOR. OTOMOTİK ÖMÜRLÜ NESNENİN 
	}						// ADRESİ RETURN EDİLMİŞ


	const Data *f7(void);   bu şekilde olabilir birde.çok seyrek çıkar karşımıza.

	Burada bir fonksiyon pointer döndürüyorsa bazı kuralları vardı bunu yazmıştık zaten 
	pointerlar konusunda.

	static yerel
	global 
	// birde string literalleri var ama buranın konusu değil.
	kullanıcıdan aldığını geri veren
	otomotik ömürlü nesneler.

	-------------------------------------------------------------

	PARAMETRELERİ POİNTER OLAN FONKSİYON VAR İSE
	------------------------------------
	a - Parametresi pointer ise
		parametrenin
		T * mı
		yoksa const T * mı olduğuna bak. yan okuma amaçlı mı yazma amaçlı mı.

	b - Fonksiyona NULL PTR geçme opsiyonu var mı
		opsiyon yoksa ve gönderirsek UBdir bu.

	c - geri dönüş değeri PTR ise
		static ömürlü mü, dinamik ömürlü mü 
		yoksa bizden aldığını mı bize geri veriyor.

		Bunlara çok dikkat etmek lazım.
		mesela dinamik ise free etmek lazım. 
		ve her seferinde farklı adres döndürecek.

	d - NULL PTR döndürme ihtimali var mı
		işini yapamayan Fonksiyonların NULL PTR döndürme ihtimnali var.
		bunu anlamak veya dikkat etmek.

	======================================================================
	======================================================================
	======================================================================
	======================================================================
	======================================================================
	======================================================================

	STRUCTLARI/YAPILARI KULLANARAK HİZMET VEREN KÜTÜPHANELER.
	------------------------------------------------
	2 tarz kütüphane var özünde.
	Ne gibi ?
	
	a - C tarzı kütüphane
	b - OOP tarzı kütüpane

	Mesela şöyle olacak
	kütüphane diyecek ki ben sana struct image türden yapı veriyorum.
	bunların elemanları şunlardır

	struct Image{
		size_t width;
		size_t height;
		//..
	};

a - 20 elemanlı diyelim. 20 sinide bilmek gerekiyor. Böyle kütüphaneleri kullanmak
	maliyetli.Öğrenmi yükü artıyor.Çünkü her bir elemanının nasıl kullanıldığını
	ne işe yaradığını bilmek gerekiyor.


b - Hata yapma riski artıyor.
	yapının elemanlarını yanlış değerler verilebilir.
	yapının elemanlarını aralık dışı değerler verilebilir.


c - Yapının elemanlarının birbirleriyle logic ilişkisi var.
	mesela birini değiştirince, diğerleride değişebilir.

	OOP TARZI KÜTÜPHANELER İSE

	Benim yapımın elemanları seni ilgilendirmeiyor.
		- yapının elemanlarına ulaşamıyoruz.
		- her iş için kütüphane fonksiyon veriyor.
		- elemanları değiştirmek için bile fonksiyon veriyor.
		- yapının elemanlarını client coddan tamamen gizler.

	Yapının elemanlarını gizlemenin yolu
	elemanı void * ile tutmak.

	struct Data {
		void *vp; // bunun ne olduğu implementasyonda belli oluyor.Çünkü buna member of
	};				// ile erişince hiçbir şey yapamayız. Türü belirsiz.
	
		
		// 
		// Kütüphanenin yapı türünü "INCOMPLETE TYPE" olarak vermesi
		// yapı türünün sadece eksik bildirimi var ama yapının elemanlarını gösteren bir 
		// bildirim yok.

		==========================================================================
		==========================================================================
		==========================================================================
		==========================================================================
		==========================================================================
		TIME.H
		------
		Bu modül yapı türünü kullanıyor.
		Tarih zaman işlemleriyle ilgili destek veren fonksiyonlar.
		belirli fonksiyonlarının parametlerinde bu yapı türü var.

		time_t   bu bir tamsayı türü.buna calender time denir.takvim zamanı.
		calender time = tarih zamanda bir originden geçen saniye sayısıdır.
		mesela başlangıç tarih zaman değeri ki buna epoche deniyor, bundan geçen
		saniye veya milisaniye sayısı olarak ifade edilebilir.

		NOT: Epoche başlangıç zamanı değeri. Genelde 01.01.1970 00:00 dır.
		Heryerde aynı olmaz zorunda değil.

		C de 01.01.1970 dir. bu tarihten şu kadar saniye sonrasını tutan tamsayı değeri
		time_t dir. bu hemen hemen heryerde long veya long long un typedef ismidir.
		4 veya 8 bytelık işaretli tamsayı türüdür.Bende mesela long long un eş ismi.
		8 bytelık.

		yani time_t ile ifade edilen değer, belirli bir originden geçen
		saniye sayısını ifade ediyor.buna da calender time deniyor.	
		Compilerda bir yapı türü var.
		Ayrıştırılmış zaman bilgisini içeriyor.epoche tan geçen saniye bilgisi
		çok anlam ifade etmiyor ama günler saatler biçiminde verilirse anlamlı olur.
		time.h yi kullanmak için struct tm yi bilmek lazım.
		C tarzı kütüphanedir bu.İnsanı ilgilendiren zaman bilgisine Broken-down time
		denir.


		bu yapının 9 tane elemanı var.
		struct tm
		{
			int tm_mday; //ayın günü değeri. Ayın 30 i gibi mesela
			int tm_mon; // bu 0 dan başlar ve ay değerini tutar.Mart ayı 2 mesela.
			int tm_year; // Yılın 1900 den fazlasını tutuyor. 2021 - 1900 = 121 tutar mesela
			int tm_wday; // haftanın gününü tutuyor. 0 pazar günü.1 ptesi.2 salı.
			int tm_yday; // yılın gün bilgisi.bilgisi.0 demek 1 = ocak oluyor. 1 demek =  2 ocak
			int tm_hour; // saat bilgisi. 0-24 arasında.
			int tm_min; // dakika bilgisi.
			int tm_sec; // saniye bilgisi
			int tm_isdst; // bayrak. is day light saving time demek. gün ışığı tasaruf 
						 // durumunda olduğunun bilgisi
		tm_ isdst < 0 ise
		sistemde gün ışığı tasaruf modu verisi tutulmuyor demek.
		tm_isdst == 0 ise
		sistemde gün ışığı tasaruf modu verisi var ama bu modda değiliz.
		tm_isdst > 0 ise
		sistemde gün ışığı tasaruf modu verisi var ve bu modda bulunuyoruz.

		};

		
		------------------------------------------------------------------------------------------
		------------------------------------------------------------------------------------------
		------------------------------------------------------------------------------------------
		------------------------------------------------------------------------------------------

		<time.h>
		time_t time(time_t *p); 
		bu fonksiyon aldığı adresteki veriyi set ediyor.çünkü parametre const değil.
		Eğer NULL ptr geçerse hiçbirşeyi set etmez.

		set için time_t türünden nesnenin adresi ile çağrı yapılacak
		istenmiyorsa null ptr gönderilip return değerine bakılır.



	int main()
	{
		time_t timer;

		time(&timer);

		printf("saniye = %lld\n", timer);  // burası 01.01.1970 ten geçen saniye sayısı.

	}

	----------------------------------

	// infinite loop 
	int main()
	{
		time_t timer;
		for (;;)
		{
			time(&timer);
			printf("saniye = %lld\r", timer);  // burası 01.01.1970 ten geçen saniye sayısı.
		}
	}

	-----------------------------------

	//null ptr gönderirsek, hiçbir nesneyi set etmesini istemiyoruz demek
	// bu seferde return değerinden faydalanacağız demek.
	printf("%lld",time(NULL));
	//hatta srand((unsigned)time(NULL)); burada da NULL verip geri dönüş değeri ile randomize ediliyor.

	//calender time = opeche tan geçen saniye sayısı.


	------------------------------------------------------------------------------------
	------------------------------------------------------------------------------------
	------------------------------------------------------------------------------------
	------------------------------------------------------------------------------------

	<time.h>
	struct tm *localtime(const time_t *);

	Bu time_t türden değeri değerini struct tm ye dönüştürüyor.
	yani calender time değerini broken down time a dönüştürüyor.
	brocken insanın anlayabileceği tür idi.

	struct tm *localtime(const time_t *);
	geri dönüş değeri static ömürlüdür

	NOT!!!!!
	yani timer geçen zamanı hesaplıyor.bunu localtime a argüman olarak gönderince,
	localtime ında geri deönüş değerini, struct tm ye atarsak
	insanın anlayabileceği türden saat tarih... bilgilerine bilgisine ulaşırız.

	ÖRNEK

	time_t timer;
	struct tm* p;

	time(&timer);
	p = localtime(&timer);

	// tm_mon da 0 ocak, 1 şubat,2 mart. Daha önce yazdığı lookup table içerisine yazıp.
	// oradan mart olduğunu çekebilir.pmon diye char * array tanımlanmıştı önceden içine yazıalbilir.
	// pdays te 0 pazar, 1 pazartesi, 2 salı ... gidiyor.burada da pdays diye bir char * pdays[] dizisi vardı.
	// pdays[p->tm_wday] içine yazılabilir. aylarda aynı şekilde

	printf("%02d %d %d %d ",p->tm_mday,p->tm_mon + 1,p->tm_year + 1900,p->tm_wday);

	//aşağısı saat
	printf("%02d:%02d:%02d\n",p->tm_hour,p->tm_min,p->tm_sec);


	---------------------------------------------------------------------------
	---------------------------------------------------------------------------

	Tamamen aynı yapıda gmtime var.	aynı işi yapıyor
	struct tm *gmtime(const time_t *);

	time_t timer;
	struct tm* p;

	time(&timer);
	p = gmtime(&timer); // localtime ile aynı

	printf("%02d %d %d %d ",p->tm_mday,p->tm_mon + 1,p->tm_year + 1900,p->tm_wday);
	printf("%02d:%02d:%02d\n",p->tm_hour,p->tm_min,p->tm_sec);

	NOT:
	EPOCHE değeri set edilemez.

	----------------------------------------------------------
	----------------------------------------------------------

	char *ctime(const time_t *t);
	char *asctime(const struct tm *p);
	

	int main()
	{
		time_t timer;
		time(&timer);

		const char* p = ctime(&timer);

		printf("tarih yazisi uzunlugu %zu\n", strlen(p));

		// p nin son karakteri newline. bununla beraber 26 karakter.
		// new line dan sonra ) görülecek bu sebeple :D
		printf("(%s)", p);
	}
	
	--------------------------------------------------------------------
	--------------------------------------------------------------------

	asctime da ise localtime return değerini argüman olarak gönderiyoruz.

	int main()
	{
		time_t timer;
		time(&timer);

		struct tm* tptr = localtime(&timer);
		const char* p2 = ctime(&timer);
		const char* p1 = asctime(tptr);

		printf("tarih yazisi uzunlugu %zu\n", strlen(p1));
		printf("(%s)\n", p1);
		printf("(%s)\n", p2);

		//derleyici standartlara uygun mu?
		printf("\n%p  %p\n", p1, p2);
	}
	
	-----------------------------------------------------------------------------
	-----------------------------------------------------------------------------
	-----------------------------------------------------------------------------
	-----------------------------------------------------------------------------
	-----------------------------------------------------------------------------
	
	Ders bitti

	time_t = calender time tutar
	struct tm = ayrıştırılmış zaman bilgisi tutar
	clock_t = iki time point arasındaki geçen süreyi tutan tür.

	clock_t clock(void); 
	bu fonksiyon mainin çağrılması ile clock fonksiyonunun çağrılması arasıda geçen süre.
	türü saniye değil. tick count türünde.
	bunu SANİYE türüne çevirmek için CLOCKS_PER_SEC macrosuna bölmek gerekiyor.


	sprintf NEDİR?

sprintf = string print formatted

Formatlı çıktıyı ekrana değil, bir karakter dizisine yazar

Yani:

printf  → stdout
sprintf → char buffer

2️⃣ TANIMI
#include <stdio.h>

int sprintf(char *str, const char *format, ...);

Parametreler:
Parametre	Açıklama
str	Yazılacak buffer
format	Format string
...	Değişken sayıda argüman
Dönüş:

Yazılan karakter sayısı

\0 dahil değil

3️⃣ NE İŞE YARAR?

Bir string oluşturmak için:

char buf[100];
sprintf(buf, "Sayi = %d", 42);


Sonuç:

buf = "Sayi = 42"

4️⃣ BASİT ÖRNEKLER
char s[50];

sprintf(s, "%d", 123);        // "123"
sprintf(s, "%f", 3.14);       // "3.140000"
sprintf(s, "%02d", 7);        // "07"
sprintf(s, "%s %d", "age", 20); // "age 20"

5️⃣ EN BÜYÜK TEHLİKE ⚠️
❌ BUFFER OVERFLOW

sprintf:

Buffer boyutunu BİLMEZ

Taşma kontrolü YOK

char buf[10];
sprintf(buf, "Bu yazi cok uzun"); // 💥 UB


📌 Undefined Behavior

Stack bozulur

Program çöker

Sessiz bug üretir
	
*/	

struct {
	int a, b, c;
}x,y,z;

struct demo
{
	
	
	double b;
	char c;
	int a;
};

int main()
{
	x.a=15;
	x.b=56;
	x.c = 98;

	printf("%d,%d,%d\n\n",x.a,x.b,x.c);

		char buffer[100];
		int d, m, y;

		printf("gun ay ve yil olarak tarih girin : ");
		scanf("%d%d%d", &d, &m, &y);
		printf("%02d-%02d-%02d\n",d,m,y);
	
		// bu formattaki yazıyı elde etmek için sprintf kullanılır
		sprintf(buffer,"%02d-%02d-%02d", d, m, y);

		puts(buffer);	
		struct  demo demo1;
		
		
		printf("size of demo structure: %zu",sizeof(demo1));


}