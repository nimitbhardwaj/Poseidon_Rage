#include<stdio.h>
#include<string.h>
int main()
{
    int t, k, i;
    char str[100000];
    scanf("%d\n", &t);
    while(t--)
    {
        fgets(str, 100000, stdin);
        k = strlen(str);
        str[k - 1] = 0;
        k--;
        k /= 2;
        for(i = 0; i < k; i++)
        {
            if(i % 2 == 0)
                putchar(str[i]);
        }
        putchar('\n');
    }
    return 0;
}
