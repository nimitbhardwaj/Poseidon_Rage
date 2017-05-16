#include<stdio.h>
int main()
{
    unsigned int t, n, k, fi;
    scanf("%u", &t);
    while(t--)
    {
        scanf("%u", &n);
        k = 5;
        fi = 0;
        while(n / k)
        {
            fi += n / k;
            k *= 5;
        }
        printf("%u\n", fi);
    }
    return 0;
}
