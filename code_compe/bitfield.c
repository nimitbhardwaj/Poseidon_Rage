#include<stdio.h>
typedef struct bitfield
{
    unsigned int a:4;
} Bit;
int main()
{
    Bit a;
    a.a = 10;
    printf("%u %lu", a.a, sizeof(a));
    return 0;
}
