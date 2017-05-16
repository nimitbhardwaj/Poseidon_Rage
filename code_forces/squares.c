#include<stdio.h>
int min_l(int*, int*, int);
int main()
{
	int n, i, k, l=0, r=0, lef, rig;
	int jar[100];
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &jar[i]);
	}
	k=min_l(jar, &l, n);
	lef=k;
	rig=l;
	r=r+n*jar[rig];
	r+=n-rig-1+lef;
	printf("%d\n",r);
	return 0;
}

int min_l(int *b, int *f, int n)
{
	int min=1000000000, i, k=0, l=0;
	for(i=0; i<n; i++)
	{
		if(min==*b)
		{
			l=i;
		}
		if(min>*b)
		{
			k=i;
			min=*b;
		}
		b++;
	}
	if(k>l)
		l=k;
	*f=l;
	return k;
}
