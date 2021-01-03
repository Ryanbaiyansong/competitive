#include<bits/stdc++.h>
#define N 200001
using namespace std;
int n,tot,mx[N],st[N],pos,ans[N],top;
char opt;
signed main(void){
	int pos=0,i,x,y;scanf("%d",&n);
	for(i=1;i<=2*n;++i){
		cin>>opt;if(opt=='+')st[++top]=++pos;
		if(opt=='-'){
			scanf("%d",&x);
			if(!top)return puts("NO"),0;
			if(x<mx[st[top]])return puts("NO"),0;
			ans[st[top--]]=x,mx[st[top]]=max(mx[st[top]],max(mx[st[top+1]],x));
		}
	}
	puts("YES");for(i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}