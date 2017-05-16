#include<stdio.h>
#define LEN 10000
long long int comparitor(long long int *, long long int *, long long int);

int main()
{
    long long int t, i, n, j, a0=0, ai;

    long long int arr1[LEN]={0}, arr2[LEN]={0};
    scanf("%lld", &t);
    for(i = 1; i<=t; i++)
    {
        scanf("%lld", &n);
        for(j=0; j<n; j++)
        {
            scanf("%lld", &ai);
            arr1[j] = ai - a0;
            a0 = ai;
        }
        a0 = 0;
        for(j=0; j<n;j++)
        {
            scanf("%lld", &arr2[j]);
        }

        //for(j=0; j<n;j++)
        //{
            printf("%lld\n", comparitor(arr1, arr2, n));
        //}

    }
    return 0;
}

long long int comparitor(long long int *a, long long int *b, long long int n)
{
    long long int i = 0, r = 0;
    while(i < n)
    {
        if(*a>= *b)
            r++;
        i++;
        a++;
        b++;
    }
    return r;
}
