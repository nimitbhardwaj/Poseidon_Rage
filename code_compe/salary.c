#include<stdio.h>
#include<math.h>
//float round(float, int);
int main()
{
    int t, n;
    float f;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n < 1500)
            f = 2.0 * n;
        else
            f = n + 98.0 / 100 * n + 500;
        printf("%g\n", f);
    }
    return 0;
}
