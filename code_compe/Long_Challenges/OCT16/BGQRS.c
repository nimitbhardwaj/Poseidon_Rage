#include<stdio.h>
#include<malloc.h>
typedef struct Poseidon
{
    unsigned int p5;
    unsigned int p2;
}Poseidon;
unsigned int pow2(unsigned int);
unsigned int pow5(unsigned int);
int main()
{
    unsigned int t, n, Q, i, num, type, l, r, x, k, res;
    Poseidon *A, X;
    scanf("%u", &t);
    while(t--)
    {
        res = 0;
        scanf("%u %u", &n, &Q);
        A = (Poseidon *) malloc(sizeof(Poseidon) * n);
        for(i = 0; i < n; i++)
        {
            scanf("%u", &num);
            A[i].p2 = A[i].p5 = 0;
            if(num % 2 == 0)
                A[i].p2 = pow2(num);
            if(num % 5 == 0)
                A[i].p5 = pow5(num);
        }
        while(Q--)
        {
            scanf("%u", &type);
            if(type == 1)
            {
                scanf("%u %u %u", &l, &r, &x);
                X.p2 = X.p5 = 0;
                if(x % 2 == 0)
                    X.p2 = pow2(x);
                if(x % 5 == 0)
                    X.p5 = pow5(x);
                for(i = l - 1; i <= r - 1; i++)
                {
                    A[i].p2 += X.p2;
                    A[i].p5 += X.p5;
                }
            }
            else if(type == 2)
            {
                scanf("%u %u %u", &l, &r, &x);
                X.p2 = X.p5 = 0;
                if(x % 2 == 0)
                    X.p2 = pow2(x);
                if(x % 5 == 0)
                    X.p5 = pow5(x);
                k = 1;
                for(i = l - 1; i <= r - 1; i++)
                {
                    A[i].p2 = X.p2 + pow2(k);
                    A[i].p5 = X.p5 + pow5(k);
                    k++;
                }
            }
            else
            {
                scanf("%u %u", &l, &r);
                X.p2 = X.p5 = 0;
                for(i = l - 1; i <= r - 1; i++)
                {
                    X.p2 += A[i].p2;
                    X.p5 += A[i].p5;
                }
                res += X.p2 > X.p5 ? X.p5 : X.p2;
            }
        }
        printf("%u\n", res);
        free(A);
    }
    return 0;
}

unsigned int pow2(unsigned int n)
{
    unsigned int i, k = 1073741824, out = 0;
    for(i = 2; i <= k + 10; i *= 2)
    {
        if(n % i == 0)
            out++;
        else
        {
            return out;
            puts("napa");
        }
    }
    puts("napa");
    return out;
}

unsigned int pow5(unsigned int n)
{
    unsigned int i, k = 1220703125, out = 0;
    for(i = 5; i <= k + 10; i *= 5)
    {
        if(n % i == 0)
            out++;
        else
        {
            return out;
            puts("kapa");
        }
    }
    puts("kapa");
    return out;
}
