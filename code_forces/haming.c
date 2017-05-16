#include<stdio.h>
#include<string.h>
#include<math.h>
int ham(char *, char *);
int main()
{
	int i, j, k, r=0, l1, l2;
	char a[200001], b[200001], c[200001], *d;
	fgets(a, sizeof(a), stdin);
	fgets(b, sizeof(b), stdin);
	l1=strlen(a);
	l2=strlen(b);
	d=b;
	if(l1==l2)
	{
		r=ham(a, b);
	}
	else
	{
		for(i=0; i<l2-l1+1; i++)
		{
		strncpy(c, d+i, l1-1);
		r+=ham(c, a);
		}
	}
	printf("%d\n", r);
	return 0;
}


int ham(char *a,char *b)
{
	int r=0;
	while(*a!='\0')
	{
		r+=(int)fabs((*a)-(*b));
		a++;
		b++;
	}
	return r;
}
