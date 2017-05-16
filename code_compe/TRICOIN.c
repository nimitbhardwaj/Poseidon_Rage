#include<stdio.h>
int main()
{
    int t, n, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        i = 1;
        while(n >= i * (i + 1) / 2)
        {
            i++;
        }
        printf("%d\n", i - 1);
    }
}
