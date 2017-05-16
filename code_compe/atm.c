#include<stdio.h>
int main()
{
    int n;
    float amt;
    scanf("%d %f", &n, &amt);
    if(n % 5 != 0)
        printf("%.2f", amt);
    else
    {
        (amt - n - 0.5 >= 0)?printf("%.2f", amt - n - 0.5) : printf("%.2f", amt);
    }
    return 0;
}
