#include<stdio.h>
int main()
{
    int t, bal, max, i;
    char c[100000];
    scanf("%d", &t);
    while(t--)
    {
        bal = max = 0;
        scanf("%s", c);
        for(i = 0; c[i] != '\0'; i++)
        {
            if(c[i] == ')')
                bal--;
            else
                bal++;
            max = max > bal?max:bal;
        }
        for(i = 0; i < max; i++)
            putchar('(');
        for(i = 0; i < max; i++)
            putchar(')');
        puts("");
    }
    return 0;
}
