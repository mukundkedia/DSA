#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];

void addEdge(int u,int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void dfs(int src,vector<int> &dist){
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
      int node = q.front();
      q.pop();
      for(auto it:adj[node]){
        if(dist[it]>dist[node]+1){
          dist[it]=dist[node]+1;
          q.push(it);
        }
        
      }
    }
    for(int i=0;i<9;i++){
      cout<<dist[i]<<" ";
    }
}



int main(){

    addEdge(0,1);
    addEdge(2,1);
    addEdge(2,6);
    addEdge(1,3);
    addEdge(0,3);
    addEdge(3,4);
    addEdge(5,4);
    addEdge(5,6);
    addEdge(6,7);
    addEdge(7,8);
    addEdge(6,8);
    vector<int> dist(100,INT_MAX);

   dfs(0,dist);

   
}