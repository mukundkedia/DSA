//KM
//https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1#

#include <bits/stdc++.h>
using namespace std;

bool isKPartition(int arr[],int i,int n,int sum,int target,bool vis[]){
    if(sum==target){
        return true;
    }
    if(i==n){
        return false;
    }
    if(vis[i]){
        return isKPartition(arr,i+1,n,sum,target,vis);
    }
    if(isKPartition(arr,i+1,n,sum,target,vis)){
        return true;
    }
    sum+=arr[i];
    if(isKPartition(arr,i+1,n,sum,target,vis)){
        vis[i]=true;
        return true;
    }
    return false;
}

bool isKPartitionPossible(int A[], int N, int K)
{
     bool res;
     bool vis[N];
     sort(A,A+N);
     memset(vis,false,sizeof(vis));
     int sum=0;
     for(int i=0;i<N;i++){
         sum+=A[i];
     }
     if(K>N){
         return false;
     }
     if(sum%K){
         return false;
     }
     if(A[N-1]>sum/K){
         return false;
     }
     int target = sum/K;
     for(int i=0;i<K-1;i++){
         if(!isKPartition(A,0,N,0,target,vis)){
             return false;
         }
     }
     return true;
}