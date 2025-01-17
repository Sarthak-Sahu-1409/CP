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

//binary search maybe...

// const int N=1200300;
// vector<int> adj[N];
// vector<int> color(N);

struct node
{
    int val,lazy;
    node(){val=0; lazy=0;}
};

node t[4*N];


void push(int id, int l, int r)
{
    if(t[id].lazy!=0)
    {
        t[id].val=t[id].lazy;
        if(l!=r)
        {
            t[2*id].lazy=t[id].lazy;
            t[2*id+1].lazy=t[id].lazy;
        }
        t[id].lazy=0;
    }
}

void build(int id, int l, int r)
{
    if(l==r) {t[id].val=bitmask[euler[l]]; t[id].lazy=0; return;}
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id].val=(t[2*id].val|t[2*id+1].val);
}

void update(int id, int l, int r, int lq, int rq, int value)
{
    push(id,l,r);
    if(lq>r || rq<l) return;
    if(lq<=l && r<=rq) {t[id].lazy=value; push(id,l,r); return;}
    int mid=(l+r)/2;
    update(2*id,l,mid,lq,rq,value);
    update(2*id+1,mid+1,r,lq,rq,value);
    t[id].val=(t[2*id].val|t[2*id+1].val);
}

int query(int id, int l, int r, int lq, int rq)
{
    push(id,l,r);
    if(l>rq || r<lq) return 0;
    if(lq<=l && r<=rq) return t[id].val;
    int mid=(l+r)/2;
    return (query(2*id,l,mid,lq,rq)|query(2*id+1,mid+1,r,lq,rq));
}

void solve()
{
    int n,q; cin>>n>>q; cnt=0;
    for(int i=1;i<=n;i++) {int x; cin>>x; bitmask[i]=(1ll<<x);}
    int m=n-1; while(m--)
    {
        int u,v; cin>>u>>v;
        adj[u].pb(v),adj[v].pb(u);
    } 
    dfs(1);
    lim=2*n;
    build(1,0,lim-1);
    while(q--)
    {
        int type; cin>>type;
        if(type==1)
        {
            int s,x; cin>>s>>x;
            update(1,0,lim-1,index[s].ff,index[s].ss,(1ll<<x));
        }
        else
        {
            int s;cin>>s;
            int ans=query(1,0,lim-1,index[s].ff,index[s].ss);
            cout<<__builtin_popcountll(ans)<<endl;
        }
    }
}

int32_t main()
{
    PIKACHU;
    //int _; cin>>_; while(_--)
    solve();
    return 0;
}