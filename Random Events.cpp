#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, n, m, r;
	double c;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int p[n];
		for(int i = 0;i < n;i++) {
			cin >> p[i];
		}
		int i;
		for(i = n-1;i >= 0;i--){
			if(p[i] != i+1) break;
		}
		double b = 0;
		if(i < 0) b = 1;
		while(m--){
			cin >> r >> c;
			if(r > i) b += c - b*c;
		}
		printf("%.8f\n", b);
	}
}