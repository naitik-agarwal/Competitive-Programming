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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int nochecker=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                continue;
            }
            else{
                int count=0;
                while(i<s.size() && s[i]=='1'){
                    count++;
                    i++;
                }
                if(count>=k){
                    nochecker=1;
                    break;
                }
                i--;
            }
        }
        if(nochecker==1){
            cout<<"NO"<<endl;
        }
        else{
            vector<int> ans(n);
            int num=1;
            for(int i=0;i<n;i++){
                if(s[i]=='1'){
                    ans[i]=num;
                    num++;
                }
                else{
                    continue;
                }
            }
            for(int i=0;i<n;i++){
                if(s[i]=='0'){
                    ans[i]=num;
                    num++;
                }
            }
            cout<<"YES"<<endl;
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}