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
#define watch(x) cout<<(#x)<<" : "<<(x)<<endl
#define f_tree tree<int, null_type, less<int>, rb_tree_tag,  tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

struct node
{
    
};
 
node t[4*200200];
int a[200200];
 
node merge(node a, node b)
{
    node ans;
    
    return ans;
}
 
void build(int id, int l, int r)
{
    if(l==r) {t[id].val=a[l]; t[id].dist=0; return;}
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=merge(t[2*id],t[2*id+1]);
}
 
void update(int id, int l, int r, int pos, int value)
{
    if(pos<l || pos>r) return;
    if(l==r) {t[id].val=value; return;}
    int mid=(l+r)/2;
    update(2*id,l,mid,pos,value);
    update(2*id+1,mid+1,r,pos,value);
    t[id]=merge(t[2*id],t[2*id+1]);
}
 
node query(int id, int l, int r, int lq, int rq)
{
    if(l>rq || r<lq) return node();
    if(lq<=l && r<=rq) return t[id];
    int mid=(l+r)/2;
    return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}

void solve()
{
    build(1,0,n-1);
    while(q--)
    {
        update(1,0,n-1,pos,value);
        a[pos]=value;
        node ans = query(1,0,n-1,{l},{r});
        cout<<ans.val<<endl;
    }
}

int32_t main()
{
    PIKACHU;
    //int _; cin>>_; while(_--)
    solve();
    return 0;
}