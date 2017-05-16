#include<stdio.h>
int isPalindrome(int);

int main()
{
    int i, t, A, B, sum = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &A, &B);
        for(i = A; i <= B; i++)
        {
            if(isPalindrome(i))
                sum += i;
        }
        printf("%d\n", sum);
        sum = 0;
    }
    return 0;
}

int isPalindrome(int n)
{
    int rev = 0, dummy;

    dummy = n;
    while(dummy)
    {
        rev = dummy % 10 + 10 * rev;
        dummy /= 10;
    }
    if(rev == n)
        return 1;
    else
        return 0;
        rev = 0;

}
