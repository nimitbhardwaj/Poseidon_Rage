#include <stdio.h>
int main()
{
    long long int t, R, G, B, k, i, j, n=1;
    scanf("%lld", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld %lld %lld\n%lld", &R, &G, &B, &k);
        k--;
        for (j=1; j<=k; j++)
        {
            if(R!=0)
            {
                R--;
                n++;
            }
            if(G!=0)
            {
                G--;
                n++;
            }
            if(B!=0)
            {
                B--;
                n++;
            }
        }
        printf("%lld\n", n);
        n=1;
    }
    return 0;
}
