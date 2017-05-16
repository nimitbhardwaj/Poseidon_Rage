#include<stdio.h>
int main()
{
    int t, A, B, C, mid;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &A, &B, &C);
        mid = A;
        if(mid <= C && mid <= B)
        {
            mid = B;
            if(mid >= C )
            mid = C;
        }
        if(mid >= C && mid >= B)
        {
            mid = B;
            if(mid <= C)
                mid = C;
        }
        printf("%d\n", mid);
    }
    return 0;
}
