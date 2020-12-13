
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
const int N=2005;
 
int n,m,s,ans,l[N],r[N];
 
int main()
{
	scanf("%d%d%d",&n,&m,&s); int i,j,k,res;
	for (i=1; i<=m; i++) scanf("%d%d",l+i,r+i);
	
	for (i=1; i<n-s+2; i++) for (j=1; j<n-s+2; j++,ans=std::max(ans,res))
		for (k=1,res=0; k<=m; k++) res+=std::max(std::max(std::min(r[k],i+s-1)-std::max(i,l[k])+1,std::min(r[k],j+s-1)-std::max(j,l[k])+1),0);
	printf("%d",ans);
	
	return 0;
}