//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#
//rec+dp+backtrack

#include <bits/stdc++.h>
using namespace std;


 bool isPartition(int arr[],int n,int sum, bool vis[],int cindex){
        if(sum==0){
            return true;
        }
        for(int i=cindex;i>=0;i--){
            if(vis[cindex]){
                continue;
            }
            int temp = sum-arr[i];
            if(temp>=0){
                vis[i]=1;
                sum-=arr[i];
                bool nxt = isPartition(arr,n,sum,vis,i-1);
                sum+=arr[i];
                vis[i]=0;
                if(nxt){
                    return true;
                }
            }
            
        }
        return false;
    }

    int equalPartition(int N, int arr[])
    {
    int sum=0;
    bool vis[N];
    for(int i=0;i<N;i++){
        vis[i]=0;
        sum+=arr[i];
    }
    if(sum%2==1){
        return 0;
    }
    int cindex = N-1;
    return isPartition(arr,N,sum/2,vis,cindex);
    }
