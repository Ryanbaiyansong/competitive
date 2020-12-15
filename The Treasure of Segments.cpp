#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, ans = 2147483647;
		scanf("%d", &n);
		int l[n], r[n], v[n], w[n];
		for (int i = 0; i < n; i++){
			scanf("%d %d", &l[i], &r[i]);
			v[i] = l[i], w[i] = r[i];
		}
		sort(v, v + n), sort(w, w + n);
		for (int i = 0; i < n; i++){
			int c = (lower_bound(w, w + n, l[i]) - w) + n - (upper_bound(v, v + n, r[i]) - v);
			ans = min(ans, c);
		}
		printf("%d\n", ans);
	}
}