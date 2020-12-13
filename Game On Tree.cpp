#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+5;
int n;
vector<int> ve[N];
int d[N];
int ans[N];
bool b[N];
vector<int> p[N];
int mx;
int h[N];
 
void solve(){
	queue<pair<int,int>> q;
	for(int i=mx;i>0;i--){
		for(int x : p[i])
			if(h[x]<d[x]) {
				if(!ans[x])ans[x]=i;
        h[x]=d[x];
        q.push({d[x],x});
      }
		while(!q.empty()){
			int v=q.front().first;
			int x=q.front().second;
      // cout<<x<<' '<<v<<endl;
			q.pop();
			if(--v==0)continue;
			for (int y:ve[x]) {
        int tv=min(v,d[y]);
				if(h[y]<tv) {
          h[y]=tv;
					if(!ans[y])ans[y]=i;
          q.push({tv, y});
        }
      }
		}
	}
}
 
int main() {
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;i++)
		scanf("%d%d",&x,&y),ve[x].push_back(y),ve[y].push_back(x);
 
	int k;
	queue<int> q;
 	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&x);
		b[x]=1;
		q.push(x);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for (int y : ve[x])
			if(!b[y])
				q.push(y),b[y]=1,d[y]=d[x]+1;
		mx=max(mx,d[x]);
		p[d[x]].push_back(x);
	}
 
	solve();
 
	for(int i=1;i<=n;++i)
		printf("%d%c",ans[i],i==n?10:' ');
 
	return 0;
}