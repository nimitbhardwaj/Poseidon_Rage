#include <stdio.h>
int main(void)
{
    int t, i, n, A[1000000], sum = 0, test = 0, trigger = 0;
    float sgpa;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
            sum += A[i];
            if( A[i] ==2 )
            {
                test = 1;
                break;
            }
            if(A[i] == 5)
                trigger = 1;
        }
        sgpa = sum / (5.0 * n) * 5.0;
        (sgpa >= 4 && test == 0 && trigger == 1)?(printf("Yes\n")):(printf("No\n"));
        test = sum = trigger = 0;
    }
    return 0;
}
