#include<bits/stdc++.h>
using namespace std;long long n,t,mod=1000000007;
int main(){scanf("%lld",&t);while(t--){scanf("%lld",&n);n>>=1;n+=2;printf("%lld\n",(((n>>1)%mod)*(((n+1)>>1)%mod))%mod);}}
