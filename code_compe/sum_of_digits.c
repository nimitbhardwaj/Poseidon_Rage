#include<stdio.h>
int main()
{
    int t, n, s = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        while(n)
        {
            s += n % 10;
            n /= 10;
        }
        printf("%d\n", s);
        s = 0;
    }
    return 0;
}
