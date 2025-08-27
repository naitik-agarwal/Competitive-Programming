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
        int k,x;
        cin>>k>>x;
        if(x>=k*k){
            cout<<2*k-1<<endl;
            continue;
        }
        else{
            int inisuml=(k+k*k)/2;
            if(x<=inisuml){
                int ans=0;
                int lower=1;
                int upper=k;
                while(lower<upper){
                    int mid=lower+(upper-lower)/2;
                    int sm=(mid+mid*mid)/2;
                    if(sm<x){
                        lower=mid+1;
                    }
                    else if(sm>=x){
                        upper=mid;
                    }
                }
                ans=lower;
                cout<<ans<<endl;
                continue;
            }
            else{
                int p=x-(k+k*k)/2;
                int ans=k;
                int lower=1;
                int upper=k-1;
                while(lower<upper){
                    int mid=lower+(upper-lower)/2;
                    int sm=(mid*k-(mid+mid*mid)/2);
                    if(sm<p){
                        lower=mid+1;
                    }
                    else if(sm>=p){
                        upper=mid;
                    }
                }
                ans+=lower;
                cout<<ans<<endl;
                continue;
            }
        }
    }

    return 0;
}