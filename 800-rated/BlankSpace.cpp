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
        if(count(all(a),0)==0){
            cout<<0<<endl;
            continue;
        }
        vector<int> num;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                continue;
            }
            else{
                int cntr=0;
                while(i<n && a[i]==0){
                    cntr++;
                    i++;
                }
                i--;
                num.push_back(cntr);
            }
        }
        cout<<*max_element(all(num))<<endl;
    }

    return 0;
}