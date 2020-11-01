#include<bits/stdc++.h>
using namespace std;
vector<int> g[500]; 
vector<int> vis(500,0);

void addEdge(int u,int v,bool para){
g[u].push_back(v);
if(para==true){
g[v].push_back(u);
}
}

void dfs(int val){
    vis[val]=1;
    for(auto it:g[val]){
        if(!vis[it]){
        dfs(it);
        }
    }
}

int main(){
    int ans=0;
    addEdge(1,2,true);
    addEdge(2,3,true);
    addEdge(3,4,true);
    addEdge(9,10,true);
    addEdge(9,11,true);
    addEdge(5,7,true);
    addEdge(5,6,true);
    addEdge(6,8,true);
    for(int i=1;i<=11;i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<"\n";
}