#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define BUFF 1000
#define RESBUF 1000
void multi(char *, char *, int, int, int *, char *);
void printArr(char *, int);
int main()
{
    int t, len1, len2, len3, i;
    char A[BUFF], B[BUFF], c, *C;
    C = (char *) malloc(sizeof(char) * RESBUF);
    scanf("%d\n", &t);
    while(t--)
    {
        len1 = len2 = len3 = 0;
        while((c = getchar()) != ' ')
            A[len1++] = c - '0';
        while((c = getchar()) != '\n')
            B[len2++] = c - '0';
        multi(A, B, len1, len2, &len3, C);
        printArr(C, len3);
        memset(A, 0, BUFF);
        memset(B, 0, BUFF);
        memset(C, 0, RESBUF);
    }
    return 0;
}

void multi(char *A, char *B, int len1, int len2, int *len3, char *C)
{
    int i, j, maxlen = len1 + len2;
    for(i = len2 - 1; i >= 0; i--)
    {
        for(j = len1 - 1; j >= 0; j--)
        {
            C[RESBUF - (len2 - i + len1 - j - 2)] += A[j] * B[i];
            C[RESBUF - (len1 - i + len2 - j - 1)] += C[RESBUF - (len1 - i + len2 - j - 2)] / 10;
            C[RESBUF - (len1 - i + len2 - j - 2)] %= 10;
        }
    }
    if(C[RESBUF - maxlen + 1] != 0)
        maxlen++;
    *len3 = maxlen;
}

void printArr(char *C, int len3)
{
    int i;
    for(i = len3 - 2; i >= 0; i--)
        putchar(C[RESBUF - i] + '0');
    putchar('\n');
}
