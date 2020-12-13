#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
const int N = 1e5+5;
int n;
int a[N];
char ans[N];
bool ok[300];
int st[50];
 
void al(int l,int r,char v){
	while(l<r)ans[l++]=v;
}
 
bool lt(pii x, pii y){
	return x.second==y.second ? x.first<y.first
														: x.second<y.second;
}
 
void f(int l,int r){
	while(l<r && a[l]==1)ans[l++]='+';
	while(l<r && a[r]==1)ans[--r]='+';
	if(l>=r)return;
 
	int x=1;
	int sp=0;
	for(int i=l;i<=r;i++){
		x*=a[i];
		if(x>=(r-l+1)*9){
			al(l,r,'*');
			return;
		}
		if(a[i]>1)
			st[sp++]=i;
	}
	int mx=0,id=0;
	for(int s=0;s<(1<<sp-1);s++){
		int v=0,w=a[st[0]];
		for(int i=0;i<sp-1;i++){
			int d=st[i+1];
			if(s&(1<<i)){
				w*=a[d];
			} else {
				v+=w+d-st[i]-1, w=a[d];
			}
		}
		if(mx<v+w)mx=v+w, id=s;
	}
	for(int i=0;i<sp-1;i++){
		char v=(id&(1<<i))?'*':'+';
		al(st[i],st[i+1],v);
	}
}
 
void solve(){
	int last=1;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			ans[i-1]=ans[i]='+';
			f(last, i-1);
			last = i+1;
		}
	}
	f(last,n);
}
 
int main(){
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>s;
	for(auto i:s)ok[i]=1;
	if(s.size()==1){
		al(1,n,s[0]);
	}else if(s.size()==2 && ok['-']){
		char v=ok['+']?'+':'*';
		for(int i=2;i<=n;i++)
			ans[i-1]=a[i]?v:'-';
	}else{
		solve();
	}
	ans[n]='\n';
	for(int i=1;i<=n;i++)
		cout<<a[i]<<ans[i];
	return 0;
}