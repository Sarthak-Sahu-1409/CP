#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#define PIKACHU {ios_base::sync_with_stdio(0); cin.tie(0);} 
#define flush(a) for(auto ptr: a) cout<<ptr<<" "; cout<<endl;
#define flushh(a,s,e) for(int i=s;i<=e;i++) cout<<a[i]<<" "; cout<<endl;
#define all(a) a.begin(),a.end() 
#define pb push_back
#define vvi vector<vector<int>>
#define vi vector<int>
#define pii pair<int,int>
#define read(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define ff first
#define ss second
#define yes {cout<<"YES\n";}
#define no {cout<<"NO\n";}
#define mod 1000000007
#define modd 998244353
#define endl '\n'
#define watch(x) cout<<"The value of "<<(#x)<<" is "<<(x)<<endl
#define f_tree tree<int, null_type, less<int>, rb_tree_tag,  tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

struct node
{
    node *child[3];
    bool end;
    node()
    {
        for(int i=0;i<3;i++) child[i]=NULL;
        end=false;
    }
};

struct Trie
{
    node *root;
    Trie()
    {
        root=new node();
    }

    void insert(string s)
    {
        node *cur=root;
        for(int i=0;i<s.length();i++)
        {
            int x=s[i]-'a';
            if(cur->child[x]==NULL) cur->child[x]=new node;
            cur=cur->child[x];
        }
        cur->end=true;
    }
};

void query(node*cur, int pos, int mismatch)
{
    if(mismatch>1) return;
    if(pos==s.length()) { if(cur->end==true && mismatch)flag=true; return;}
    for(int i=0;i<3;i++)
    {
        if(cur->child[i]!=NULL) query(cur->child[i],pos+1,mismatch+!(s[pos]-'a'==i));
    }
}

void solve()
{
    Trie t;

}

int32_t main()
{
    PIKACHU;
    //int _; cin>>_; while(_--)
    solve();
    return 0;
}