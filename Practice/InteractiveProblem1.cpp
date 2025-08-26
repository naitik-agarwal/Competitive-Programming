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

    int lower=1;
    int upper=1000000;
    while(lower<upper){
        int middle=(upper+lower)/2;
        cout<<middle<<endl;
        cout.flush();
        string s;
        cin>>s;
        if(s=="<"){
            upper=middle-1;
        }
        else{
            lower=middle;
        }
    }
    cout<<"! "<<lower<<endl;
    cout.flush();
    return 0;
}