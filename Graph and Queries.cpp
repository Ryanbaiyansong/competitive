#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
 
int const N = 200000, M = 300000, Q = 500000;
int n, m, q, p[N + 1], T, pa[N + 1];
bool off[M + 1];
pair<int, int> qu[Q], ed[M + 1];
set<int> st[N + 1];
 
struct O{
	int i, j, v, t;
	O(int a, int b, int c, int d):i(a), j(b), v(c), t(d) {}
	void roll(){
		if (v == 0)pa[i] = 0;
		else {
			auto it = st[j].find(v);
			if (it == st[j].end())return;
			st[j].erase(it);
			st[i].insert(v);
		}
	}
};
vector<O> op;
 
int P(int v) { while (pa[v])v = pa[v]; return v; }
 
void J(int a, int b){
	++T;
	a = P(a);
	b = P(b);
	if (a == b)return;
	if (st[a].size() < st[b].size())swap(a, b);
	pa[b] = a;
	op.emplace_back(b, a, 0, T);
	while (!st[b].empty()){
		st[a].insert(*st[b].begin());
		op.emplace_back(b, a, *st[b].begin(), T);
		st[b].erase(st[b].begin());
	}
}
 
int main(){
	scanf("%d%d%d", &n, &m, &q);
	f(i, 1, n + 1)scanf("%d", p + i);
	f(i, 1, m + 1){
		int a, b;
		scanf("%d%d", &a, &b);
		ed[i] = make_pair(a, b);
	}
	
	f(i, 0, q){
		scanf("%d%d", &qu[i].first, &qu[i].second);
		if (qu[i].first == 2)off[qu[i].second] = true;
	}
	
	f(i, 1, n + 1)st[i].insert(p[i]);
	
	f(i, 1, m + 1)if (!off[i])J(ed[i].first, ed[i].second);
	for (int i = q - 1; i >= 0; --i)if (qu[i].first == 2)J(ed[qu[i].second].first, ed[qu[i].second].second);
	
	f(i, 0, q)if (qu[i].first == 1){
		int t = P(qu[i].second);
		printf("%d\n", st[t].empty() ? 0 : *st[t].rbegin());
		if (!st[t].empty())st[t].erase(--st[t].end());
	}else {
		while (!op.empty() && op.back().t == T){
			op.back().roll();
			op.pop_back();
		}
		--T;
	}
}