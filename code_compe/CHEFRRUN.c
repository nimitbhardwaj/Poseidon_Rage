#include<stdio.h>
int isMagic(int *, int, int);
int main()
{
    int t, i, n, A[1000000], magic;
    scanf("%d", &t);
    while(t--)
    {
        magic = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for(i = 0; i < n; i++)
        {
            if(isMagic(A, i, n))
                magic++;
        }
        printf("%d\n", magic);
    }
}

int isMagic(int *A, int index, int n)
{
    int i, test = index, Arr[1000000], k = 0, j;
    while(1)
    {
        Arr[k] = test;
        k++;
        test = (test + A[test] + 1) % n;
        if(test == index)
        {
            return 1;
        }
        for(j = 0; j < k - 1; j++)
            if(test == Arr[j])
                return 0;
    }
}
