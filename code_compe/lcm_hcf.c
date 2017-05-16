#include<stdio.h>
int lcm(int, int);
int hcf(int, int);
int main()
{
    int t, a, b, c, d;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &a, &b);
        c = hcf(a, b);
        d = lcm(a, b);
        printf("%d %d\n", c, d);
    }
    return 0;
}
int lcm(int a, int b)
{
    int c = (a > b)? a : b, i;
    for(i = c; ; i++)
    {
        if(i % a == 0 && i % b == 0)
            return i;
    }
}

int hcf(int a, int b)
{
    int c = (a > b)? a:b, i;
    for(i = c; i > 0; i--)
    {
        if(a % i == 0 && b % i == 0)
            return i;
    }
}
