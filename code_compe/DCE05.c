#include<stdio.h>

int survivor(int);
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", survivor(n));
    }
    return 0;
}

int survivor(int n)
{
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    if(n % 2 == 0)
        return 2 * survivor(n / 2);
    else
        return 2 * survivor((n - 1) / 2);
}
