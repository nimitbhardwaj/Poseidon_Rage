#include<stdio.h>
#include<math.h>
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%.0f\n", sqrt(n));
    }
    return 0;
}
