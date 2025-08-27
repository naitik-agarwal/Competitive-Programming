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
        int x,k;
        cin>>x>>k;
        int ans=0;
        int n=x;
        if(x%k!=0){
            cout<<1<<endl;
            cout<<x<<endl;
            continue;
        }
        while(n>=1){
            if(n%k!=0 && (x-n)%k!=0){
                ans=n;
                break;
            }
            else{
                n--;
            }
        }
        cout<<2<<endl<<ans<<" "<<x-ans<<endl;
    }

    return 0;
}