#include <bits/stdc++.h>
#define ll long long
#define N 200010
 
using namespace std;
 
int t,n,k,a,b;
int in[N];
 
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		map<int,map<int,int> > m;
		vector<int> in(n+10,0);
		vector<int> leaf(n+10,0);
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			m[a][b]=1;
			m[b][a]=1;
			in[a]++;
			in[b]++;
		}
		queue<int> q;
		for(int i=1;i<=n;i++)
		{
			if(in[i]==1)
				q.push(i);
		}
		int ct=0;
		while(!q.empty())
		{
			int i=q.front();
			q.pop();
			if(!m[i].empty())
			{
				int x=m[i].begin()->first;
				m[x].erase(i);
				leaf[x]++;
				if(leaf[x]%k==0)
					ct++;
				if(leaf[x]==in[x]-1 && (in[x]-1)%k==0)
					q.push(x);
			}
		}
		printf("%d\n", ct);
	}
	return 0;
}