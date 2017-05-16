#include<stdio.h>
#include<stdbool.h>
int main()
{
    unsigned int n, a = 0, b = 0, t, i = 0, a_2 = 2, a_5 = 5;
    scanf("%u", &t);
    while(t--)
    {
        scanf("%u", &n);
        while(true)
        {
            a += n / a_2;
            if( !(n / a_2))
                break;
            a_2 *= 2;
        }
        i = 0;
        while(true)
        {
            b += n / a_5;
            if( !(n / a_5))
                break;
            a_5 *= 5;
        }
        i = 0;
        printf("%u\n", a>=b?b:a);
        a = b = 0;
        a_2 = 2;
        a_5 = 5;
    }
    return 0;
}
