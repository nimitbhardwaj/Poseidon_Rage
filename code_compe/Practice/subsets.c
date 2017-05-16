#include<stdio.h>
#include<stdlib.h>
int *mask(int *, int, int, int*);
int main()
{
    int Arr[100], n, i, *p, j, m;
    scanf("%d", &n);
    for(i = 0; i <n; i++)
        scanf("%d", &Arr[i]);
    for(i = 1; i< (1 << (n)); i++)
    {
        p = mask(Arr, i, n, &m);
        for(j = 0; j < m; j++)
            printf("%d ", p[j]);
        puts("");
    }
    return 0;
}

int *mask(int *A, int mask, int n, int *m)
{
    int *p, val, i, si = 0;
    p = (int *) malloc(sizeof(int) * n);

    for(i = 0; i < n; i++)
    {
        val = mask % 2;
        val = A[i] * val;
        mask /= 2;
        if(val == 0)
            ;
        else
        {
            *(p + si) = val;
            si++;
        }
    }
    *m = si;
    return p;
}
