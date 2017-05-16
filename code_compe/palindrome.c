#include<stdio.h>
int main()
{
    int t, n, rev = 0, dummy;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        dummy = n;
        while(dummy)
        {
            rev = dummy % 10 + 10 * rev;
            dummy /= 10;
        }
        if(rev == n)
            puts("wins");
        else
            puts("losses");
            rev = 0;
    }
    return 0;
}
