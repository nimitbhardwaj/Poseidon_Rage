#include<stdio.h>
#include<limits.h>
#include<malloc.h>
int main()
{
    int n, m, i;
    int min;
    int j;
    int *A, *B;
    scanf("%d %d", &n, &m);
    A = (int *) malloc(sizeof(int) * n);
    B = (int *) malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    for(i = 0; i < n; i++)
    {
        min = INT_MAX;
        for(j = 0; j < n; j++)
        {
            if(j == i)
                continue;
            else
            {
                if(A[i] % A[j] == 0)
                {
                    if(min > A[j])
                        min = A[j];
                }
            }
        }
        B[i] = min;
        if(min == INT_MAX)
            B[i] = -1;
    }
    for(i = 0; i < m; i++)
    {
        scanf("%d", &j);
        printf("%d\n", B[j - 1]);
    }
    free(A);
    free(B);
    return 0;
}
