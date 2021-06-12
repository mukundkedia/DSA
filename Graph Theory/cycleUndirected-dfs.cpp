#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];

void addEdge(int u,int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

bool checkCycle(int node,int parent,vector<int> &vis){
    vis[node]=1;
    for(auto it:adj[node]){
      if(!vis[it]){
        if(checkCycle(it,node,vis)){
          return true;
        }
      }
      else if(vis[it] and it!=parent){
        return true;
      }
    }
    return false;
}

int main(){
    addEdge(1,3);
    addEdge(3,5);
    addEdge(2,4);
    addEdge(2,5);
    addEdge(4,6);
  vector<int> vis(100,0);
  if(checkCycle(1,-1,vis)){
    cout<<"true";
  }
  else{
    cout<<"false";
  }
}