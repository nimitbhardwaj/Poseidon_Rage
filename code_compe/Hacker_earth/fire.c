#include<stdio.h>
#include<malloc.h>
int main()
{
    int t, n, *A, i, total_time;
    scanf("%d", &t);
    while(t--)
    {
        total_time = 0;
        scanf("%d", &n);
        A = (int *) malloc(sizeof(int) * n);
        for(i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for(i = 0; i < n; i++)
        {
            if(A[i] >= total_time)
                total_time += A[i] - total_time + 1;
        }
        printf("%d\n", total_time);
        free(A);
    }
    return 0;
}
