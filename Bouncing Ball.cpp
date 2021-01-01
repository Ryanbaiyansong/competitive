#include <iostream>
#include <algorithm>
using namespace std;
int t,n,p,k,dp[200100],x,y,m;
char d[200100];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>p>>k>>d>>x>>y;
		m=1000000007;
		p--;
		for(int i=n-1;i>=p;i--){
			dp[i]=x*(1-d[i]+'0');
			if(i+k<n)dp[i]+=dp[i+k];
			m=min(m,(i-p)*y+dp[i]);
		}
		cout<<m<<endl;
	}
}