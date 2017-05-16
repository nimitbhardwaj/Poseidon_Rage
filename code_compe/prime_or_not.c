#include<stdio.h>
int main()
{
    int t, n, i, ck = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 2; i < n; i++)
        {
            if(n % i == 0)
            {
                ck =1;
                break;
            }
        }
        puts(ck==1?"no":"yes");
        ck = 0;
    }
    return 0;
}
