#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[5],y[5],xx[5],yy[5],c[5],T;
 
signed main()
{	
	scanf("%lld",&T);
	while(T--)
	{
		int nw,ans=2e9,xl,xr,yl,yr;
		for(int i=1;i<=4;i++) scanf("%lld%lld",&xx[i],&yy[i]),c[i]=i;
		do {
			for(int i=1;i<=4;i++) x[i]=xx[c[i]],y[i]=yy[c[i]];
			nw=abs(y[1]-y[2])+abs(y[3]-y[4])+abs(x[1]-x[3])+abs(x[2]-x[4]);
			yl=min(y[3],y[4])-max(y[1],y[2]),yr=max(y[3],y[4])-min(y[1],y[2]);
			xl=min(x[2],x[4])-max(x[1],x[3]),xr=max(x[2],x[4])-min(x[1],x[3]);
			if(xr<yl) nw+=(yl-xr)*2;
			if(xl>yr) nw+=(xl-yr)*2;
			ans=min(ans,nw);
		}while(next_permutation(c+1,c+5));
		printf("%lld\n",ans);
	}
	return 0;
}
