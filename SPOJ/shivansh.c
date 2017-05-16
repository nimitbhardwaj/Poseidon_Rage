#include<stdio.h>
int main()
{
    int m, n, M[1000], A[1000], C[1000], i, j = 0, k;
    scanf("%d %d", &m, &n);
    for(i = 0; i < m; i++)
        scanf("%d", &M[i]);
    for(i = 1; i <= n; i++)
        A[i - 1] = i;
    for(i = 0; i < m; i++)
    {
        for(k = 0; k < n; k++)
        {
            if(A[k] == M[i])
                A[k] = -1;
        }
    }
    for(i = 0; i < n; i++)
    {
        if(A[i] != -1)
            C[j++] =A[i], printf("%d\n", A[i]);
    }
    return 0;
}
