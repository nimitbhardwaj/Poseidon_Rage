#include<stdio.h>
int main()
{
    int t, n, px, py, i, res;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        res = 0;
        
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &px, &py);
            res ^= i + 1;
        } 
        printf("%d\n", res);
    }
    return 0;
}
