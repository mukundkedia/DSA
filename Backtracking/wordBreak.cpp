//https://practice.geeksforgeeks.org/problems/word-break1352/1
//KM

#include<bits/stdc++.h>
using namespace std;

bool solve(int i,int j,string str,vector<string> b,int n){
    if(j==n){
        if(i==n) return true;
        return false;
    }
    if(find(b.begin(),b.end(),str.substr(i,j-i+1))==b.end()){
        return solve(i,j+1,str,b,n);
    }
    else{
        if(solve(i,j+1,str,b,n)){
            return true;
        }
        return solve(j+1,j+1,str,b,n);
    }
}

int wordBreak(string A, vector<string> &B) {
    return solve(0,0,A,B,A.size());
}