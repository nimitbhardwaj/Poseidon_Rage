#include<stdio.h>
int main()
{
    int t, i, l, c;
    char str1[100000], str2[100001];
    scanf("%d\n", &t);
    while(t--)
    {
        fgets(str1, 100000, stdin);
        fgets(str2, 100000, stdin);

        for(i = 0; str1[i] != '\n'; i++)
        {
            if(str1[i] == str2[i])
                if(str1[i] == 'W')
                    str2[i] = 'B';
                else
                    str2[i] = 'W';
            else
                str2[i] = 'B';
        }
        str2[i] = '\0';
        puts(str2);
    }
    return 0;
}
