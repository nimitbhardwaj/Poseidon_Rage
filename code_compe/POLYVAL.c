#include <stdio.h>
#define MODULO 786433ull
int main()
{
    unsigned long long int i, N, Arr[250000], Q, k, ans;
    scanf("%llu", &N);
    for(i = 0; i <= N; i++)
        scanf("%llu", &Arr[i]);
    scanf("%llu", &Q);
    while(Q--)
    {
        scanf("%llu", &k);
        ans = Arr[N];
        for(i = 1; i <= N; i++)
            ans = (Arr[N - i] % MODULO + (k * ans) % MODULO) % MODULO;
        printf("%llu\n", ans);

    }
    return 0;
}
