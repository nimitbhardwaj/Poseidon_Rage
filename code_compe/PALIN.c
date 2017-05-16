#include<stdio.h>
int isPalindrome(int);
int main()
{
    int t, n, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        i = n;
        while(1)
        {
            if(isPalindrome(i))
            {
                printf("%d\n", i);
                break;
            }
            i++;
        }
    }
    return 0;
}

int isPalindrome(int n)
{
    int rev = 0, dummy = n;
    while(dummy)
    {
        rev = rev * 10 + dummy % 10;
        dummy /= 10;
    }
    if(rev == n)
        return 1;
    else
        return 0;
}
