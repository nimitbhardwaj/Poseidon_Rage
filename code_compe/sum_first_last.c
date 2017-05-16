#include<stdio.h>
int main()
{
    int t, n, le, me;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        le = n % 10;
        while(n != 0)
        {
            me = n % 10;
            n /= 10;
        }
        printf("%d\n", me + le);
    }
    return 0;
}
