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
        if(n%2==0){
            cout<<(n/2)<<" "<<(n/2)<<endl;
            continue;
        }
        else{
            if(n%3==0){
                int num1=n/3;
                int num2=num1*2;
                cout<<num1<<" "<<num2<<endl;
                continue;
            }
            else if(n%7==0 && n!=7){
                int num1=n-7;
                int num2=n-(n/7);
                if(num1<=num2){
                    cout<<7<<" "<<num1<<endl;
                    continue;
                }
                else{
                    cout<<n/7<<" "<<num2<<endl;
                    continue;
                }
            }
            else{
                cout<<1<<" "<<n-1<<endl;
                continue;
            }
        }
    }

    return 0;
}