#include <bits/stdc++.h>
#define ll long long
#define ff(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
 
 
 
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		int ans=0;
		ff(i,0,20){
			int next=INT_MAX;
			ff(j,0,n) if(a[j]==(i+'a')&&a[j]!=b[j]&&b[j]>a[j]) next = min(next,b[j]-'a');
			ff(j,0,n) if(a[j]==(i+'a')&&a[j]!=b[j]&&b[j]>a[j]) a[j] = next+'a';
			if(next!=INT_MAX) ans++;
		}
		if(a==b)
		cout<<ans<<"\n";
		else cout<<"-1\n";
	}
}