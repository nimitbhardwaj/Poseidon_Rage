#include<stdio.h>
#define BUFFER 1000000
void increment(char*, int*);
int isPalin(char*, int);
void printArr(char *, int);
int main()
{
    int t, len = 0;
    char A[BUFFER], c;
    scanf("%d\n", &t);
    while(t--)
    {
            while((c = getchar()) != '\n')
            {
                        len++;
                        A[len] = c;
                    }
            while(1)
            {
                        increment(A, &len);
                        if(isPalin(A, len))
                        {
                                        printArr(A, len);
                                        break;
                                    }
                    }
            len = 0;
        }
    return 0;
}
 
void increment(char *A, int *len)
{
    int i = *len;
    while(1)
    {
            A[i] += 1;
            if(A[i] == '9' + 1)
            {
                        A[i] = '0';
                        i--;
                    }
            else
                break;
        }
}
void printArr(char *A, int len)
{
    int i;
    if(A[0] == 1)
        putchar(A[0]);
    for(i = 1; i <= len; i++)
        putchar(A[i]);
    putchar('\n');
}
int isPalin(char *A, int len)
{
    int i = 1;
    if(A[0] == '1')
        i = 0;
    while(i <= len)
    {
            if(A[i] != A[len]) 
                return 0;
            len--;
            i++;
        }
    return 1;
}
