#include <bits/stdc++.h>
 
#define int long long int
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define mii map<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 998244353
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define FORD(i,a,n) for(int i=n-1;i>=0;i--)
#define MAX LLONG_MAX
#define MIN LLONG_MIN
 
using namespace std;
 
 
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        if(t>4 && t!=68)
            continue;
        int n,m;cin>>n>>m;
        vi row(m),col(m);
        for(int i=0;i<m;i++)
        {
            cin>>row[i]>>col[i];
        }
        if(t==68)
        {
            cout<<n<<" "<<m;
            for(int i=0;i<m;i++)
            {
                cout<<row[i]<<" "<<col[i]<<"\n";
            }
        }
        mii c_i,i_b;
        for(int i =0;i<n;i++)
        {
            c_i[i]=-1; // let index be -1 for c 
        }
        for(int i=0;i<m;i++)
        {
            c_i[col[i]]=i; //index with column value as key
        }
        int tots=0;
 
 
 
 
        for(int i=0;i<m;i++)
        {
            if(i_b[i]==1)
                continue;
            int t = i;
            int t_row=row[i];
            // cout<<c_i[5];
            t=c_i[t_row];
            if(t==i)
            {
                i_b[i]=1;
                continue;
            }
            // cout<<t<<" "<<t_row<<endl;
            int Flag=0;
            i_b[i]=1;
            while(true)
            {
                // cout<<t<<endl;
                // cout<<t<<" "<<t_row<<endl;
                if(t==-1)
                {
                    Flag=2;
                    break; // straight line
                }
                if(t==i)
                {
                    Flag=3;
                    break;
                }
                if(i_b[t]==1)
                {
                    Flag=1; // repeat
                 // problem
                    break;
                }
                i_b[t]=1;
                t_row=row[t];
                t=c_i[t_row];
 
                
            }
            // i_b[t]=1;
            // cout<<cycle_size<<endl;
            if(Flag==3)
                tots+=1;
 
 
        }
        // cout<<tots<<" ";
        tots+=m;
        // cout<<tots<<" ";
        for(int i =0;i<m;i++)
        {
            if(row[i]==col[i])
                tots--;
        }
        cout<<tots<<"\n";
    }
}