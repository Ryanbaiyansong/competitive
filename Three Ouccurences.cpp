#include <bits/stdc++.h>
using namespace std;
 
int const N = 500'001;
mt19937_64 g;
using R = decltype(g());
R h[N], s[N];
int a[N], c[N], t[N];
map<R, int> m;
long long x;
int l, n, r = 1;
 
signed main()
{
    generate(h, h + N, g);
    scanf("%d", &n);
    for (++m[0]; r <= n; ++r) {
        scanf("%d", a + r);
        if ((++c[a[r]]) % 3) {
            s[r] = s[r - 1] + h[a[r]];
        } else {
            s[r] = s[r - 1] - (h[a[r]] << 1);
        }
        for (++t[a[r]]; t[a[r]] > 3; --t[a[++l]]) {
            --m[s[l]];
        }
        x += m[s[r]]++;
    }
    printf("%lld\n", x);
}