#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define BUF 1000000
int main()
{
    int n, i, len, m, ck, kapa;
    char *W, S[BUF];
    while(1)
    {
        kapa = 0;
        scanf("%d\n", &n);
        W = (char *) malloc(sizeof(char) * (n + 1));
        scanf("%s\n%s", W, S);
        len = strlen(S);
        m = 0;
        while(m <= len)
        {
            ck = 0;
            for(i = 0; i < n; i++)
            {
                if(S[m + i] != W[i])
                {
                    ck = 1;
                    break;
                }
            }
            if(ck == 1)
            {
                m += i + 1;
            }
            else
            {
                kapa = 1;
                printf("%d\n", m);
                m += 1;
            }
        }
        if(kapa == 0)
            puts("");
        puts("");
    }
    return 0;
}
