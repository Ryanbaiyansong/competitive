#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a;
	cin>>a;
	for(ll i=0;i<a;i++){
		ll k;
		cin>>k;
		set<ll> x;
		for(ll j=1;j*j<=k;j++){
			if(k%j == 0){
				if(j*j == k){
					x.insert(j);
				}
				else{
					x.insert(j);
					x.insert(k/j);
				}
			}
		}
		x.erase(1);
		vector<ll> y;
		y.push_back(*x.begin());
		x.erase(*x.begin());
		set<ll>::iterator it;
		while(!x.empty()){
			for(it = x.begin();it!=x.end();it++){
				if(__gcd(y.back(),*it) != 1){
					y.push_back(*it);
					x.erase(*it);
					break;
				}
			}
		}
		for(ll j=0;j<y.size();j++){
			cout<<y[j]<<" ";
		}
		cout<<"\n";
		if(__gcd(y[0],y.back()) == 1){
			cout<<1<<"\n";
		}
		else{
			cout<<0<<"\n";
		}
		
	}
}