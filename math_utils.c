#include "math_utils.h"

// SADECE BU DOSYADA KULLANILACAK*başka dosyada görünmez.
static int normalize(int x)
{
    if (x < 0)
        return -x;
    return x;
}
static int value = 40;
// DIŞARIYA AÇIK
 int add(int a, int b)
{
    return normalize(a) + normalize(b);
}
