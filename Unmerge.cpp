#include <bits/stdc++.h>
using namespace std;
int n,x;
void sol()
{
	cin>>n;
	bool kt[2001]={0};
	kt[0]=1;
	vector<int>a;
	for(int i=1;i<=n+n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	for(int i=0,j=0;i<a.size();i=j)
	{
		while(a[i]>=a[j]&&j<a.size()) j++;
		for(int k=n;k+i>=j;k--) kt[k]|=kt[k+i-j];
	}
	if(kt[n]) cout<<"YES\n";
	else cout<<"NO\n";
}
main()
{
	int t;
	cin>>t;
	while(t--) sol();
}