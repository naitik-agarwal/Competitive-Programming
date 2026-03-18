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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==1){
            cout<<a[0]+k<<endl;
            continue;
        }
        if(k%2==1){
            for(int i=0;i<n;i++){
                if(a[i]%2==1){
                    a[i]+=k;
                }
                else{
                    continue;
                }
            }
            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        else{
            if(k%6!=0){
                for(int i=0;i<n;i++){
                    if(a[i]%3==0){
                        continue;
                    }
                    else{
                        if(k%3==1){
                            if(a[i]%3==1){
                                a[i]+=2*k;
                            }
                            else{
                                a[i]+=k;
                            }
                        }
                        else{
                            if(a[i]%3==1){
                                a[i]+=k;
                            }
                            else{
                                a[i]+=2*k;
                            }
                        }
                    }
                }
                for(int i=0;i<n;i++){
                    cout<<a[i]<<" ";
                }
                cout<<endl;
            }
            else{
                for(int i=0;i<n;i++){
                    
                        if(k%5==1){
                            if(a[i]%5==1){
                                a[i]+=4*k;
                            }
                            else if(a[i]%5==2){
                                a[i]+=3*k;
                            }
                            else if(a[i]%5==3){
                                a[i]+=2*k;
                            }
                            else if(a[i]%5==4){
                                a[i]+=k;
                            }
                            else{
                                continue;
                            }
                        }
                        else if(k%5==2){
                            if(a[i]%5==1){
                                a[i]+=2*k;
                            }
                            else if(a[i]%5==2){
                                a[i]+=4*k;
                            }
                            else if(a[i]%5==3){
                                a[i]+=k;
                            }
                            else if(a[i]%5==4){
                                a[i]+=3*k;
                            }
                        }
                        else if(k%5==3){
                            if(a[i]%5==1){
                                a[i]+=3*k;
                            }
                            else if(a[i]%5==2){
                                a[i]+=k;
                            }
                            else if(a[i]%5==3){
                                a[i]+=4*k;
                            }
                            else if(a[i]%5==4){
                                a[i]+=2*k;
                            }
                        }
                        else if(k%5==4){
                            if(a[i]%5==1){
                                a[i]+=k;
                            }
                            else if(a[i]%5==2){
                                a[i]+=2*k;
                            }
                            else if(a[i]%5==3){
                                a[i]+=3*k;
                            }
                            else if(a[i]%5==4){
                                a[i]+=4*k;
                            }
                        }
                        else{
                            while(a[i]%29!=0){
                                a[i]+=k;
                            }
                        }
                    
                    
                }
                for(int i=0;i<n;i++){
                    cout<<a[i]<<" ";
                }
                cout<<endl;
                continue;
            }
        }
    }

    return 0;
}