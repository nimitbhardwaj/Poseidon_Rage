#include<stdio.h>
#include<stdlib.h>
void multi(char *, int, int *);
int main()
{
    int  i, n, m = 0;
    char *a, *b;
    a = (char *) malloc(sizeof(char) * 200);
    b = (char *) malloc(sizeof(char) * 200);
    while((*(a + m++) = getchar() - '0') != '\n' - '0')
        fflush(stdin);
    m--;
    scanf("%d", &n);
    for(i = 0; i < m; i++)
        *(b + i) = *(a + m - i - 1);
    free(a);
    multi(b, n, &m);
    for(i = m - 1; i >= 0 ; i--)
        printf("%d", *(b + i));
    printf("\n");
    return 0;
}

void multi(char *a, int n, int *m)
{
    int i, tmp = 0;
    for(i = 0; i < *m; i++)
    {
        tmp = *(a + i) * n + tmp;
        *(a + i) = tmp % 10;
        tmp /= 10;
    }
    while(tmp)
    {
        *(a + *m) = tmp % 10;
        *m += 1;
        tmp /= 10;
    }
}
