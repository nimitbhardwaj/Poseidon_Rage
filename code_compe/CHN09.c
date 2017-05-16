#include<stdio.h>
int main()
{
    int t, c, a, b;
    scanf("%d\n", &t);
    while(t--)
    {
        a = b = 0;
        while((c = getchar()) != '\n') 
        {
            if(c == 'a')
                a++;
            else
                b++;
        }
        printf("%d\n", (a > b)? b : a);
    }
    return 0;
}
