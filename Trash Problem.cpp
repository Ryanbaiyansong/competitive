#include<stdio.h>
#include<set>
#define it register int
#define ct const int
#define il inline
using namespace std;
int n,Q;
set<int> S;
multiset<int> D;
il void add(ct x){
	auto pre=S.lower_bound(x),nxt=S.upper_bound(x);
	if(pre!=S.begin()&&nxt!=S.end()) --pre,D.erase(D.find(*nxt-*pre)),++pre;
	if(pre!=S.begin()) --pre,D.insert(x-*pre);
	if(nxt!=S.end()) D.insert(*nxt-x);
	S.insert(x);
}
il void del(ct x){
	auto pre=S.lower_bound(x),nxt=S.upper_bound(x);
	if(pre!=S.begin()) --pre,D.erase(D.find(x-*pre)),++pre;
	if(nxt!=S.end()) D.erase(D.find(*nxt-x));
	if(pre!=S.begin()&&nxt!=S.end()) --pre,D.insert(*nxt-*pre);
	S.erase(S.find(x));
}
il void cal(){printf("%d\n",S.size()<=2?0:*S.rbegin()-*S.begin()-*D.rbegin());}
int main(){
	scanf("%d%d",&n,&Q);it i,x;
	for(i=1;i<=n;++i) scanf("%d",&x),add(x);
	cal();
	while(Q--) scanf("%d%d",&i,&x),i?add(x):del(x),cal();
	return 0;
}
