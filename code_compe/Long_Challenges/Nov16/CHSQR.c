#include<stdio.h>
int main()
{
    int i, j, k, t, kapa, napa;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &k);
        kapa = (k + 1) / 2;
        for(i = kapa; i >= 1; i--)
        {
            napa = i;
            for(j = 0; j < k; j++)
            {
                printf("%d ", napa);
                if(napa == k)
                    napa = 0;
                napa++;
            }
            putchar('\n');
        }
        kapa = k;
        while(kapa > (k + 1) / 2)
        {
            napa = kapa;
            for(i = 0; i < k; i++)
            {
                printf("%d ", napa);
                if(napa == k)
                    napa = 0;
                napa++;
            }
            putchar('\n');
            kapa--;
        }

    }
    return 0;
}
