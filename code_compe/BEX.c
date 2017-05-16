#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define N 10000000
struct Book
{
    int n;
    char name[20];
};

void push(struct Book*, struct Book, int*);
struct Book pop(struct Book*, int*);
int main(void)
{
    int t, n, len = 0, min = 10000000, i = 0, kapa = 0, j;
    struct Book *stack, book;
    stack = (struct Book *) malloc(N * sizeof(struct Book));
    scanf("%d", &t);
    while(t--)
    {
        min = 10000000;
        kapa = 0;
        scanf("%d", &n);
        if(n != -1)
        {
            book.n = n;
            scanf("%s", book.name);
            push(stack, book, &len);
        }
        else
        {
            for(j = 0; j < len; j++)
            {
                if(min >= stack[j].n)
                {
                    kapa = j;
                    min = stack[j].n;
                }
            }
            i = len;
            while(len != kapa )
            {
                book = pop(stack, &len);
            }
            printf("%d %s\n", i - kapa - 1, book.name);
        }
    }
    return 0;
}

void push(struct Book *stack, struct Book book, int *len)
{
    (stack + *len)->n = book.n;
    strcpy((stack + *len)->name, book.name);
    *len += 1;
}

struct Book pop(struct Book *stack, int *len)
{
    *len = *len - 1;
    return stack[*len];
}
