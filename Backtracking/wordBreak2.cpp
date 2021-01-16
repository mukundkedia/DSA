//https://practice.geeksforgeeks.org/problems/word-break-part-2/0#
//lb

#include <bits/stdc++.h>
using namespace std;

void solve(int i,int j,int n,vector<string> &vec,string &s,vector<string> &cur,set<vector<string>>& res){
    if(j==n){
        if(i==n){
            res.insert(cur);
            return;
        }
        return;
    }
    if(find(vec.begin(),vec.end(),s.substr(i,j-i+1))!=vec.end()){
        cur.push_back(s.substr(i,j-i+1));
        int temp=i;
        i=j+1;
        solve(i,j+1,n,vec,s,cur,res);
        i=temp;
        cur.pop_back();
        solve(i,j+1,n,vec,s,cur,res);
    }
    else{
        solve(i,j+1,n,vec,s,cur,res);
    }
}

int main() {
	int t;
	cin>>t;

	while(t--){
	    int n;
	    cin>>n;
	    	set<vector<string>> res;
	    vector<string> vec(n);
	    for(int i=0;i<n;i++){
	        cin>>vec[i];
	    }
	    string s;
	    cin>>s;
	    int len=s.size();
	    vector<string> temp;
	    solve(0,0,len,vec,s,temp,res);
	    for(auto it:res){
	        cout<<"(";
	        for(int k=0;k<it.size();k++){
	            if(k==it.size()-1){
	                cout<<it[k];
	            }
	            else{
	            cout<<it[k]<<" ";
	            }
	        }
	        cout<<")";
	    }
	    cout<<"\n";
	}
}