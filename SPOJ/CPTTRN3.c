#include<stdio.h>
int main()
{
    int t, a, b, i, j;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &a, &b);
        for(i = 0; i < 3 * a; i++)
        {
            if(i % 3 == 0)
            {
                for(j = 0; j < 3 * b; j++)
                    putchar('*');
                putchar('*');
            }
            else if(i % 3 == 1 || i % 3 == 2)
            {
                for(j = 0; j < 3 * b; j++)
                {
                    if(j % 3 == 0)
                        putchar('*');
                    else
                        putchar('.');
                }
                putchar('*');
            }
            putchar('\n');
        }
        for(i = 0; i < 3 * b; i++)
            putchar('*');
        puts("*\n");
    }
    return 0;
}
