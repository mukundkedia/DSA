//KM
//

//General Recurssion

#include <bits/stdc++.h>
using namespace std;

void solve(string s,int pos,int len,set<string> &res,string temp){
    if(pos==len){
        if(temp.back()!=' '){
        res.insert(temp);
        }
        return;
    }
    temp+=s[pos];
    solve(s,pos+1,len,res,temp);
    solve(s,pos+1,len,res,temp+" ");
}

int main() {
int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    int len = s.size();
    set<string> res;
    string temp="";
    solve(s,0,len,res,temp);
    for(auto a:res){
        cout<<"(";
        cout<<a<<")";
    }
    cout<<endl;
}
}

//Backtracking

#include <bits/stdc++.h>
using namespace std;

void solve(string s,int pos,int len,set<string> &res ){
    if(pos==len-1){
     res.insert(s);
        return;
    }
   
    solve(s,pos+1,len,res);
    s.insert(pos+1," ");
    solve(s,pos+2,len+1,res);
    s.erase(pos+1,1);
}

int main() {
int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    int len = s.size();
    set<string> res;
  
    solve(s,0,len,res);
    for(auto a:res){
        cout<<"(";
        cout<<a<<")";
    }
    cout<<endl;
}
}