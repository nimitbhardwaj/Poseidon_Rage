#include<stdio.h>
int main()
{
    int t, m, n, A[30], i, j, sum, ck;
    scanf("%d", &t);
    while(t--)
    {
        ck = 0;
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for(i = 0; i < 1 << n; i++)
        {
            sum = 0;
            for(j = 0; j < n; j++)
            {
                if(i & 1 << j)
                    sum += A[j];
            }
            if(sum == m)
            {
                ck = 1; 
                break;
            } 
        }
        if(ck == 1)
            puts("Yes");
        else
            puts("No");


    }
    return 0;
}
