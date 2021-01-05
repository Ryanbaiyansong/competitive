#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100; 
int t;
int n;
int a[maxn];
int b[maxn];
vector<int> g[maxn];
int visit[maxn];
vector<int> wjm;
int main () {
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) g[i].clear();
		wjm.clear();
		memset(visit,0,sizeof(visit));
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			g[a[i]].push_back(i);
		}
		for (int i=1;i<=n;i++) {
			scanf("%d",&b[i]);
			g[b[i]].push_back(i);
		}
		bool f=true;
		for (int i=1;i<=n;i++) if (g[i].size()!=2) f=false;
		if (!f) {
			printf("-1\n");
			continue;
		}
		for (int i=1;i<=n;i++) {
			if (visit[i]) continue;
			if (g[i][0]==g[i][1]) continue;
			vector<int> x,y;
			for (int j=i,k=g[i][0];!visit[j];) {
				visit[j]=1;
				k=g[j][0]^g[j][1]^k;
				if (a[k]==j) {
					x.push_back(k);
					j=b[k];
				}
				else {
					y.push_back(k);
					j=a[k];
				}
			}
			if (x.size()<y.size()) 
				wjm.insert(wjm.end(),x.begin(),x.end());
			else
				wjm.insert(wjm.end(),y.begin(),y.end());
		}
		printf("%d\n",wjm.size());
		for (auto i:wjm) printf("%d ",i);
		printf("\n");
	}
}