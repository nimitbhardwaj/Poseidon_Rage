#include <stdio.h>

int gcd(int a, int b);
void swap(int *a, int *b);

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a > b)
            swap(&a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}

int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
