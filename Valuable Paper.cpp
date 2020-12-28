#include <iostream>
#include <algorithm>
#include <set>
 
using namespace std;
 
struct edge{
    int s,e,v;
};
 
bool cmp(edge a, edge b){
    return a.v < b.v;
}
 
int main(){
	int n,m;
	cin >> n >> m;
 
	edge e[m];
	for(int i=0 ; i<m ; i++){
        cin >> e[i].s >> e[i].e >> e[i].v;
	}
 
	sort(e,e+m,cmp);
 
	bool ok=false;
	set <int> a;
	set <int> b;
	for(int i=0 ; i<m ; i++){
        a.insert(e[i].s);
        b.insert(e[i].e);
        if(a.size()==n&&b.size()==n){
            ok=true;
            cout << e[i].v << endl;
            break;
        }
	}
 
	if(!ok) cout << -1 << endl;
 
	return 0;
}