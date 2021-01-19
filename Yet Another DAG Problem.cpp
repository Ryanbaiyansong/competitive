#include<bits/stdc++.h>
using namespace std;
const int N=18;
int n,m,t[N],p[1<<N],f1[1<<N],f2[1<<N],ans[N];
long long dp[1<<N],a[N],sum[1<<N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		u--,v--;
		a[u]+=c;
		a[v]-=c;
		t[v]|=(1<<u);
	}
	for(int s=0;s<(1<<n);s++)
	{
		dp[s]=1e18;
		int c=0;
		for(int i=0;i<n;i++)
		{
			if(s&(1<<i))
			{
				sum[s]+=a[i];
				c|=t[i];
			}
		}
		if((c&s)==c) f1[s]=1;
		if((c&s)==0) f2[s]=1;
	}
	dp[0]=0;
	for(int i=0;i<(1<<n);i++)
	{
		if(dp[i]>1e17)
			continue;
		int s=(((1<<n)-1)^i);
		for(int t=s;t;t=(t-1)&s)
		{
			if(f1[i^t]&&f2[t])
			{
				int c=dp[i]+sum[i^t];
				if(dp[i^t]>c)
				{
					dp[i^t]=c;
					p[i^t]=i;
				}
			}
		}
	}
	int s=(1<<n)-1;
	for(int i=0;i<n;i++)
	{
		if(!s)
			break;
		int t=p[s];
		for(int j=0;j<n;j++)
			if((s^t)&(1<<j))
				ans[j]=i;
		s=t;
	}
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
	return 0;
}