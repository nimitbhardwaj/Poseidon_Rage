#include<stdio.h>
#include<malloc.h>
#include<math.h>
long long int *Sieve(long long int);
long long int *segmentedSieve(long long int, long long int, long long int *);
int main()
{
    long long int t, n, m, *basic, *sieve;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &m);
        basic = Sieve(m);
        sieve = segmentedSieve(n, m, basic);
        free(basic);
        free(sieve);
    }
    return 0;
}

long long int *Sieve(long long int N)
{
    long long int sq, i, j;
    long long int *p;
    sq = sqrt(N);
    p = (long long int *) malloc(sizeof(long long int) * (sq + 1));
    p[0] = p[1] = 1;
    for(i = 2; i * i <= sq; i++)
    {
        if(p[i] == 0)
        {
            for(j = i * i; j <= sq; j += i)
                p[j] = 1;
        }
    }
    return p;
}

long long int *segmentedSieve(long long int a, long long int b, long long int *A)
{
    long long int *p;
    long long int sq, i = a, kapa = a, j, napa = a;
    p = (long long int *) malloc(sizeof(long long int) * (b - a + 1));
    //puts("Howdy");
    sq = sqrt(b);
    for(i = a; i <= b; i++)
    {
        kapa = 0;
        for(j = 2; j <= sq; j++)
        {
            if(i % j == 0)
            {
                if(i == j)
                    break;
                p[i - napa] = 1;
                kapa = 1;
                break;
            }
        }
        if(kapa == 0 && i != 1)
            printf("%lld\n", i);
    }
    if(a == 1)
        p[0] = 1;
    return p;

}
