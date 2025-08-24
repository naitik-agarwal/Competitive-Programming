#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")

#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
int maxminno(int num){
    int maxx=0;
    int minn=10;
    while(num>0){
        int tem=num%10;
        maxx=max(maxx,tem);
        minn=min(minn,tem);
        num/=10;
    }
    return (maxx-minn);
}
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        int ans=l;
        int luck=maxminno(ans);
        for(int i=l;i<=r;i++){
            int no=maxminno(i);
            if(no>luck){
                ans=i;
                luck=no;
            }
            if(no==9){
                break;
            }
        } 
        cout<<ans<<endl;
    }

    return 0;
}