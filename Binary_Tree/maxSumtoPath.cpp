//youtube.com/watch?v=gm4Ye0fESpU
//TBW

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int N = 3e5;

vector<int> g[N];
int a[N],dp[N];

void dfs(int u,int par){
    int mx=0;
    dp[u]=a[u];
    for(int child:g[u]){
         if(child==par){
             continue;
         }
         dfs(child,u);
        mx = max(mx,dp[child]);
    }
    dp[u]+=mx;
}

int main(){
    int i,j,u,v,n;
    cin>>n;
    for(i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(i=1;i<n+1;i++){
        cin>>a[i];
    }
    dfs(1,0);

    cout<<dp[1]<<"\n";
}