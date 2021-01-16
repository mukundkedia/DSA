//https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1#
//https://leetcode.com/problems/combination-sum/
//KM

#include<bits/stdc++.h>
using namespace std;

void solve(int i,int sum,int target,vector<int>& combination,vector<vector<int>> &res,vector<int>& a,int n){
    if(sum==target){
        res.push_back(combination);
        return;
    }
    if(i==n || sum>target){
        return;
    }
    sum+=a[i];
    combination.push_back(a[i]);
    solve(i,sum,target,combination,res,a,n);
    sum-=a[i];
    combination.pop_back();
    solve(i+1,sum,target,combination,res,a,n);
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int>> res;
       
         sort( A.begin(), A.end() );
        A.erase( unique( A.begin(), A.end() ), A.end() );
         int n = A.size();
        vector<int> temp;
        solve(0,0,B,temp,res,A,n);
        return res;
}