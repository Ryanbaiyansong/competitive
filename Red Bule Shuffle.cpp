#include<bits/stdc++.h>
using namespace std;
int main()
{int t;cin>>t;while(t--){int n,i,c=0;cin>>n;string s,t;cin>>s>>t;for(i=0;i<n;i++)
if(s[i]>t[i])c++;else if(t[i]>s[i])c--;cout<<((c>0)?"RED":((c<0)?"BLUE":"EQUAL"))<<"\n";}}