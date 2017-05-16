#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MOD 1000000007
int *KMP(char *, char *);
int *__lookUpTable(char *);
int dynamic(char *, char *, int *, int);
int next(int, int *, int);
int D_Array[500000];
int lenS, lenT;
int main()
{
    int t, i;
    char S[400000], T[400000];
    int *A;
    scanf("%d\n", &t);
    while(t--)
    {
        fgets(S, 400000, stdin);
        fgets(T, 400000, stdin);
        lenS = strlen(S);
        lenT = strlen(T);
        S[--lenS] = 0;
        S[--lenT] = 0;
        A = KMP(S, T);
        /*for(i = 0; i <= A[0]; i++)*/
            /*printf("%da\n", A[i]);*/
        memset(D_Array, 500000, sizeof(int));
        printf("%d\n", dynamic(S, T, A, 1));
        free(A);
    }
}

int *KMP(char *S, char *T)
{
    //Array A need to be deleted
    int sz = lenS, szt = lenT;
    //printf("%d %dlen\n", sz, szt);
    int *A = (int *) malloc(sizeof(int) * sz);
    int *B = __lookUpTable(T);
    int i = 0, j = 0;
    //for(int i = 0; i < lenT; i++)
        //printf("%db\n", B[i]);
    A[0] = 0;
    while(i < sz)
    {
        if(T[j] == S[i])
        {
            i++;
            j++;
            printf("%c mathces with %c\n", T[j], S[i]);
        }
        if(j == szt)
        {
            A[0]++;
            A[A[0]] = i - j;
            j = B[j - 1];
        }
        else if(i < sz && T[j] != S[i])
        {
            printf("%c does not mathces with %c\n", T[j], S[i]);
            if(j != 0)
                j = B[j - 1];
            else
                i++;
        }
    }
    free(B);
    return A;
}


int *__lookUpTable(char *T)
{
    //array is needed to be freed
    int sz = lenS;
    int *B = (int *) malloc(sizeof(int) * sz);
    int j = 0;
    B[0] = 0;
    for(int i = 1; i < sz; i++)
    {
        while(1)
        {
            if(T[j] == T[i])
            {
                B[i] = j + 1;
                j++;
                break;
            }
            else if(T[j] != T[i] && j != 0)
            {
                j = B[j - 1];
            }
            else if(T[j] != T[i] && j == 0)
            {
                break;
            }
        }
    }
    return B;
}

int dynamic(char *S, char *T, int *A, int n)
{
    if(n == A[0] + 1)
        return 1;
    //std::cout << "next of " << n << " is " << next(n, A, T.size()) << std::endl;
    int a = next(n, A, lenT);
    if(D_Array[n + 1] == 0)
        D_Array[n + 1] = dynamic(S, T, A, n + 1);
    if(D_Array[a] == 0)
        D_Array[a] = dynamic(S, T, A, a);
    return (D_Array[n + 1] + D_Array[a]) % MOD;
}
int next(int n, int *A, int len)
{
    for(int i = n + 1; i <= A[0]; i++)
    {
        if(A[n] + len <= A[i])
            return i;
    }
    return A[0] + 1;
}

