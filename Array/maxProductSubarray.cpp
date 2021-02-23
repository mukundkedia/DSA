//https://leetcode.com/problems/maximum-product-subarray/

#include<bits/stdc++.h>?
using namespace std;

 int maxProduct(vector<int>& nums) {
        int len=nums.size();
        int res=nums[0];
        int maxx= nums[0];
        int minn = nums[0];
        for(int i=1;i<len;i++){
            int temp=maxx;
            maxx = max(max(maxx*nums[i],minn*nums[i]),nums[i]);
            minn = min(min(temp*nums[i],minn*nums[i]),nums[i]);
            if(res<maxx){
                res=maxx;
            }
        }
        return res;
    }

    long long maxProduct(int *nums, int n) {
        if(n==1){
            return nums[0];
        }
        long long ans=0;
        long long curr = 1;
        for(int i=0;i<n;i++){
            curr*=(long long)nums[i];
            ans=max(ans,curr);
            if(curr==0){
                curr=1;
            }
        }
        
        curr=1; 
        
        for(int i=n-1;i>=0;i--){
            curr*=(long long)nums[i];
            ans=max(ans,curr);
            if(curr==0){
                curr=1;
            }
        }
        return ans;
	}