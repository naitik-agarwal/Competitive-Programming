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
        int max_depth=0;
        map<int,vector<int>> layers;
        for(int i=1;i<=n;i++){
            cout<<"?"<<" "<<i<<" "<<n<<" ";
            for(int j=1;j<=n;j++){
                cout<<j<<" ";
            }
            cout<<endl;
            int x;
            cin>>x;
            if(x==-1){return 0;}
            layers[x].push_back(i);
            if(x>max_depth){
                max_depth=x;
            }
        }
        vector<int> path;
        path.push_back(layers[max_depth][0]);
        for(int d=max_depth-1;d>=1;d--){
            for(int candidate:layers[d]){
                cout<<"? "<<path.back()<<" 2 "<<candidate<<" "<<path.back()<<endl;
                int res;
                cin>>res;
                if(res==2){
                    path.push_back(candidate);
                    break;
                }
            }
        }
        cout<<"! "<<path.size()<<" ";
        for(int node:path){
            cout<<node<<" ";
        }
        cout<<endl;
    }

    return 0;
}
