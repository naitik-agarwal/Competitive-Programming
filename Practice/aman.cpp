#include<bits/stdc++.h>
using namespace std;


int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid(m);
    for(int i=0;i<m;i++){
        grid[i].resize(n);
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<m-1;i++){
        for(int j=0;j<n-1;j++){
            if(grid[i][j]==1){
                if(grid[i+1][j]==1){
                    ans++;
                }
                if(grid[i][j+1]==1){
                    ans++;
                }
                if(grid[i+1][j+1]==1){
                    ans++;
                }
                else{
                    continue;
                }
            }
            else{
                continue;
            }
        }
    }
    cout<<ans<<endl;
    return 0;

}