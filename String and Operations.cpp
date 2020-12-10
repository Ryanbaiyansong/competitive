#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int TC;
	cin>>TC;
	while(TC--) {
		int N, M;
		string S;
		cin>>N>>M>>S;
		auto f=[&](char c) {
			return c=='a'+M-1 ? 'a' : char(c-(c!='a'));
		};
		for(int i=0, p=1; i<N; i++) {
			char a=p ? f(S[i]) : S[i];
			char b=i+1<N ? p ? f(S[i+1]) : S[i+1] : 'z';
			p=0;
			if(i+2<N && S[i+2]<min(a, b)) {
				cout<<S[i+2]<<a;
				S[i+2]=S[i+1];
				i++;
			} else if(b<a) {
				cout<<b;
				S[i+1]=b==S[i+1] ? a : S[i];
			} else {
				cout<<a;
				p=1;
			}
		}
		cout<<'\n';
	}
}