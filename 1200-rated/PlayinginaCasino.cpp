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
        int n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n);
        for(int i=0;i<n;i++){
            grid[i].resize(m);
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        else{
            int ans=0;
            vector<vector<int>> grid2(m);
            for(int i=0;i<m;i++){
                grid2[i].resize(n);
                for(int j=0;j<n;j++){
                    grid2[i][j]=grid[j][i];
                }
                sort(rall(grid2[i]));
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    ans+=((n-j-1)*grid2[i][j]);
                    ans-=(j*(grid2[i][j]));
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}