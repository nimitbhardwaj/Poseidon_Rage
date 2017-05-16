#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<math.h>
#define MAX 1000000
int A[MAX];
void sieve(int);
long long int ncr(int, int);
int main()
{
    int t, n, k, i;
    long long int res;
    sieve(MAX);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        n--;
        k--;
        if(k > n - k)
            k = n - k;
        printf("%lld\n", ncr(n, k));
    }
    return 0;
}

void sieve(int n)
{
    memset(A, 0, MAX);
    int i, j;
    A[0] = A[1] = 1;
    for(i = 2; i * i < MAX; i++)
    {
        if(A[i] == 0)
        {
            for(j = i * i; j < MAX; j += i)
                A[j] = 1;
        }
    }
}

