#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MOD 1000000007
 
void computeLPSArray(char *pat, int M, int *lps);
void KMPSearch(char *pat, char *txt, int *);
int dynamic(char *S, char *T, int *A, int n);
int next(int n, int *A, int len);
int *D_Array;
int len;

int main()
{
    int t, num;
    int *A;
    char T[400000], S[400000];
    int l1, l2;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s %s", S, T);
        l1 = strlen(S);
        l2 = strlen(T);
        len = l2;
        D_Array = (int *) calloc(sizeof(int) & 1000000, sizeof(int));
        A = (int *) calloc(sizeof(int) * l1, sizeof(int));
        KMPSearch(T, S, A);
        num = dynamic(S, T, A, 1);
        printf("%d\n", num - 1);
        free(A);
        free(D_Array);
    }
    return 0;
}


void KMPSearch(char *pat, char *txt, int *A)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]
    A[0] = 0;
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    while(i < N)
    {
      if(pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
          A[0]++;
          int a = A[0];
          A[a] = i - j;
          j = lps[j-1];
      }
 
      // mismatch after j matches
      else if(pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if(j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
}
 
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while(i < M)
    {
       if(pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if( len != 0 )
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
 
int dynamic(char *S, char *T, int *A, int n)
{
    if(n == A[0] + 1)
        return 1;
    //std::cout << "next of " << n << " is " << next(n, A, T.size()) << std::endl;
    int a = next(n, A, strlen(T));
    if(D_Array[n + 1] == 0)
        D_Array[n + 1] = dynamic(S, T, A, n + 1);
    if(D_Array[a] == 0)
        D_Array[a] = dynamic(S, T, A, a);
    return (D_Array[n + 1] + D_Array[a]) % MOD;
}
int next(int n, int *A, int len)
{
    int i;
    for(i = n + 1; i <= A[0]; i++)
    {
        if(A[n] + len <= A[i])
            return i;
    }
    return A[0] + 1;
}
