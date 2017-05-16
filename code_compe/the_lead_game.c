#include<stdio.h>
#include<math.h>
int abs(int);
int main()
{
    int n, max = 0, ck = 0, a = 0, b = 0, del, c = 0, d = 0;
    scanf("%d", &n);
    while(n--)
    {
        c += a;
        d += b;
        scanf("%d %d", &a, &b);
        del = (a + c) - (b + d);

        if(abs(del) > max)
        {
            if(del > 0)
                ck = 1;
            else
                ck = 2;
            max = abs(del);
        }

    }
    printf("%d %d\n", ck, max);
    return 0;
}
