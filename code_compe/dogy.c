#include<stdio.h>
int main()
{
    int t, N, K, i, max = 0, ck = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &N, &K);
        for(i = 1; i <= K; i++)
        {
            if(max <= N % i)
                max = N % i;

        }
        printf("%d\n", max);
        max = 0;
    }
    return 0;
}
