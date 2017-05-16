#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int i, j, t, max, n;
    time_t tim;
    srand(time(&tim));
    scanf("%d %d", &t, &max);
    printf("%d\n", t);
    for(i = 0; i < t; i++)
    {
        printf("%d\n", max);
        for(j = 0; j < max; j++)
        {
            printf("%d ", (int) rand() % 1000000000);
        }
        printf("\n");
    }
    return 0;
}
