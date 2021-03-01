//KM
//https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1#

// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool solve(int index,vector<int> nums,int k,int currSum,int targetSum,vector<bool> vis){
        if(k==1){
            return true;
        }
        if(currSum==targetSum){
            return solve(0,nums,k-1,0,targetSum,vis);
        }
        for(int i=index;i<nums.size();i++){
            if(vis[i]==false and currSum+nums[i]<=targetSum){
                vis[i]=1;
                if(solve(i+1,nums,k,currSum+nums[i],targetSum,vis)){
                    return true;
                }
                else{
                    vis[i]=0;
                }
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        if(sum%k!=0 || n<k){
            return false;
        }
        vector<bool> vis(n,0);
        
        return solve(0,nums,k,0,sum/k,vis);
    }
};