#include <stdio.h>
int main()
{
    int mark, n, i, t, sum = 0, fail = 0, top = 0;
    float cgpa;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &mark);
            sum += mark;
            if(mark == 2)
                fail = 1;
                
            if(mark == 5)
                top = 1;
        }
        cgpa = ((float)sum) / n;
        if(cgpa >= 4 && top == 1 && fail == 0)
            puts("Yes");
        else
            puts("No");
        top = fail = sum = 0;
    }
    return 0;
}
