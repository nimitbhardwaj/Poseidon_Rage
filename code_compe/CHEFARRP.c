#include<stdio.h>
#include<malloc.h>
int *subarray(int *, int, int, int *);
int main()
{
    int t, n, i, j, Arr[10000], *a, prod, sum, res, len;
    scanf("%d", &t);
    while(t--)
    {
        res = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &Arr[i]);
        for(i = 0; i < 1 << n; i++)
        {
            prod = 1;
            sum = 0;
            a = subarray(Arr, n, i, &len);
            for(j = 0; j < len; j++)
            {
                printf("%d", a[j]);
                sum += a[j];
                prod *= a[j];
            }
            puts("");
            if (sum == prod)
                res++;

            free(a);
        }
        printf("%d\n", res);
    }
    return 0;
}


int *subarray(int *A, int n, int mask, int *len)
{
    int *a = (int *) malloc(n * sizeof(int)), i;
    *len = 0;
    for(i = 0; i < n; i++)
    {
        if(mask % 2)
            a[*len] = A[i], *len += 1;
        mask /= 2;
    }
    return a;
}
