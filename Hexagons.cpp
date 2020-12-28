#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        ll x,y,c1,c2,c3,c4,c5,c6;
        cin>>x>>y;
        cin>>c1>>c2>>c3>>c4>>c5>>c6;
        ll ans=(x>=0?c6:c3)*abs(x)+(y>=0?c2:c5)*abs(y);
        ans=min(ans,(x>=0?c1:c4)*abs(x)+(y-x>=0?c2:c5)*abs(y-x));
        ans=min(ans,(y>=0?c1:c4)*abs(y)+(y-x>=0?c3:c6)*abs(y-x));
        cout<<ans<<endl;
    }
}