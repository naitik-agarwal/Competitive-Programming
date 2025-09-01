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
        int ans=0;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> b=a;
        if(n%2==1){
            if(a[n-1]>a[n-2]){
                a[n-1]=a[n-2];
            }
        }
        for(int i=0;i<n;i++){
            if(i==0){
                if(a[i]>a[i+1]){
                    a[i]=a[i+1];
                    continue;
                }
                else{
                    continue;
                }
            }
            if(i%2==0 && i<n-1){
                if(a[i]>a[i+1] || a[i]>a[i-1]){
                    a[i]=min(a[i+1],a[i-1]);
                }
            }
            else{
                continue;
            }
        }
        for(int i=0;i<n;i++){
            if(b[i]>a[i]){
                ans+=(b[i]-a[i]);
            }
        }
        for(int i=0;i<n-1;i++){
            if(i%2==1){
                if(a[i-1]+a[i+1]>a[i]){
                    int diff=a[i+1]+a[i-1]-a[i];
                    if(diff<=a[i+1]){
                        a[i+1]-=diff;
                    }
                    else{
                        diff-=a[i+1];
                        a[i+1]=0;
                        a[i-1]-=diff;
                    }
                    ans+=diff;
                }
                else{
                    continue;
                }
            }
            else{
                continue;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}