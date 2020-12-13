#include<bits/stdc++.h>
using namespace std;
int n,x,p,y,z,l,h,d,a=1,m=1000000007;
int main() {
    for(scanf("%d%d%d",&n,&x,&p),y=x-1,z=n-x,h=n; l<h; p<(d=l+h>>1)?
            (a=z--*1LL*a%m,h=d):(p==d?0:a=y--*1LL*a%m,l=d+1));
    for(z+=y; 0<z; a=z--*1LL*a%m);
    printf("%d\n",a),exit(0);
}
