#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v[200003],g[200003];
long long dist[2][2][200003];
int main(){
	cin>>n>>m;
	while(m--){
		int x,y,w;
		cin>>x>>y>>w;
		x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
		g[x].push_back(w);
		g[y].push_back(w);
	}
	priority_queue<pair<long long,pair<int,pair<bool,bool> > > >Q;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<200003;k++)
				dist[i][j][k]=4611686018427387902;
	Q.push(make_pair(0,make_pair(0,make_pair(0,0))));
	dist[0][0][0]=0;
	while(Q.size()){
		long long dst=-Q.top().first,x=Q.top().second.first,y=Q.top().second.second.first,z=Q.top().second.second.second;Q.pop();
//		cout<<x+1<<' '<<y<<' '<<z<<' '<<dst<<endl;
		if(dst!=dist[y][z][x])continue;
		for(int k=0;k<v[x].size();k++)
			for(int i=y;i<2;i++)
				for(int j=z;j<2;j++)
					if(dist[i][j][v[x][k]]>dst+(i-y-j+z+1)*g[x][k]){
						dist[i][j][v[x][k]]=dst+(i-y-j+z+1)*g[x][k];
						Q.push(make_pair(-dist[i][j][v[x][k]],make_pair(v[x][k],make_pair(i,j))));
					}
	}
	for(int i=1;i<n;i++)
		cout<<dist[1][1][i]<<' ';
}