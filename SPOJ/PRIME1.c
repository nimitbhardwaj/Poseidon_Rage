#include<stdio.h>
#include<malloc.h>
#define MAX 1000000
int* sieve(int);
int main()
{
    int *Sieve;
    Sieve = sieve(MAX);
    int n, m, t, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(i = n; i <= m; i++)
            if(Sieve[i] == 0)
                printf("%d\n", i);
    }
    return 0;
}

int *sieve(int n)
{   
    int *p, i, j;
    p = (int *)malloc(sizeof(int) * n + 2);
    p[0] = p[1] = 1;
    for(i = 2; i * i <= n; i++)
    {
        if(p[i] == 0)
        {
            for(j = i * i; j <= n; j++)
                if(j % i == 0)
                    p[j] = 1;
        }
    }
    return p;
}
