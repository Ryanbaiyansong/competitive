#include<bits/stdc++.h>
using namespace std;
const int N=20;
const int M=100;
int a[N],t,n;
bool v[M];
int main()
{
	cin>>n;
	for(int i=0;i<6*n;i++) cin>>a[i],v[a[i]]=1;
	for(int i=0;i<6*n;i++)for(int j=0;j<6*n;j++)if(i!=j && i/6!=j/6)v[a[i]*10+a[j]]=1;
	while(v[++t]);cout<<t-1<<endl;
}