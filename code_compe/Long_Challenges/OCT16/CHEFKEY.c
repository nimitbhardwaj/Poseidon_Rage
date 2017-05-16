#include<stdio.h>
int main(void)
{
    int t, n, m, c, i, max, res, k;
    scanf("%d", &t);
    while(t--)
    {
        res = 0;
        scanf("%d %d %d", &n, &m, &c);
        for(i = 1; i <= n; i++)
        {
            if(c % i == 0)
            {
                k = c / i;
                if(k <= m)
                    res++;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
