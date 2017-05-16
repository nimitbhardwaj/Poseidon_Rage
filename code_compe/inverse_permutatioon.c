#include<stdio.h>
#include<malloc.h>
int *inv(int*, int);
int main()
{
    int A[100000], n, i, *B, k = 0;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
        }
        B = inv(A, n);
        for(i = 0; i < n; i++)
        {
            if(A[i] != B[i])
            {
                k = 1;
                break;
            }
        }
        printf(k == 0? "ambiguous\n":"not ambiguous\n");
        k = 0;
        free(B);
    }
    return 0;
}

int *inv(int *A, int n)
{
    int *B, i;
    B = (int *) malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
    {
        B[A[i] - 1] = i + 1;
    }
    return B;
}
