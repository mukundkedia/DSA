#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isPalindrome(string str){
    string t = str;
    reverse(t.begin(),t.end());
    if(str==t){
        return true;
    }
    return false;
}

void solve(string a,string b){
    
    if(a.size()==0){
        cout<<b<<"\n";
        return;
    }
    
    for(int i=0;i<a.size();i++){
        string prefix = a.substr(0,i+1);
        string ros = a.substr(i+1);
        if(isPalindrome(prefix)){
            solve(ros,b+"("+prefix+") ");
        }
    }
}

int main()
{
	string s;
    cin>>s;
  	solve(s,"");
}