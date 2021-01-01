#include<bits/stdc++.h>
using namespace std;
int n;
int a[300010];
pair<int,int>p[300010];
long long ans;
int x;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=0;i<=30;i++)
	{
		for(int j=1;j<=n;j++)p[j]=make_pair(a[j]>>i+1,j);
		sort(p+1,p+n+1);
		long long s0=0,s1=0;
		for(int j=1;j<=n;)
		{
			int k=j;
			int c0=0,c1=0;
			while(k<=n && p[k].first==p[j].first)
			{
				if(~a[p[k].second]>>i&1)s0+=c1,c0++;else s1+=c0,c1++;
				k++;
			}
			j=k;
		}
		if(s0<=s1)ans+=s0;else ans+=s1,x|=(1<<i);
	}
	printf("%lld %d",ans,x);
	return 0;
} 