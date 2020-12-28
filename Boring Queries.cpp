#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second
 
const int mod = 1000000007;
 
struct segTree{
	int l, r;
	segTree *tl = 0, *tr = 0;
	ll val = 1, chg = 0;
	
	segTree(int a, int b) : l(a), r(b){}
	
	segTree(segTree *cp){
		l = cp->l, r = cp->r;
		tl = cp->tl, tr = cp->tr;
		val = cp->val;
		if(l != r){
			if(tl) tl->chg = 1;
		    if(tr) tr->chg = 1;
		}
	}
	
	void add(int x, ll v){
		if(l == r) return (void)((val *= v) %= mod);
		int mid = (l + r) / 2;
		if(x <= mid){
			if(!tl) tl = new segTree(l, mid);
			else if(tl->chg) tl = new segTree(tl);
			tl->add(x, v);
		}else{
			if(!tr) tr = new segTree(mid + 1, r);
			else if(tr->chg) tr = new segTree(tr);
			tr->add(x, v);
		}
		val = (tl ? tl->val : 1) * (tr ? tr->val : 1) % mod;
	}
	
	ll qry(int a, int b){
		if(b < l || r < a) return 1;
		if(a <= l && r <= b) return val;
		return (tl ? tl->qry(a, b) : 1) * (tr ? tr->qry(a, b) : 1) % mod;
	}
};
 
const int k = 200001;
int n, q;
ll p[k], lp[k], iv[k];
vector<int> pr;
segTree *tre[k];
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	iv[0] = iv[1] = 1;
	for(int i = 2; i < k; i++){
		iv[i] = mod - mod / i * iv[mod % i] % mod;
		if(!lp[i]) pr.push_back(lp[i] = i);
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < k; j++){
			lp[i * pr[j]] = pr[j];
		}
	}
	
	cin >> n;
	
	tre[0] = new segTree(1, n);
	for(int i = 1; i <= n; i++){
		ll x, y;
		cin >> x;
		tre[i] = new segTree(tre[i - 1]);
		for(; ~-x; x /= y){
			for(y = lp[x]; !(x % y); y *= lp[x]){
				if(p[y]) tre[i]->add(p[y], iv[lp[x]]);
				p[y] = i;
			}
			tre[i]->add(i, y /= lp[x]);
		}
	}
	
	cin >> q;
	
	for(int x = 0; q; q--){
		int l, r;
		cin >> l >> r;
		(l += x) %= n, (r += x) %= n;
		if(l++ > r++) swap(l, r);
		cout << (x = tre[r]->qry(l, r)) << endl;
	}
 
	return 0;
}