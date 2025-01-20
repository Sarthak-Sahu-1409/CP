#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#define PIKACHU {ios_base::sync_with_stdio(0); cin.tie(0);} 
#define flush(a) for(auto ptr: a) cout<<ptr<<" "; cout<<endl;
#define flushh(a,s,e) for(int i=s;i<=e;i++) cout<<a[i]<<" "; cout<<endl;
#define int long long int 
#define all(a) a.begin(),a.end() 
#define pb push_back
#define vvi vector<vector<int>>
#define vi vector<int>
#define pii pair<int,int>
#define read(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define ff first
#define ss second
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define mod 1000000007
#define modd 998244353
#define endl '\n'
#define watch(x) cout<<"The value of "<<(#x)<<" is "<<(x)<<endl
#define f_tree tree<int, null_type, less<int>, rb_tree_tag,  tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

const int N=3e5+5;
vector<int> adj[N];
vector<int> level(N,0);

void dfs(int node, int parent, vvi&dp, int curr)
{
    dp[node][0]=parent;
    level[node]=curr;
    for(int i=1;i<21;i++) dp[node][i]=dp[dp[node][i-1]][i-1];
    for(auto child: adj[node])
    if(child!=parent) dfs(child,node,dp,curr+1);
}
 
int lca(int u, int v, vvi&dp)
{
    if(level[u]<level[v]) swap(u,v);
    for(int i=20;i>=0;i--)
    {
        if((level[u]-level[v])&(1<<i)) u=dp[u][i];
    }
    if(u==v) return u;
    for(int i=20;i>=0;i--)
    {
        if(dp[u][i]!=dp[v][i]) u=dp[u][i],v=dp[v][i];
    }
    return dp[u][0];
}

void solve()
{
    
    vvi dp(n+1, vi (21,0));
    
    dfs(1,0,dp,0);
    
}

int32_t main()
{
    PIKACHU;
    //int _; cin>>_; while(_--)
    solve();
    return 0;
}