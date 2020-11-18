//https://practice.geeksforgeeks.org/problems/generate-binary-string/

#include <bits/stdc++.h>
using namespace std;

void solve(string s,int index){
    if(s.size()==index){
        cout<<s<<"\n";
        return;
    }
    if(s[index]=='?'){
        s[index]='0';
        solve(s,index+1);
        s[index]='1';
        solve(s,index+1);
    }
    else{
        solve(s,index+1);
    }
}

int main() {
    int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    solve(s,0);
	}
}