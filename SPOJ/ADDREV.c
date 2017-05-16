#include<stdio.h>
int rev(int);
int main()
{
    int t, m, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &m, &n);
        m = rev(m);
        n = rev(n);
        m = m + n;
        m = rev(m);
        printf("%d\n", m);
    }
    return 0;
}

int rev(int a)
{
    int rev = 0;
    while(a)
    {
        rev = rev * 10 + a % 10;
        a /= 10;
    }
    return rev;
}
