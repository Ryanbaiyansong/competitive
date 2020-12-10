#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<set<int>>m(n);
		int i;
		for(i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			x--;y--;
			m[x].insert(y);
			m[y].insert(x);
		}
		queue<int>leafs;
		for(i=0;i<n;i++)
		{
			if(m[i].size()==1)
				leafs.push(i);
		}
		vector<int>val(n,1);
		while(!leafs.empty())
		{
			int u=leafs.front();
			leafs.pop();
			int v=*m[u].begin();
			val[v]+=val[u];
			val[u]=0;
			m[v].erase(u);
			if(m[v].size()==1)
				leafs.push(v);
		}
		long long ans=0;
		for(i=0;i<n;i++)
		{
			ans+=(val[i]*1ll*(val[i]-1))/2;
			ans+=val[i]*1ll*(n-val[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}