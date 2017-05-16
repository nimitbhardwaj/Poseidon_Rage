#include<stdio.h>
int main()
{
    unsigned int n, k, num, val = 0;
    scanf("%u %u", &n, &k);
    while(n--)
    {
        scanf("%u", &num);
        if(num % k == 0)
            val++;
    }
    printf("%d", val);
    return 0;
}
