#include<stdio.h>
int main()
{
    int t, n, i, j, k, A[100000], left, right;
    unsigned long long score, sum;
    scanf("%d", &t);
    while(t--)
    {
        sum = 0;
        scanf("%d", &n);
        for(i = 0; i <= n; i++)
            scanf("%d", &A[i]);
        for(i = 0; i < 1 << n; i++)
        {
             score = 0;
             k = i;
             left = right = A[0];
             for(j = 1; j <= n; j++)
             {
                 if(k % 2 == 0)
                 {
                     score += A[j] * left;
                     left = A[j];
                 }
                 else
                 {
                    score += A[j] * right;
                    right = A[j];
                 }
                 k /= 2;
             }
             sum += score;
        }
        printf("%llu\n", sum);
    }
}
