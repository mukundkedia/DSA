//https://www.spoj.com/problems/DIEHARD/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int dp[1002][1002];


int solve(int h,int a,int step){
    if(h<=0 || a<=0){
        return 0;
    }
    if(dp[h][a]!=-1){
        return dp[h][a];
    }
    if(step){
         dp[h][a] = solve(h+3,a+2,0)+1;
    }
    else{
       dp[h][a] = max(solve(h-5,a-10,1),solve(h-20,a+1,1))+1; 
    }
    return dp[h][a];
}

int main()
{
	int h,a;
    cin>>h>>a;
    memset(dp,-1,sizeof(dp));
    cout<<solve(h+3,a+2,0);
}