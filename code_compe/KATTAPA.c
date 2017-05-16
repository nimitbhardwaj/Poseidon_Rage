#include<stdio.h>
int main()
{
    int n, A, i, l = 0, u = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &A);
        if(A % 2 == 0)
            l++;
        else
            u++;
    }
    puts(l > u? "READY FOR BATTLE":"NOT READY");
    return 0;
}
