#include<bits/stdc++.h>
using namespace std;
int deg[200005];
vector <int> e[200005];
int qwq[200005],u[200005],v[200005],w[200005],cnt;
queue <int> q;
int main(int argc, char** argv) 
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			deg[i]=0 , e[i].clear();
		for(int i=1; i<=m ;i++)
		{
			cin>>qwq[i]>>u[i]>>v[i];
			if(qwq[i]) ++deg[v[i]], e[u[i]].push_back(v[i]);
		}
		for(int i=1;i<=n;i++)
			if(!deg[i]) q.push(i);
		cnt=0;
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			w[x]=++cnt;
			for(auto v:e[x])
			{
				--deg[v];
				if(!deg[v]) q.push(v);
			}
		}
		if(cnt<n) puts("NO");
		else
		{
			puts("YES");
			for(int i=1;i<=m;i++)
			{
				if(w[u[i]]<w[v[i]]) cout << u[i] << " " << v[i] << "\n";
				else cout << v[i] << " " << u[i] << '\n';
			}
		}
	}
	return 0;
}