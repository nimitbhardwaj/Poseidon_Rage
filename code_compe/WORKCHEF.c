#include<stdio.h>
long long int isSpecial(long long int, long long int);
int main()
{
    long long int t, L, R, K, i, special;
    scanf("%lld", &t);
    while(t--)
    {
        special = 0;
        scanf("%lld %lld %lld", &L, &R, &K);
        for(i = L; i <= R; i++)
        {
            if(isSpecial(i, K))
                special++;
        }
        printf("%lld\n", special);
    }
    return 0;
}

long long int isSpecial(long long int n, long long int k)
{
    long long int l = n, i, kappa = 0, arr[10];
    while(l)
    {
        i = l % 10;
        if(i != 0)
        {
            if(n % i == 0 && arr[i - 1] == 0)
                kappa++, arr[i - 1] = 1;
        }
        l /= 10;
    }
    if(kappa >= k)
        return 1;
    else
        return 0;
}
