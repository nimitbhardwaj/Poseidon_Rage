#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<malloc.h>
int comp(const void *, const void *);
unsigned long long int euler_hcf(unsigned long long int, unsigned long long int);
int main()
{
    unsigned long long int t, n, i, j, min = LONG_MAX, kapa;
    unsigned long long int *A;
    scanf("%llu", &t);
    while(t--)
    {
        min = INT_MAX;
        scanf("%llu", &n);
        A = (unsigned long long int *) malloc(sizeof(unsigned long long int) * n);
        for(i = 0; i < n; i++)
        {
            scanf("%llu", &A[i]);
        }
        /*qsort(A, n, sizeof(int), comp);*/
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(i == j)
                    continue;
                kapa = (A[i] * A[j]) / euler_hcf(A[i], A[j]);
                printf(">>%llu\n", kapa);
                if(kapa < min)
                    min = kapa;
            }
        }
        printf("%llu\n", min);
        free(A);
    }
    return 0;
}

int comp(const void *A, const void *B)
{
    return *((int *)A) - *((int *)B);
}
unsigned long long int euler_hcf(unsigned long long int a, unsigned long long int b)
{
    unsigned long long int tmp, kapa = 1;
    if(a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    while(kapa)
    {
        kapa = a % b;
        a = b;
        b = kapa;
    }
    return a;
}
