#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
const int N=1010;
const int INF=0x3f3f3f3f;
int g[N][N],u[N*N],v[N*N],w[N*N],a[N],b[N];
int n,m,k;
 
int main() {
	cin>>n>>m>>k;
	memset(g,0x3f,sizeof g);
	for(int i=1; i<=n; ++i)
		g[i][i]=0;
	for(int i=1; i<=m; ++i)
		cin>>u[i]>>v[i]>>w[i],
		    g[u[i]][v[i]]=g[v[i]][u[i]]=min(g[u[i]][v[i]],w[i]);
	for(int i=1; i<=k; ++i)
		cin>>a[i]>>b[i];
	for(int l=1; l<=n; ++l)
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				g[i][j]=min(g[i][j],g[i][l]+g[l][j]);
	int res=INF;
	for(int i=1; i<=m; ++i) {
		int sum=0;
		for(int j=1; j<=k; ++j)
			sum+=min({g[a[j]][b[j]],g[a[j]][u[i]]+g[v[i]][b[j]],g[b[j]][u[i]]+g[v[i]][a[j]]});
		res=min(res,sum);
	}
	cout<<res<<endl;
	return 0;
}
