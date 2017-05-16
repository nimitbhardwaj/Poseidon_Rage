#include<stdio.h>
int main()
{
    int t, n, r = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n > 2048)
        {
            r += n / 2048;
            n = n % 2048;
        }
        while(n)
        {
            r += n % 2;
            n = n / 2;
        }
        printf("%d\n", r);
        r = 0;
    }
    return 0;
}
