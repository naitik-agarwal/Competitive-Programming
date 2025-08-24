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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> hash(101,0);
        for(int i=0;i<n;i++){
            hash[a[i]]++;
        }
        int checker=0;
        for(int i=0;i<n;i++){
            if(hash[a[i]]>1){
                checker=1;
                break;
            }
        }
        if(checker==1){
            cout<<"YES"<<endl;
            continue;
        }
        else{
            cout<<"NO"<<endl;
            continue;
        }
    }

    return 0;
}