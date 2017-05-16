#include<stdio.h>
int main()
{
    int t, n, m = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        while(n)
        {
            if(n % 10 == 4)
                m++;
            n /= 10;
        }
        printf("%d\n", m);
        m = 0;
    }
    return 0;
}
