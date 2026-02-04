#include <stdio.h>
#include <string.h>
/*
C içerisinde büyük bir yazıyı küçük bir array e kopyalamak UB.
C de  sonu _s ile biten fonksiyonlar var Secure dan geliyor.

void my_puts(const char* p)
{
    while(*p)//null değilse
        putchar(*p++);//elemanı ekrana yazdırıp adresi bir artırıyor.

    putchar('\n');
}  
    
char * my_gets(char* p)
{
    int c;
    char  *ptemp= p;//dizinin başlangıç adresini alıyoruz return etmek için.
    //burada alıyoruz çünkü aşağıda p  artacak.

    while ((c= gerchar() != '\n') && c != EOF)//EOF= std giriş akımının buffer ı boşsa gene girmeyecek.
    {
        *p++=(char) c;//adresi artırıp içine yazıyoruz.
    }
        *p='\0';

        return ptemp;

    }
===============================================================================

bazı string fonksiyonları
	strlen
	strchr
	strstr
	strcpy
	strcat
	strrchr
	strcmp
	strspn
	strcspn
	strncpn
	strncat
	strncmp 
===============================================================================

size_t strlen(const char *p);
bir yazının uzunluğunu buluyor. yazının adresini alıyor.
Bu fonksiyona Null ptr geçmek UB.

Geri dönüş değerini de aynı şekilde saklamak mantıklı.
size_t len = strlen(str);

size_t yi printf ile yazdırmak için %zu conversion specifier kullanmak mantıklı.
size_t len = strlen(str);
printf("%zu\n",len);

kodunu manuel olarak aşağıdaki gib yazabiliriz

size_t my_strlen(const char* p)
{
    size_t len = 0;

    while(*p++)// *p != null denebilirdi.
        len++;

    return len;

}
=======================================

strchr -> bu bir yazı içerisindeki bir karakteri arıyor.

char* my_strchr(const char * p, int c)
{
    while(*p)
    {
        if(*p == c)
        {
            return (char*)(p);
            p++;
        }
    
    }
        if (c == '\0')
            return (char *)p;

    return NULL;
}
    char a;
	a = (char)getchar(); // veya (void)scanf("%c", &a);

	char *p = my_strchr(str, a);

	if (p)
	{
		printf("%d indisli eleman  - > %p  =   %c\n",p-str, p, *p);
		*p = '!';
		my_puts(str);
	}
	else
		printf("bulunamadi");


	p = strchr(str,'\0');
	*p++ = 'X';
	*p = '\0';
	puts(str);

	===========================================================
	===========================================================

	NULL						'\0'
	------------------------|--------------------	
	symbolic constant		|	character constant
	pointer degiskenlere	|	s[i] = '\0';


	Bu ikisinin bir arada kullanıldığı yer

	if(ptr != NULL && *ptr != '\0')
	burada eğer pointer null değilse demek istiyor ilk ifadede
	ikincisinde ise dereference edilen pointer değeri null character değilse demektir

	aşağıdaki gibide yazılabilir.
	if(ptr && *ptr)

	Tam tersi - de morganı hatırla
	if(!ptr || !*ptr)    -> ptr null ise veya *ptr null character ise.
	uzunda yazılabilir.short circuit te olabilir.

	====================================================================
	====================================================================

    strrchr -> yazıda karaterin geçtiği son yeri bulur.
	char * strrchr(const char *p, int ch);


	----------------------
	ör:

	char str[SIZE];
	char* p;
	printf("bir yazi giriniz\n");
	my_gets(str);

	printf("bir karakter girin\n");
	char c = getchar();
	printf("arama strrchr ile yapiliyor.\n");
	p = strrchr(str, c);

	if (p)
	{
		printf("yazinin bulundugu %d indisli karakteri\n", p - str);
		*p = '*';
		puts(str);
	}
	else
		printf("bulunamadi\n");

	--------------------------------------------------
	--------------------------------------------------

	kodu aşağıda

	char* my_strrchr(const char * p, int c)
	{
		// 2 yol var. birincisi kötü. yazının sonuna gidip. sonra geri gelirken
		// ilk bulunan yerde return edilir. ama dezavantaja. çok büyük ise yazı.
		// en sona gitmek geri gelmek çok maaliyetli.

		// verimli yol aşağıda.

		const char* pfound = NULL;

		while (*p)
		{
			if (*p == c) // burada 10 kerede denk gelse en son denk gelenin indisini tutar
				pfound = p;
			++p;
		}

		if (c == '\0') // eğer c null char ise zaten artırılmış olan p yi return eder.
			return (char*)p;	// çünkü p buraya geldiyse en son olan '\0'tedir.

		return (char*)pfound;


	char str[SIZE];
	char* p;
	printf("bir yazi giriniz\n");
	my_gets(str);

	printf("bir karakter girin\n");
	char c = getchar();
	printf("arama strrchr ile yapiliyor.\n");
	p = my_strrchr(str, c);

	if (p)
	{
		printf("yazinin bulundugu %d indisli karakteri\n", p - str);
		*p = '*';
		puts(str);
	}
	else
		printf("bulunamadi\n");

	}


	=================================================================
    int my_strcmp(const char* p1, const char* p2)
{
	while (*p1 == *p2) // iki değerde birbirine eşitse
	{
		if (p1 == '\0') // bu değerlerden biri null chr ise diğeride null chr dir.
			return 0; // return 0 strcmp nin kullanım şekli.eşitse 0.
		p1++;
		p2++;
	}
	
	return *p1 - *p2; // diyelimki eşit değiller. p1 büyükse pozitif değer. diğeri büyükse
}						// negatif değer. biri bitmişse bile sondaki '\0'ın değeri 0 dır.
						// ve işlemler değer - 0 veya 0 - değer şeklinde olabilir.çok mantıklı.

	=================================================================

	daha detaylı bilgi için 31 ve 32 ya bak.

*/
int main()
{


}