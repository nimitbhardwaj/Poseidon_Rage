#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
int len;
void enque(char**, int *, int *, char *);
char *deque(char **, int *, int *);
int main()
{
    char *queue[N], inp[2 * N], *str;
    int t, n, i, j, f = 0, r = 0, c;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            fgets(inp, 100, stdin);
            if(strncmp(inp, "cd", 2) == 0)
            {
                str = strtok(inp + 3, "/");
                while(str != NULL)
                {
                    enque(queue, &f, &r, str);
                    puts(str);
                    str = strtok(NULL, "/");
                }
            }
            else
            {
                while(len)
                    printf("/%s", deque(queue, &f, &r));
                puts("/");
            }
        }
    }
    return 0;
}

void enque(char **p, int *f, int *r, char *str)
{
    if((*r + 1) % N == *f)
    {
        fputs("Out of Memory", stderr);
        exit(0);
    }
    *(p + *r) = str;
    *r = (1 + *r) % N;
    len++;
}

char *deque(char **p, int *f, int *r)
{
    char *str;
    if(*f == *r)
    {
        fputs("No element present", stderr);
        exit(0);
    }
    str = *(p + *f);
    *f = (*f + 1) % N;
    len--;
    return str;

}
