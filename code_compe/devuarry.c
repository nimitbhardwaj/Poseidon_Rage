#include<stdio.h>
int main()
{
    int n, q, i;
    unsigned int min = 1000000001, max = 0, A, num;
    scanf("%d %d", &n, &q);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &A);
        if(A > max)
            max = A;
        if(A < min)
            min = A;
    }
    while(q--)
    {
        scanf("%u", &num);
        if(num >= min && num <= max)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
