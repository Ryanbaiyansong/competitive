#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ull unsigned long long int
#define ll long long int
#define pb push_back
#define mp make_pair
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define rep(i , L , R) for( i = L ; i < R ; i++)
#define per(i,L,R) for( i = L; i >= R; i--)
#define all(con) (con).begin(),(con).end()
#define fi first
#define se second
#define foreach(iter,con) (typeof((con).begin()) iter=(con).begin(); iter!=(con).end(); iter++)
#ifdef DEBUGG
#define deb(args...){dbg,args; cerr<<endl;}
#else
#define deb(args...)
#endif
struct debb{template<typename T> debb& operator,(const T &v){cerr<<v<<" ";return *this;}}dbg;
#define debug(args...) do {cerr << #args << ": "; dbg,args; cerr << "\n";} while(0)
#define printa(a,L,R) rep(i,L,R) cout << a[i] << (i==R?'\n':' ')
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
ll gcd(ll a, ll b){if(b==0)return a;else return gcd(b,a%b);}
ll power(ll x, ll y,ll p){ll res = 1;x=x%p;while(y>0){if(y&1)res=((res%p)*(x%p))%p;y=y>>1;x=(x*x)%p;}return res;}
 
int main()
{
   SPEED
   ll a1,a2,k1,k2,n,i,z=0,s2;
   cin>>a1>>a2>>k1>>k2>>n;
   ll s1 = (k1-1)*a1 + (k2-1)*a2;
   cout<<max(z,n-s1);
   if(k1<=k2)
   {
      s2 = min(a1,n/k1);
      n = n - (s2*k1);
      s2 += min(a2,n/k2);
   }
   else
   {
       s2 = min(a2,n/k2);
      n = n - (s2*k2);
      s2 += min(a1,n/k1);
   }
   cout<<" "<<s2<<"\n";
}
 
 
 