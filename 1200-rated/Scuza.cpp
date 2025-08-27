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
        int n,q;
        cin>>n>>q;
        vector<int> k(q),a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<q;i++){
            cin>>k[i];
        }
        vector<int> prefixsum,maxele;
        maxele.push_back(a[0]);
        prefixsum.push_back(a[0]);
        int sum=a[0];
        for(int i=1;i<n;i++){
            sum+=a[i];
            prefixsum.push_back(sum);
            int crn=maxele.back();
            maxele.push_back(max(crn,a[i]));
        }
        for(int i=0;i<q;i++){
            auto it=upper_bound(all(maxele),k[i]);
            int dis=distance(maxele.begin(),it);
            if(it==maxele.end()){
                cout<<prefixsum.back()<<" ";
            }
            else{
                if(dis==0){
                    cout<<0<<" ";
                }
                else{
                    cout<<prefixsum[dis-1]<<" ";
                }
            }
        }
        cout<<endl;
    }

    return 0;
}