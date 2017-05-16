#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int cmp(const void *a, const void *b);
int main()
{
    int n, i;
    int *A;
    scanf("%d", &n);
    A = (int *) malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);
    qsort(A, n, sizeof(int), cmp);
    for(i = 0; i < n; i++)
        printf("%d ", A[i]);
    puts("");
    return 0;
}

int cmp (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
