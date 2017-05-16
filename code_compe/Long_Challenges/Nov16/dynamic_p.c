#include<stdio.h>
#include<malloc.h>
int fib_rec(int);
int fib_dy(int);
int fib_dy_rec(int);
int *dy;
int *dy_rec;
int main()
{
    int n, ck, t;
    extern int *dy;
    dy = (int *) malloc(sizeof(int) * 1000000);
    dy_rec = (int *) malloc(sizeof(int) * 1000000);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &ck);
        if(ck == 0)
            printf("%d\n", fib_rec(n));
        else if(ck == 1)
            printf("%d\n", fib_dy(n));
        else
            printf("%d\n", fib_dy_rec(n));
        printf("%p\n", fib_rec);
    }
    return 0;
}

int fib_rec(int a)
{
    if(a == 1)
        return 1;
    else if(a == 2)
        return 1;
    else
        return fib_rec(a - 1) + fib_rec(a - 2);
}

int fib_dy(int a)
{
    extern int *dy;
    if(dy[a] != 0)
        return dy[a];
    else
    {
        int i;
        dy[1] = 1;
        dy[2] = 1;
        for(i = 3; i <= a; i++)
            dy[i] = dy[i - 1] + dy[i - 2];
        return dy[a];
    }
}

int fib_dy_rec(int a)
{
    if(a == 0 || a == 1 || a == 2)
        return 1;
    if(dy_rec[a] != 0)
        return dy[a];
    else
    {
        dy_rec[a] = fib_dy_rec(a - 1) + fib_dy_rec(a - 2);
        return dy_rec[a];
    }
}
