#include<stdio.h>
int main()
{
	int l, i=0, l2=1, l1=1;
	scanf("%d", &l);
	if(l%2!=0)
		puts("0");
	else
	{
		while(l2!=0)
		{
			l2=l/2-l1;
			if(l1==l2)
				;
			else
				i++;
			l1++;
			
		}
		printf("%d\n", (i-1)/2);
	}
	return 0;
}
