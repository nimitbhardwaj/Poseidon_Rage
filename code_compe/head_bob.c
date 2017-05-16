#include<stdio.h>
int main()
{
    int t, n, ck = 0;
    char c[1000000], d;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        fflush(stdin);
        d = getchar();
        fgets(c, 1000000, stdin);
        while(n--)
        {
            if(c[n] =='I')
            {
                ck =1;
            }
            if(c[n] =='Y')
            {
                ck = 2;
            }
        }
        if(ck == 0)
            printf("NOT SURE\n");
        if(ck == 1)
            printf("INDIAN\n");
        if(ck == 2)
            printf("NOT INDIAN\n");
        ck = 0;
        fflush(stdin);
    }
    return 0;
}
