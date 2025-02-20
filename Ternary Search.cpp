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


int ternary_search(int n, int k) 
{
    int low = 1, high = n;

    while (high - low > 2) 
    {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        if (value(mid1) < value(mid2)) //for unimodular minima
        {
            high = mid2;
        } 
        else 
        {
            low = mid1;
        }
    }
    
    // Find the minimum value of x in the range [low, high]
    int result = INT_MAX;
    for (int i = low; i <= high; i++) {
        result = min(result, value(i));
    }

    return result;
}

void solve()
{
    int n,k; cin>>n>>k;
    cout<<ternary_search(n,k)<<endl;
}

int32_t main()
{
    PIKACHU;
    int _; cin>>_; while(_--)
    solve();
    return 0;
}
