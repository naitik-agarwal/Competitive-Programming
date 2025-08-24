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
        int n;
        cin>>n;
        vector<int> g(n);
        for(int i=0;i<n;i++){
            cin>>g[i];
        }
        sort(all(g));
        int ans=0;
        if(n%2==0){
            for(int i=0;i<n;i++){
                if(i%2==1){
                    ans+=g[i];
                }
            }
            cout<<ans<<endl;
            continue;
        }
        else{
            int maxx=INT_MAX;
            for(int i=n-1;i>0;i--){
                if(i%2==0){
                    ans+=g[i];
                    int num=g[i-1];
                    g[i]-=num;
                    g[i-1]-=num;
                }
                else{
                    maxx=min(maxx,g[i]);
                }
            }
            ans+=g[0];
            cout<<ans<<endl;
        }
    }

    return 0;
}