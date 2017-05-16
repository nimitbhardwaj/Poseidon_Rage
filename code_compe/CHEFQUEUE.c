#include<stdio.h>
#include<malloc.h>
#define MODULO 1000000007
struct Chef
{
    int index;
    int level;
};
void push(struct Chef *, struct Chef, int *);
struct Chef pop(struct Chef *, int *);
int main()
{
    struct Chef *stack, *chefs, dummy;
    int len = 0, N, K, i, fear = 1, gamma = 0;
    scanf("%d %d", &N, &K);
    chefs = (struct Chef *) malloc(sizeof(struct Chef) * N);
    stack = (struct Chef *) malloc(sizeof(struct Chef) * N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &chefs[i].level);
        chefs[i].index = i;
    }
    push(stack, chefs[0], &len);
    for(i = 1; i < N; i++) 
    {
        dummy = pop(stack, &len);
        if(dummy.level <= chefs[i].level)
        {
            push(stack, dummy, &len);
        }
        else
        {
            while(dummy.level > chefs[i].level)
            {
                fear = ((chefs[i].index - dummy.index + 1) % MODULO * fear %MODULO) % MODULO;
                if(len == 0)
                {
                    gamma = 1; 
                    break;
                }
                dummy = pop(stack, &len);
            }
            if(gamma == 1)
                gamma = 0;
            else        
                push(stack, dummy, &len);
        }
        push(stack, chefs[i], &len);

    }
    printf("%d\n", fear);
    return 0;
}

void push(struct Chef *stack, struct Chef element, int *len)
{
    stack[*len] = element;
    *len += 1;
}

struct Chef pop(struct Chef *stack, int *len)
{
    *len -= 1;
    return stack[*len];
}
