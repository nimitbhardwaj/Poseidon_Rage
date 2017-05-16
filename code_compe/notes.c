#include<stdio.h>
int main()
{
    int t, n, sum = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);

        sum += n / 100;
        n %= 100;
        sum += n / 50;
        n %= 50;
        // sum += n / 20;
        // n %= 20;
        sum += n / 10;
        n %= 10;
        sum += n / 5;
        n %= 5;
        sum += n/2;
        n %= 2;
        sum += n/1;
        n %= 1;
        printf("%d\n", sum);
        sum = 0;
    }
    return 0;
}
