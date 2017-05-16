#include<stdio.h>
#include<malloc.h>
#include<string.h>
char *fact(int, int*);
void multiply(char *, int, int*);
int main()
{
    int t, n, m = 0;
    char *p;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        p = fact(n, &m);
        while(m)
            printf("%d", *(p + --m));
        free(p);
        m = 0;
        printf("\n");
    }
    return 0;
}

char *fact(int n, int *m)
{
    char *c;
    int i;
    c = (char *) malloc(2000 * sizeof(char));
    *c = 1;
    *m = 1;
    for(i = 1; i <= n; i++)
    {
        multiply(c, i, m);
    }
    return c;
}

void multiply(char *p, int n, int *m)
{
    int i, tmp = 0;
    for(i = 0; i < *m; i++)
    {
        tmp += *(p + i) * n;
        *(p + i) = tmp % 10;
        tmp /= 10;
    }
    while(tmp)
    {
        *(p + *m) = tmp % 10;
        tmp /=10;
        *m += 1;
    }
}
