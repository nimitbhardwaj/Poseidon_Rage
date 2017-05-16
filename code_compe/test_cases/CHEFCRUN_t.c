#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int t, i, n, j, a, b;
    time_t ti;
    scanf("%d", &t);
    srand((unsigned) time(&ti));
        printf("%d\n", t);
    for(i = 0; i < t; i++)
    {
        n = rand() % 5 + 1;
        printf("%d\n", n);
        for(j = 0; j < n; j++)
            printf("%d ", (-5 + rand() % 15));
        printf("\n");
        a = rand() % n + 1;
        b = rand() % n + 1;
        if(a > b)
            printf("%d %d", b, a);
        else
            printf("%d %d", a, b);
        printf("\n");
    }
    return 0;
}
