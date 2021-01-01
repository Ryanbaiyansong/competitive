#include <bits/stdc++.h>
 
using namespace std;
 
int n, k;
long long ans, x[500005], cur;
 
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", x + i);
	sort(x, x + n);
	while (n && cur >= 0) {
		ans += cur;
		cur += x[--n];
	}
	x[n++] = cur;
	k++;
	for (int i = 0; i < n; i++)
		ans += i / k * x[i];
	printf("%lld\n", ans);
}