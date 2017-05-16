#include<stdio.h>
int main()
{
    int t, d, n0, n1;
    scanf("%d\n", &t);
    while(t--)
    {
        n0 = n1 = 0;
        while((d = getchar()) != '\n')
        {
            if(d == '0')
                n0++;
            else if(d == '1')
                n1++;
        }
        printf(n0 == 1 || n1 == 1 ? "Yes\n" : "No\n");
    }
    return 0;
}
