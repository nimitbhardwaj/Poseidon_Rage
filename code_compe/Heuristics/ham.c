#include<stdio.h>
typedef unsigned long long int ull;
int main()
{
    ull t, n, m;
    scanf("%llu", &t);
    while(t--)
    {
        scanf("%llu %llu", &n, &m);
        if(n % 2llu == 0llu)
            n = n / 2;
        else
            n = n / 2 + 1llu;
        if(n <= m)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
