#include <cstdio>
int a[5005];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		int j=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]!=a[1])j=i;
		}
		if(j==0){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=2;i<=n;i++)if(a[i]!=a[1])printf("%d %d\n",1,i);
		else printf("%d %d\n",j,i);
	}
	return 0;
} 