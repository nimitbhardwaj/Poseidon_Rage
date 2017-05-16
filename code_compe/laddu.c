#include<stdio.h>
#include<string.h>
int main()
{
    int t, i, n, j, pmon = 1, l=0, num;
    char orig[12], str[50];
    scanf("%d", &t);
    for(i = 1; i <= t; i++)
    {
        scanf("%d %s", &n, orig);
        if(strcmp(orig, "INDIAN") == 0)
            pmon = 200;
        else
            pmon = 400;
        for(j=1; j<=n; j++)
        {
            scanf("%s", str);
            if(strcmp(str, "CONTEST_WON") == 0)
            {
                scanf("%d", &num);
                if(num > 20)
                    num = 20;
                l += 300 + 20 - num;
            }

            if(strcmp(str, "TOP_CONTRIBUTOR") == 0)
            {
                l += 300;
            }

            if(strcmp(str, "BUG_FOUND") == 0)
            {
                scanf("%d", &num);
                l += num;
            }

            if(strcmp(str, "CONTEST_HOSTED") == 0)
            {
                l += 50;
            }

        }
        printf("%d\n", l / pmon );
        l = 0;
    }
}
