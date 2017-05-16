#include<stdio.h>
#include<malloc.h>
long long int NU[1000000] = {0};
long long int vl = 0;
int isMagical(char*, int);
char *convert(long long int, int*);
int main()
{
    int t, m;
    long long int n, k = 0, i, count = 0;
    char *A, B[15], c;
    scanf("%d\n", &t);
    while(t--)
    {
        scanf("%lld", &n);
        for(k = 1; ; k++)
        {
            A = convert(k, &m);
            if(isMagical(A, m))
                count++;
            if(count == n - 1)
                break;
        }
        printf("%lld\n", k);
        count = 0;
    }
    return 0;
}

int isMagical(char *A, int m)
{
    int i, size = 1 << m, j, mask;
    long long int *p, val, ck, pro = 1, sum = 0;
    p = (long long int*) malloc(sizeof(long long int) * size);
    p[0] = 0;
    for(i = 1; i < size; i++)
    {
        mask = i;
        for(j = 0; j < m; j++)
        {
            // printf("a");

            ck = mask % 2;
            mask /= 2;
            val = A[j] * ck;
            if(ck)
                pro *= val;
            else
                ;
        }
        p[i] = pro;
        sum += pro;
        //printf("%lld\n", pro);
        pro = 1;
    }
    // printf("%lld\n", sum);
    if(sum % 2 == 0)
        return 1;
    else
        return 0;
}


char *convert(long long int n, int *m)
{
    char *Arr;
    Arr = (char *)malloc(10000000 * sizeof(char));
    *m = 0;
    while(n)
    {
        Arr[*m] = n % 10;
        n /= 10;
        *m = *m + 1;
    }
    return Arr;
}
