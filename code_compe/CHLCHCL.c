#include<stdio.h>
int main()
{
    int t, m, n, test;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        if(n % 2 == 0 || m % 2 == 0)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
