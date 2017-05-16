#include<stdio.h>
#include<string.h>
int main()
{
    char S[12346];
    int t, l, begin, end, i, ch;
    scanf("%d\n", &t);
    while(t--)
    {
        fgets(S, 12345, stdin);
        l = strlen(S) - 1;
        S[l] = 0;
        begin = 0;
        end = l - 1;
        ch = 0;
        while(begin <= end)
        {
            if((S[begin] == '.' || S[end] == '.') || S[begin] == S[end])
            {
                if(S[begin] == '.' && S[end] == '.')
                    S[begin] = S[end] = 'a';
                else if(S[begin] == '.')
                    S[begin] = S[end];
                else if(S[end] == '.')
                    S[end] = S[begin];
                begin++;
                end--;
            }
            else
            {
                ch = 1;
                break;
            }
        }
        if(ch == 0)
            puts(S);
        else
            printf("%d\n", -1);
    }
    return 0;
}
