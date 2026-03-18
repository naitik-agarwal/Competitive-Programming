#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast,unroll-loops")

#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using namespace __gnu_pbds;

vector<string> generateStrings(int maxLength) {
    vector<string> result;
    string current = "a";

    auto nextString = [&](string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == 'z') {
            s[i] = 'a';
            i--;
        }
        if (i < 0) {
            // all were 'z', need to extend length
            s = string(s.size() + 1, 'a');
        } else {
            s[i]++;
        }
        return s;
    };

    while ((int)current.size() <= maxLength) {
        result.push_back(current);
        current = nextString(current);
    }
    return result;
}
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        auto strings=generateStrings(3);
        for(int i=0;i<strings.size();i++){
            if(s.find(strings[i])==string::npos){
                cout<<strings[i]<<endl;
                break;
            }
            else{
                continue;
            }
        }
    }

    return 0;
}