#include<stdio.h>
#include<malloc.h>
#include<math.h>
int LeastPrimeDivisor(int, int *);
int *Seep(int);
int maxy(int, int);
int main()
{
    int t, n, m, i, dumm, type, j, L, R, result;
    int *A, *sieve;
    scanf("%d", &t);
    sieve = Seep(100000);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        A = (int *) malloc(n * sizeof(int));
        for(i = 0; i < n; i++)
        {
            scanf("%d", &dumm);
            A[i] = dumm;
        }
        for(i = 0; i < m; i++)
        {
            scanf("%d", &type);
            if(type == 0)
            {
                scanf("%d %d", &L, &R);
                for(j = L - 1; j <= R - 1; j++)
                    A[j] = A[j] / LeastPrimeDivisor(A[j], sieve);
            }
            else
            {
                result = 1;
                scanf("%d %d", &L, &R);
                for(j = L - 1; j <= R - 1; j++)
                    result = maxy(result, LeastPrimeDivisor(A[j], sieve));
                printf("%d\n", result);
            }
        }
        free(A);
    }
    free(sieve);
    return 0;
}


int *Seep(int n)
{
    int sq = (int)sqrt(n);
    int i, *sieve, j;
    sieve = (int *)malloc((n + 1) * sizeof(int));
    for(i = 2; i <= sq; i++)
    {
        if(sieve[i - 2] == 0)
        {
            for(j = i * i; j <= n; j += i)
                sieve[j - 2] = 1;
        }
    }
    return sieve;
}

int LeastPrimeDivisor(int n, int *sieve)
{
    int i, j;
    if(n == 1)
        return 1;
    if(sieve[n - 2] == 0)
        return n;
    for(i = 0; i < 1000000; i++)
    {
        if(sieve[i] == 0)
        {
            if(n % (i + 2) == 0)
            {
                //printf("%d\n", i + 2);
                return i + 2;
            }
        }
    }
    return 1;
}

inline int maxy(int a, int b) {return a > b ? a : b;}
