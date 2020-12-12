#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int> v[N];
int ans=1;
int dfs(int node,int par){
	
    vector<int>  sz;
	
	for(int ch:v[node]){
		if(ch!=par)
		{
			int val=dfs(ch,node);
			sz.push_back(val);
	
		}
	}
		sort(sz.begin(),sz.end());
		int z=sz.size();
		if(v[node].size()==1 and node!=1){ans=max(1,ans);return  1;}
		if(v[node].size()>=2){
			if(node==1)
				ans=max({ans,sz[z-1],sz[z-2]+1});
			else ans=max(ans,sz[z-1]+1);
		}
		
		return sz[0]+1;
 
		
		
 
	
 
}
int main(){
	int t;
	cin>>t;
	while(t--){
 
     
		int n;
		cin>>n;
		for(int i=0;i<n-1;i++){
			int x,y;
			cin>>x>>y;
			v[x].emplace_back(y);
			v[y].emplace_back(x);
		}
		ans=0;
		dfs(1,0);
//		cout<<"ans ";
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)v[i].clear();
 
		
 
 
		
	}
}