#include<stdio.h>
void sort(int *, int);
void swap(int *, int *);
int main()
{
    int t, n, k, i;
    int A[10000];
    float avg = 0.0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        for(i = 0; i < n; i++)
            scanf("%d", &A[i]);
        sort(A, n);
        for(i = k; i < n - k; i++)
            avg += A[i];
        avg /= n - 2 * k;
        printf("%f\n", avg);
        avg = 0.0;

    }
    return 0;
}


void sort(int *A, int n)
{
    int i, j, k;
    for(i = 1; i < n; i++)
    {
        k = i;
        for(j = i - 1; j >= 0; j--)
        {
            if(A[k] < A[j])
                swap(&A[k], &A[j]), k = j;
        }
    }
}


void swap(int *a, int *b)
{
    int p, *q;
    p = *a;
    *a = *b;
    *b = p;
}
