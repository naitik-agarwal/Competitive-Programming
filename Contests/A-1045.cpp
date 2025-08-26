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
        int n,a,b;
        cin>>n>>a>>b;
        if(n%2==0){
            if(b%2==1){
                cout<<"NO"<<endl;
                continue;
            }
            else{
                if(a<=b){
                    cout<<"YES"<<endl;
                    continue;
                }
                else{
                    if(a%2==1){
                        cout<<"NO"<<endl;
                        continue;
                    }
                    else{
                        cout<<"YES"<<endl;
                        continue;
                    }
                }
            }
        }
        else{
            if(b%2==0){
                cout<<"NO"<<endl;
                continue;
            }
            else{
                if(a<=b){
                    cout<<"YES"<<endl;
                    continue;
                }
                else{
                    if(a%2==0){
                        cout<<"NO"<<endl;
                        continue;
                    }
                    else{
                        cout<<"YES"<<endl;
                        continue;
                    }
                }
            }
        }
    }

    return 0;
}