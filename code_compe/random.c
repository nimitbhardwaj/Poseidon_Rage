#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int N, i, q, ty;
    srand(clock());
    N = rand() % 1000 + 1;
    printf("%d\n", N);
    for(i = 1; i <= N; i++)
        printf("%d ", rand() % 1000000000 + 1);
    q = rand();
    printf("\b\n%d", q);
    for(i = 1; i <= q; i++)
    {
        ty = rand() % 2 + 1;
        printf("%d ", ty);
        if(ty == 1)
            printf("%d %d\n", rand() % N + 1, rand() % 1000000000 + 1);
        if(ty == 2)
            printf("%d\n", rand() % N + 1);
    }
    return 0;
}
