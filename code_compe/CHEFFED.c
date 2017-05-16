#include<stdio.h>
int S(int);

int main()
{
    int n, i, a, b, res = 0;
    scanf("%d", &n);
    if(n < 1000000)
        for(i = n - 1; i >= n / 10; i--)
        {
            a = S(i);
            b = S(a);
            if(a + b + i == n)
                res++;
        }
    else
        for(i = n - 1000; i < n; i++)
        {
            a = S(i);
            b = S(a);
            if(a + b + i == n)
                res++;
        }
    printf("%d\n", res);
    return 0;
}

int S(int a)
{
    int n = 0;
    while(a)
    {
        n += a % 10;
        a = a / 10;
    }
    return n;
}
