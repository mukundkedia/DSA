//https://leetcode.com/problems/remove-invalid-parentheses/
// lb

#include<bits/stdc++.h>?
using namespace std;

class Solution {
public:
    set<string> vs;
    void solve(string s,int mra,set<string>& ans){
        if(mra==0){
            if(getMin(s)==0){
                ans.insert(s);
               }
            return;
        }
        
        for(int i=0;i<s.size();i++){
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            if(vs.find(left+right)!=vs.end()){
                continue;
            }
            vs.insert(left+right);
            solve(left+right,mra-1,ans);
        }
    }
    
    int getMin(string s){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                if(st.size()==0){
                    st.push(s[i]);
                }
                else if(st.top()==s[i]){
                    st.push(s[i]);
                }
                else{
                    st.pop();
                }
            }
        }
        return st.size();
    }
    
   
    
    vector<string> removeInvalidParentheses(string s) {
        int minRemoval = getMin(s);
        set<string> res;
        solve(s,minRemoval,res);
        vector<string> ans;
        for(auto it:res){
            ans.push_back(it);
        }
        return ans;
    }
};