#include<stdio.h>
struct pas
{
	int t;
	int f;
	
};
int main()
{
	int s, n, i, k, ti=0, pre;
	struct pas arr[100];
	scanf("%d %d", &n, &s);
	for(i=0; i<n; i++)
	{
	scanf("%d %d", &arr[i].f, &arr[i].t);
	}
	k=n-1;
	pre=s;
	while(k!=-1)
	{
		ti=ti-arr[k].f+pre;
		pre=arr[k].f;
		if(ti>=arr[k].t)
			;
		else
			ti=arr[k].t;
		k--;
			
	}
	ti=ti+pre;
	printf("%d\n", ti);
	return 0;
}

