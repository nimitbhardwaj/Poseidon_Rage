#include<stdio.h>
int main()
{
	int m, n, i, bul[100]={0}, k, j, ll;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
	{
		scanf("%d", &k);
		for(j=1; j<=k; j++)
		{
			scanf("%d", &ll);
			bul[ll-1]=1;
		}
	}
	j=0;
	ll=1;
	while(j<m)
	{
		if(bul[j]==0)
		{
			ll=0;
			break;
		}
		j++;
	}
	if(ll==0)
		puts("NO");
	else
		puts("YES");	
	return 0;
}
