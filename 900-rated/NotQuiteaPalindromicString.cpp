#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast,unroll-loops")

#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int noofzero=count(all(s),'0');
        int noofone=count(all(s),'1');
        int minn=max(noofzero/2,noofone/2);
        int mx=minn;
        int mn=n/2-minn;
        if(k>=mn && k<=mx){
            cout<<"YES"<<endl;
            continue;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}