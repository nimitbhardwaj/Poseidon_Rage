#include<stdio.h>
int hcf(int *, int);
int main()
{
    int t, n, i, A[50], h;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &A[i]);
        h = hcf(A, n);
        for(i = 0; i < n; i++)
            printf("%d ",  A[i] / h);
        printf("\n");

    }
    return 0;
}

int hcf(int *A, int n)
{
    int min = 1001, i, j, h, k = 0;
    for(i = 0; i < n; i++)
        if(min > A[i])
            min = A[i];
    for(i = 1; i <= min; i++)
    {
        for(j = 0; j < n; j++)
            if( A[j] % i != 0 )
            {
                k = 1;
                break;
            }
        if(k == 0)
        {
            h = i;
        }
        k = 0;
    }
    return h;
}
