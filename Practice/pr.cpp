#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

int main(){
    vector<int> a={20 ,20 ,80, 70, 70 ,70, 420 ,5 ,1 ,5 ,1 ,60 ,90};
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}