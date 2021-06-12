#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];

void addEdge(int u,int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void dfs(int node,vector<int>& vis){
  vis[node]=1;
  cout<<node<<" ";
  for(auto it:adj[node]){
    if(!vis[it]){
      dfs(it,vis);
    }
  }
}

int main(){
    addEdge(1,2);
    addEdge(1,3);
    addEdge(3,5);
    addEdge(2,4);
    addEdge(2,5);
    addEdge(4,6);
    addEdge(4,5);
    addEdge(5,6);
    vector<int> vis(100,0);
    dfs(1,vis);
}