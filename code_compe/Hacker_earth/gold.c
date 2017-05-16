#include<stdio.h>
#include<malloc.h>
#define MOD 1000000007
typedef struct coin
{
    int val, day;
}Coin;
int main()
{
    int n, m, k, i, sum = 0;
    Coin A;
    scanf("%d %d %d", &n, &m, &k);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &A.val);
        A.day = A.val / k;
        if(A.day <= m)
            sum += (A.day + 1) * (A.val) / 2;
        if(A.day < m && A.val - k * A.day != 0)
            sum = (1 + sum);
        if(A.day > m)
        {
            sum += m * (2 * A.val - k * (m - 1)) / 2;
        }
        sum %= MOD;
    }
    printf("%d", sum);
    return 0;
}
