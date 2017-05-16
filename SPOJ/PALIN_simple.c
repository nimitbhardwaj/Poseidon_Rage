#include<stdio.h>
int isPalin(int);
int next(int);
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", next(n));
            
    }
    return 0;
}
int isPalin(int a)
{
    int n = a, rev = 0;
    while(a)
    {
        rev = rev * 10 + a % 10;
        a /= 10;
    }
    if(n == rev)
        return 1;
    return 0;

}

int next(int a)
{
    int i;
    for(i = a + 1; ; i++)
    {
        if(isPalin(i))
            return i;
    }
}
