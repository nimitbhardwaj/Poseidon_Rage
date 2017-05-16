#include<stdio.h>
int main()
{
	int n, p, i, r=1;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		scanf("%d", &p);
		r=r*p;
	}
	n=1;
	for(i=2; i<=r; i++)
	{
		if(r%i==0)
			n=n*i;
	}
	printf("%d", n%1000000007);
	return 0;
}
