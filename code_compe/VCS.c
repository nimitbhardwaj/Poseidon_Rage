#include <stdio.h>
int main()
{
    int t, N, M, K, i, ArM[100] = {0}, ArK[100] = {0}, ArDummy[100] = {0}, both, none, a, b;
    scanf("%d", &t);
    while(t--)
    {
        both = none = 0;
        scanf("%d %d %d", &N, &M, &K);
        for(i = 0; i < M; i++)
            scanf("%d", &ArM[i]);
        for(i = 0; i < K; i++)
            scanf("%d", &ArK[i]);
        for(i = 0; i < N; i++)
        {
            a = ArM[i];
            b = ArK[i];
            if(a)
                ArDummy[a - 1]++;
            if(b)
                ArDummy[b - 1]++;
        }
        for(i = 0; i < N; i++)
        {
            if(ArDummy[i] == 2)
                both++;
            if(ArDummy[i] == 0)
                none++;
        }
        printf("%d %d\n", both, none);
        for(i = 0; i < N; i++)
        {
            ArDummy[i] = 0;
            ArM[i] = 0;
            ArK[i] = 0;
        }

    }
    return 0;
}
