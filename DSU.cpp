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

struct DSU
{
    vector<int> rank,par;
    int n;
    DSU(int _n)
    {
        n= _n;
        par.assign(n+1,0);
        rank.assign(n+1,0);
        for(int i=0;i<=n;i++) par[i]=i,rank[i]=1;
    }
    int find(int x) 
    {
        if (par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x, int y)
    {
        int rootx=find(x);
        int rooty=find(y);
        if(rootx==rooty) return;
        if(rank[rootx]<rank[rooty]) swap(rootx,rooty);
        rank[rootx]+=rank[rooty];
        par[rooty]=rootx;
    }
};

void solve()
{
    DSU dsu = DSU(n);
}

int32_t main()
{
    PIKACHU;
    int _; cin>>_; while(_--)
    solve();
    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:

vector<vector<int>>mat; 
int n;
vector<vector<int>>vis;

struct DSU
{
    int n; 
    vector<int>par,rank;
    DSU(int _n=0)
    {
        n=_n;
        par.assign(n,0); 
        rank.assign(n,0);
        for(int i=0;i<n;i++) par[i]=i, rank[i]=1;
    }
    int find(int x)
    {
        if(x==par[x]) return x;
        else return par[x]=find(par[x]);
    }
    void unite(int x, int y) 
    {
        int px=find(x), py=find(y);
        if(px==py) return;
        if(rank[px]<rank[py]) swap(px,py);
        par[py]=px;
        rank[px]+=rank[py];
    }
};

DSU dsu;   

void dfs(int i, int j)
{
    vis[i][j]=true;
    int dx[4]={-1,+1,0,0};
    int dy[4]={0,0,+1,-1};
    for(int k=0;k<4;k++)
    {
        int ni=i+dx[k],nj=j+dy[k];
        if(ni<0 || nj<0 || ni>=n || nj>=n) continue;
        if(vis[ni][nj] || mat[ni][nj]==0) continue;
        dsu.unite(i*n+j,ni*n+nj);
        dfs(ni,nj);
    }
}

int largestIsland(vector<vector<int>>& grid) 
{
    mat=grid;
    n=grid.size();
    dsu = DSU(n*n);
    vis.assign(n,vector<int>(n,0));

    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) 
            if(!vis[i][j] && grid[i][j]==1) 
                dfs(i,j);

    int ans=0;

    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==1) continue;

            set<int> s;
            if(i-1>=0 && mat[i-1][j]==1) s.insert(dsu.find((i-1)*n+j));
            if(j-1>=0 && mat[i][j-1]==1) s.insert(dsu.find(i*n+j-1));
            if(i+1<n && mat[i+1][j]==1) s.insert(dsu.find((i+1)*n+j));
            if(j+1<n && mat[i][j+1]==1) s.insert(dsu.find(i*n+j+1));

            int size=1;
            for(auto p: s) size += dsu.rank[p];
            ans = max(ans,size);
        }
    }

    return ans==0 ? n*n : ans;
}
};
