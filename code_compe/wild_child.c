#include<stdio.h>
#include<string.h>
void flush_input(void);
int main()
{
    int t, i, ck = 0;
    char X[12], Y[12], *c, *d;
    scanf("%d\n", &t);
    while(t--)
    {
        fgets(X, 12, stdin);
        fgets(Y, 12, stdin);
        c = X;
        d = Y;
        while(*c !='\0')
        {
            if(*c =='?' || *d=='?')
                ;
            else
            {
                if(*c == *d)
                ;
                else
                {
                    ck = 1;
                    break;
                }
            }
            c++;
            d++;
        }
        if(ck == 0)
            puts("Yes");
        else
            puts("No");
        ck = 0;
    }
    return 0;
}

void flush_input(void)
{
    int c;
    do
    {
        c = getchar();
    } while(c == '\n' && c == EOF);
}
