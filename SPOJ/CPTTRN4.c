#include<stdio.h>
int main()
{
    int t, a, b, w, h, i, j;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d", &a, &b, &h, &w);
        for(i = 0; i < (h + 1) * a; i++)
        {
            if(i % (h + 1) == 0)
            {
                for(j = 0; j < (w + 1) * b; j++)
                    putchar('*');
            }
            else
            {
                for(j = 0; j < (w + 1) * b; j++)
                {
                    if(j % (w + 1) == 0)
                        putchar('*');
                    else
                        putchar('.');
                }
            }
            puts("*");
        }
        for(i = 0; i < (w + 1) * b; i++)
            putchar('*');
        putchar('*');
        puts("");
    }
    return 0;
}
