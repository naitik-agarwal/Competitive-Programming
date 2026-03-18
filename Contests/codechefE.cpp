#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s; // size is n+1
	    cin>>s;
	    int maxx=-1;
        if(s=="1"){
            cout<<1<<endl;
        }
	    for(int i=0;i<n+1;i++){
	        if(s[i]=='1'){
	            maxx=i;
	        }
	    }
	    if(maxx==0){
	        cout<<1<<" ";
	        for(int i=1;i<n;i++){
	            cout<<0<<" ";
	        }
	        cout<<endl;
	        continue;
	    }
	    if(maxx==-1){
	        for(int i=0;i<n;i++){
	            cout<<0<<" ";
	        }
	        cout<<endl;
	        continue;
	    }
	    else{
	        for(int i=0;i<n;i++){
	            cout<<i<<" ";
	        }
	        cout<<endl;
	    }
	}
}
