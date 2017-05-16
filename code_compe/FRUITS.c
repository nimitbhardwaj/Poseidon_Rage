#include<stdio.h>
int mini(int, int);
int main()
{
    int t, n, m, k, max, min;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &m, &k);
        min = mini(m, n);
        max = m + n - min;
        printf("%d\n", max - mini(min + k, max));
    }
    return 0;
}

int mini(int a, int b)
{
    if(a > b)
        return b;
    else
        return a;
}
