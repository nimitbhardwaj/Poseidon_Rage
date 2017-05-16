#include<stdio.h>
#include<string.h>
void push(char, char *, int *);
char pop(char *, int *);
int main()
{
    int t, l, i, st = 0;
    char str[402], stack_op[400];
    scanf("%d\n", &t);
    while(t--)
    {
        fgets(str, 402, stdin);
        l = strlen(str);
        for(i = 0; i < l; i++)
        {
            if(str[i] <= 'z' && str[i] >= 'a')
                printf("%c", str[i]);
            if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
                push(str[i], stack_op, &st);
            if(str[i] == ')')
                printf("%c", pop(stack_op, &st));
        }
        putchar('\n');
    }
    return 0;
}

void push(char c, char *stack, int *len)
{
    stack[*len] = c;
    (*len)++;
}
char pop(char *stack, int *len)
{
    (*len)--;
    return stack[*len];
}
