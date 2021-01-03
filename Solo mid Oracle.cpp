 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	long long t, a, b, c, d;
	for(cin >> t; t; t --) {
		cin >> a >> b >> c >> d;
		if(a > b * c) puts("-1");
		else cout << (((a - 1) / b) / d + 1) * a - ((a - 1) / b / d) * ((a - 1) / b / d + 1) / 2 * b *d << endl;
	}
 
	return 0;
}