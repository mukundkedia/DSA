//KM
//https://practice.geeksforgeeks.org/problems/subsets/0

#include <bits/stdc++.h>
using namespace std;

void subsets(int arr[],int i,int n,set<vector<int>> &res, vector<int> &curr){
    if(i==n){
        res.insert(curr);
        return;
    }
    subsets(arr,i+1,n,res,curr);
    curr.push_back(arr[i]);
    subsets(arr,i+1,n,res,curr);
    curr.pop_back();
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        set<vector<int>> res;
        vector<int> currset;
        subsets(arr,0,n,res,currset);
        for(auto it:res){
            cout<<"(";
            for(int i=0;i<it.size();i++){
                if(i==it.size()-1){
                    cout<<it[i];
                }
                else{
                    cout<<it[i]<<" ";
                }
            }
            cout<<")";
        }
        cout<<endl;
    }
}