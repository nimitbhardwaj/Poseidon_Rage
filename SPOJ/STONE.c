#include<stdio.h>
int main()
{
    int t, n, i, a, b;
    float x, y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        x = y = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            x += a;
            y += b;
        }
        printf("%.2f %.2f\n", x / n, y / n);
    }
}
