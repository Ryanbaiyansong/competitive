#include<bits/stdc++.h>
using namespace std;
int n,T,k,a[200010],b,f[200010],l[200010],ans; 
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)scanf("%d",&b);
		for(int i=1;i<=n;i++)l[i]=lower_bound(a+1,a+i+1,a[i]-k)-a;
		for(int i=1;i<=n;i++){
			ans=max(f[l[i]-1]+i-l[i]+1,ans);
			f[i]=max(f[i-1],i-l[i]+1);
		}
		printf("%d\n",ans);
	}
} 