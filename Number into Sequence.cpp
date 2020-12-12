#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,t;
 
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		ll b=1,j;
		for(ll i=2;i<=sqrt(n);i++){
			ll n2 = n,ta=0;
			while(n2%i==0){
				n2/=i;
				ta++;
			}
			if(ta>b){
				b = ta;
				j = i;
			}
		}
		cout<<b<<'\n';
		for(ll i=1;i<b;i++){cout<<j<<' ';n/=j;}
		cout<<n<<'\n';
	}
 
 
}