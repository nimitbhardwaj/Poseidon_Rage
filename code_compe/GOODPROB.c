#include<stdio.h>
int max(int, int, int *);
int main()
{
    int n, Arr[100000], i, j, sum = 0, ck;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &Arr[i]);
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            ck = (Arr[i] & Arr[j]);
            if(ck == Arr[i] || ck == Arr[j])
                ck = 1;
            else
                ck = 0;
            if(ck == 1)
                sum += max(i, j, Arr);
        }
    }
    printf("%d\n", sum);
    return 0;
}

int max(int i, int j, int *A)
{
    int c = 0, k;
    for(k = i; k <= j; k++)
        if(A[k] > c)
            c = A[k];
    return c;
}
