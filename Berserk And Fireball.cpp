#import<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL i,j,k,m,n,p,r,s,x,y,a[200040],b[200040],c[200040];
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>x>>k>>y;
	for(;i++<n;)cin>>a[i];
	for(i=0;i++<m;)
	{
		cin>>p;
		for(;j<=n&&a[j]^p;)j++;
		if(j>n)
		{
			cout<<-1;
			return 0;
		}
		b[i]=j;
	}
	b[++m]=n+1;
	for(i=0;i++<m;)
	{
		for(j=b[i-1],p=0;++j<b[i];)
		{
			if(a[j]>a[b[i-1]]&&a[j]>a[b[i]])p++;
		}
		r=b[i]-b[i-1]-1;
		if(p&&r&&r<k)
		{
			cout<<-1;
			return 0;
		}
		else
		{
			if(p)s+=r%k*y+(r/k-1)*min(x,k*y)+x;
			else s+=r%k*y+r/k*min(x,k*y);
		}
	}
	cout<<s;
}