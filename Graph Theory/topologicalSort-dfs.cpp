#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];

void addEdge(int u,int v){
  adj[u].push_back(v);
}

void dfs(int node,vector<int>& vis,stack<int>& res){
  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it]){
      dfs(it,vis,res);
    }
  }
  res.push(node);
}

int main(){
  addEdge(5,0);
    addEdge(4,0);
    addEdge(4,1);
    addEdge(3,1);
    addEdge(2,3);
    addEdge(5,2);
    addEdge(5,0);
    stack<int> res;
    vector<int> vis(100,0);
    for(int i=0;i<6;i++){
      if(!vis[i]){
      dfs(i,vis,res);
      }
    }
    while(!res.empty()){
      cout<<res.top()<<" ";
      res.pop();
    }
}