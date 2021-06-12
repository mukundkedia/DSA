#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];

void addEdge(int u,int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void bfs(int node,vector<int> &vis){
  queue<int> q;
  q.push(node);
  vis[node]=1;
  while(!q.empty()){
    int topNode = q.front();
    cout<<topNode<<" ";
    q.pop();
    for(auto it:adj[topNode]){
      if(!vis[it]){
        vis[it]=1;
      q.push(it);
      } 
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
    bfs(1,vis);
}