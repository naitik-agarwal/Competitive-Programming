#include<bits/stdc++.h>
using namespace std;

int sumof(int n,int ans){
    if(n==1){
        return 1;
    }
    sumof(n-1,ans);
    ans+=sumof(n-1,ans);
    return ans;
}

int main(){
    int n;
    cin>>n;
    int ans=0;
    ans=sumof(n,ans);
    cout<<ans<<endl;
    return 0;
}