#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[70][70],dp[70][70][70][36];
int solve(int i,int j,int mod,int taken){
	if(i==n) return mod?-2e9:0;
	if(j==m || taken==m/2) return solve(i+1,0,mod,0);
	if(dp[i][j][mod][taken]!=-1) return dp[i][j][mod][taken];
	return dp[i][j][mod][taken]=max(solve(i,j+1,mod,taken),a[i][j]+solve(i,j+1,(mod+a[i][j])%k,taken+1));
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);
	memset(dp,-1,sizeof(dp));
	cin>>n>>m>>k;
	for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>a[i][j];
	cout<<solve(0,0,0,0);
}