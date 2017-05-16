#include<stdio.h>
#include<malloc.h>
int Kadane(int *, int);
int max(int, int);
int main()
{
    int t, *A, n, i, start, end, *clk, *c_clk, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        A = (int *) malloc(n * sizeof(int));
        for(i = 0; i < n; i++)
            scanf("%d", &A[i]);
        scanf("%d %d", start, end);
        clk = (int *) malloc((end - start + 1) * sizeof(int));
        c_clk = (int *) malloc((n - (end - start - 1)) * sizeof(int));
        for(i = start, k = 0; i <= end; i++, k++)
            clk[k] = A[i - 1];
        for(i = end - 1, k = 0; i != start; i = (i + 1) % n, k++)
            c_clk[k] = A[i];
    }
    return 0;
}

int Kadane(int *A, int n)
{
    int max_ending = 0, max_so_far = 0, i;
    for(i = 0; i < n; i++)
    {
        max_ending = max(0, max_ending);
        max_so_far = max(max_so_far, max_ending);
    }
    return max_so_far;
}


inline int max(int a, int b){return a > b ? a : b;}


