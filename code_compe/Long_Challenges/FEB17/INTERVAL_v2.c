#include <stdio.h>

typedef long long int lld;

int main()
{
    lld t, n, m, i, a, kapa;
    lld Narr[300100], Marr[1000], Sarr[300100];
    scanf("%lld", &t);
    while(t--)
    {
        Sarr[0] = 0;
        scanf("%lld %lld", &n, &m);
        for(i = 0; i < n; i++)
        {
            scanf("%lld", &a);
            Narr[i] = a;
            Sarr[i + 1] = Sarr[i] + Narr[i];
        }
        for(i = 0; i < m; i++)
        {
            scanf("%lld", &a);
            Marr[i] = a;
        }
        for(i = 0; i < n; i++)
        {
        
        }
        for(i = m - 1; i >= 0; i--)
        {
        }
    }
    return 0;
}
