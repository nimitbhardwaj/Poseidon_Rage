#include<stdio.h>
#define MODU 1000000007
void func_2(unsigned long long *, int, int, int *, unsigned long long int *);
void multiply(char *, unsigned long long int, int*);
int main()
{
    int N, i, q, type, p, f, R, numb, r1;
    unsigned int long long r2, city[100000];
    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%llu", &city[i]);
    }
    scanf("%d", &q);
    for(i = 1; i <= q; i++)
    {
        scanf("%d", &type);
        switch (type)
        {
            case 1:
                scanf("%d %d", &p, &f);
                city[p - 1] = f;
                break;
            case 2:
                scanf("%d", &R);
                func_2(city, N, R, &r1, &r2);
                //printf("%d %llu\n", r1, r2);

                break;
        }
    }
    return 0;
}

void multiply(char *p, unsigned long long int n, int *m)
{
    unsigned long long int i, tmp = 0;
    for(i = 0; i < *m; i++)
    {
        tmp += *(p + i) * n;
        *(p + i) = tmp % 10;
        tmp /= 10;
        printf("%d", *(p + i));
    }
    while(tmp)
    {
        *(p + *m) = tmp % 10;
        tmp /=10;
        *m += 1;
        printf("%d", *(p + *m - 1));
    }
    *m--;

}

void func_2(unsigned long long *A, int N, int R, int * r1, unsigned long long int *r2)
{
    int i, m = 1;
    unsigned long long int md = 1, dump = 1, slump;
    char Ar[1000000]= {1};
    for(i = 0; i * R < N; i++)
    {
        multiply(Ar, A[R * i], &m);
        //md = ((md % MODU) * (A[R * i] % MODU)) % MODU;
    }
    puts("");

    *r1 = Ar[m - 1];
    *r2 = (unsigned) md;
}
