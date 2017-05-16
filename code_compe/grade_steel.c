#include<stdio.h>
int main()
{
    int t, a, c, ck[3]={0};
    float b;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %f %d", &a, &b, &c);
        if(a > 50)
            ck[0] = 1;
        if(b < 0.7)
            ck[1] = 1;
        if(c > 5600)
            ck[2] = 1;
            
        if(ck[0] ==1 && ck[1] == 1 && ck[2] == 1)
            printf("10\n");
        else if(ck[0] ==1 && ck[1] == 1 && ck[2] == 0)
            printf("9\n");
        else if(ck[0] ==0 && ck[1] == 1 && ck[2] == 1)
            printf("8\n");
        else if(ck[0] ==1 && ck[1] == 0 && ck[2] == 1)
            printf("7\n");
        else if(ck[0] ==0 && ck[1] == 0 && ck[2] == 0)
            printf("5\n");
        else
            printf("6\n");
        ck[0] = ck[1]= ck[2] = 0;

    }
    return 0;
}
