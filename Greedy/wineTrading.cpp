//https://www.spoj.com/problems/GERGOVIA/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int res=0;
    int buy=0,sell=0;
    while(1){
        while(vec[buy]<=0 and buy<n){
            buy++;
        }
        while(vec[sell]>=0 and sell<n){
            sell++;
        }
        if(buy==n || sell==n){
            break;
        }
        int trans = min(vec[buy],-vec[sell]);
        res+=trans*abs(sell-buy);
        vec[buy]-=trans;
        vec[sell]+=trans;
    }
    cout<<res;
    }
