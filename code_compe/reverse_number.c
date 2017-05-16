#include<stdio.h>
int main()
{
    int t, n, m = 0;
    scanf("%d", &t);
    while(t--)
    {
    	scanf("%d", &n);
    	while(n)
    	{
    	    m = (n % 10) + m * 10;
    	    n /= 10;
    	}
    	printf("%d\n", m);
        m = 0;
    }
    return 0;
}
