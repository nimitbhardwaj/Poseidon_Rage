#include<stdio.h>
int main()
{
    int t = 10;
    char c, res;
    while(t--)
    {
        res = 1;
        while((c = getchar()) != '\n')
        {
            if(c == 'T')
                res *= 2;
            else if(c == 'D')
                res *= 2;
            else if(c == 'L')
                res *= 2;
            else if(c == 'F')
                res *= 2;
        }
        printf("%d\n", res);
    }
    return 0;
}
