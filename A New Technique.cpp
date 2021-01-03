#include<bits/stdc++.h>
int a[250010],p[510][510],T,n,m;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		for(int j=1,x;j<=m;j++)
			scanf("%d",&x),a[x]=j;
		for(int i=1;i<=m;i++)
		for(int j=1,x;j<=n;j++)
			scanf("%d",&x),p[j][a[x]]=x;
		for(int i=1;i<=n;i++)
		{for(int j=1;j<=m;j++)
			printf("%d ",p[i][j]);
		puts("");
		}
	}
	return 0;
}