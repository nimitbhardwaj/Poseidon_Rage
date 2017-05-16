#include<stdio.h>
int main()
{
    int t, s, v;
    double time;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &s, &v);
        time = 2.0 / 3.0 * (float)s / v;
        printf("%lf\n", time);
    }
    return 0;
}

