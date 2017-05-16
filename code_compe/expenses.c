#include<stdio.h>
int main()
{
    int t, n, p;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &p);
        if(n > 1000)
            printf("%f\n", n * p - n * p * 10.0/100.0);
        else
            printf("%f\n", ((float)n) * p);
    }
    return 0;
}
