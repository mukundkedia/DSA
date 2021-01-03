//KM
//https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0

#include <bits/stdc++.h>
using namespace std;

void solve(string s,int i,int len,set<string> &res){
    if(i==len-1){
        res.insert(s);
    }
    for(int j=i;j<len;j++){
        swap(s[i],s[j]);
        solve(s,i+1,len,res);
        swap(s[i],s[j]);
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    set<string> res;
	    int len = s.size();
	    
	    solve(s,0,len,res);
	    for(auto a:res){
	        cout<<a<<" ";
	    }
	    cout<<"\n";
	}
}