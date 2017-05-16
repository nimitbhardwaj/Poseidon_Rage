#include<stdio.h>
int main()
{
    int t, n, i, Arr[1000], k, ck = 0, l = 0, b = 0, max = 0;
    scanf("%d", &t);
    while(t--)
    {
        ck = l = b = 0;
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            Arr[i] = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &k);
            max = max > k?max:k;
            Arr[k]++;
        }
        for(i = max; i >= 1; i--)
        {
            if(Arr[i] / 2 >=1)            
            {
                if(Arr[i] == 2 || Arr[i] == 3)
                {
                    if(ck == 0)
                        l = i;
                    else
                        b = i;
                    ck++;
                    if(ck == 2)
                        break;
                }
                if(Arr[i] >= 4)
                {
                    l = b = i;
                    break;
                }
            }
        }
        printf("%d\n", l * b == 0? -1: l * b);
    }
    return 0;
}
