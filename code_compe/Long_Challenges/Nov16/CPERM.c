#include <stdio.h>
#define MOD 1000000007
unsigned long long int PowMod(unsigned long long int n, unsigned long long int e);
int main()
{
    unsigned long long int t, n, product;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        n -= 1;
        if(n == 1 || n == 0)
            printf("%lld\n", 0llu);
        else if(n < 30)
            printf("%lld\n", (1llu << n) - 2llu);
        else
        {
            product = PowMod(2llu, n);
            printf("%lld\n", product - 2);
        }
    }
    return 0;
}
unsigned long long int PowMod(unsigned long long int n, unsigned long long int e)
{
    unsigned long long int res;
    if(e == 0)
        res = 1;
    else if(e == 1)
        res = n;
    else
    {
        res = PowMod(2, e / 2);
        res = (res * res) % MOD;
        if(e % 2)
            res = (res * n) % MOD;
    }
    return res;
}
