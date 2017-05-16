#include<stdio.h>
#define SIZE 100000
int Arr[10000000];
int isPalindrome(int);
void fill(int);
int main()
{
    int t, l, r;
    fill(SIZE);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", Arr[r] - Arr[l - 1]);
    }
    return 0;
}

void fill(int N)
{
    int i;
    for(i = 1; i <= N; i++)
    {
        Arr[i] = Arr[i-1];
        if(isPalindrome(i))
            Arr[i] += i;
    }
}

int isPalindrome(int N)
{
    int rev = 0, i, dum = N;
    while(dum)
    {
        rev = 10 * rev + dum % 10;
        dum /= 10;
    }
    if(N == rev)
        return 1;
    return 0;
}
