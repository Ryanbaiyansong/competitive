#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int q,s;
char buf[10];
 
struct St{
	St(int be){
		mp[be]=0;
		g[0]=1;
	}
	void set(int v,ll c){
		base+=c;
		if(v==s) {
			return;
		}
		add(v,mi()-c);
	}
	void add(int v,ll c){
		if(mp.count(v)){
			if(mp[v]+base<=c)return;
			del(v);
		}
		if(mp.count(v))for(;;);
		c-=base;
		mp[v]=c;
		g[c]++;
	}
	ll mi(){
		return g.begin()->first+base;
	}
	bool has(int x){
		return mp.count(x);
	}
	void del(int x){
		if(!mp.count(x))for(;;);
		//assert(mp.count(x));
		ll c=mp[x];
		//if(g[c]<=0)for(;;);
		assert(g[c]>0);
		if(g[c]==1)g.erase(c);
		else g[c]--;
		mp.erase(x);
	}
	ll base=0;
	map<int,ll> mp;
	map<ll,int> g;
};
	
void merge(St& a, St& b){
	if(a.mp.size()<b.mp.size()) swap(a,b);
	for(const auto& i:b.mp){
		int v=i.first;
		a.add(v,i.second+b.base);
	}
}
 
St f(int be){
	St st(be);
	while(q-- > 0){
		scanf("%s",buf);
		int v,c;
		switch(buf[0]){
		case 's':
			scanf("%d%d",&v,&c);
				st.set(v,c);
			break;
		case 'i':
			{
			scanf("%d",&v);
			St tt=f(v);
			if(st.has(v)){
				tt.base+=st.mp[v]+st.base;
				st.del(v);
				merge(st, tt);
			}
			}
			break;
		case 'e':
			return st;
		default:
			exit(1);
		}
	}
	return st;
}
 
int main() {
	scanf("%d%d",&q,&s);
	St st=f(0);
	printf("%lld\n",st.mi());
	return 0;
}