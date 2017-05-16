#include<stdio.h>
int main()
{
    int t, n, i, a;
    scanf("%d", &t);
    while(t--)
    {
        a = 0;
        scanf("%d", &n);
        for(i = 0; ; i++)
        {
            a += 9 * (i) + 1;
            if(a >= n)
                break;
        }
        printf("%d\n", i + 1);
    }
    return 0;
}
