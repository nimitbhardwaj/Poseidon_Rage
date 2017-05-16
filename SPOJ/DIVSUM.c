#include<stdio.h>
int main()
{
    int t, n, s, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        s = 0;
        for(i = 1; i < n; i++)
            s += n % i == 0 ? i : 0;
        printf("%d\n", s);
    }
    return 0;
}
