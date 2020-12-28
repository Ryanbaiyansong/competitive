#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
int dis[N],n,m,x[N],y[N],ex,ey;
set<pair<int,int> > r,c;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void solve(int u,int v){
	int d=dis[u]+min(abs(x[u]-x[v]),abs(y[u]-y[v]));
	if(dis[v]>d){
		dis[v]=d;
		q.push({d,v});
	}
}
void dij(){
	dis[0]=0;q.push({0,0});
	while(!q.empty()){
		int d=q.top().first,u=q.top().second;q.pop();
		if(dis[u]!=d)continue;
		r.erase({x[u],u});
		c.erase({y[u],u});
		auto it=r.lower_bound({x[u],0});
		if(it!=r.end())solve(u,(*it).second);
		if(it!=r.begin()){it--;solve(u,(*it).second);}
		it=c.lower_bound({y[u],0});
		if(it!=c.end())solve(u,(*it).second);
		if(it!=c.begin()){it--;solve(u,(*it).second);}
	} 
	int ans=INT32_MAX;
	for(int i=0;i<=m;i++){
		ans=min(ans,dis[i]+abs(x[i]-ex)+abs(y[i]-ey));
	}
	cout<<ans<<endl;
}
int main(){
	cin>>n>>m;
	cin>>x[0]>>y[0]>>ex>>ey;
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i];
		r.insert({x[i],i});
		c.insert({y[i],i});
	}
	memset(dis,INF,sizeof dis);
	dij();
	return 0;
} 